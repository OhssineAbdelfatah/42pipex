#ifndef HEADER_H
#define HEADER_H

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
/* 
open, x
close, x
read, x
write, x
malloc, x
free, x
perror, 
execve,
exit, 
fork, x
pipe, 
strerror,
access,
dup,
dup2,
unlink,
wait, x 
waitpid, x
 */

typedef struct s_split
{
	int	i;
	int	j;
	int	k;
}	t_split;

typedef struct s_file {
    char *name;
    int fd;
    int exist;
} t_file;

typedef struct s_cmd {
    char **name; // why double pointers : [ls][-l][-a] cmd and args
    char *abs_path;
} t_cmd;


typedef struct s_pipex
{
    int nbr_cmd;
    t_file infile;
    t_file outfile;
    t_cmd *cmd;
    char *env_path;
    char **env_path_2d;
} t_pipex ;


char **split_path(char *path);
size_t ft_strlen(const char *str);
char	*ft_strndup(const char *s1, size_t size);
char	**ft_split(char const *s, char c);
void exec_cmds(t_pipex *dt, char *env[]);
#endif