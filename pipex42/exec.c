#include"header.h"

static void exec_cmd(int in,__unused int out, t_pipex *dt, char *env[], int i)
{
    pid_t pid;

    if ((pid = fork()) == 0) {
        dup2(in, 0);
        close(in);
        dup2(out, 1);
        close(out);        
        execve(dt->cmd[i].abs_path,dt->cmd[i].name, env);
    }
}

void exec_cmds(t_pipex *dt, char *env[])
{
    int i = -1, in, fd[2];
    in = open(dt->infile.name, O_RDONLY);
    while (++i < dt->nbr_cmd - 1) {
        pipe(fd);
        exec_cmd(in, fd[1], dt, env, i);
        close(fd[1]);
        in = fd[0];
    }
    if (in != 0)
        dup2(in, 0);
    int out = open(dt->outfile.name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(out, 1);
    close(out);
    execve(dt->cmd[i].abs_path,dt->cmd[i].name, env);

    // execlp(cmds[i], cmds[i], (char *)0);
}