#include"header.h"


void exit_error(const char *msg)
{
	return (printf("%s\n",msg),exit(0));
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;
	char	*temp;

	i = ft_strlen(s1);
	new = (char *)malloc(i * sizeof(char) + 1);
	if (!new)
		return (NULL);
	temp = new;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (new);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while (((unsigned char)*s1 || (unsigned char)*s2) && n--)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (*s1)
	{
		*res++ = *s1++;
	}
	while (*s2)
	{
		*res++ = *s2++;
	}
	*(res) = '\0';
	return (res - len);
}
bool check_cmd(t_pipex *data)
{
	char *cmd_abs_path;
	int counter = 0;

	data->env_path = getenv("PATH");
	data->env_path_2d = split_path(data->env_path);
	int i = -1;
	int j = -1 ;
	while(data->env_path_2d[++j])
		data->env_path_2d[j] = ft_strjoin(data->env_path_2d[j], "/");
	while(++i < data->nbr_cmd)
	{
		j = -1;

		while(data->env_path_2d[++j])
		{
			cmd_abs_path = ft_strjoin(data->env_path_2d[j], data->cmd[i].name[0]);
			if(access(cmd_abs_path, X_OK) == 0)
			{
				data->cmd[i].abs_path = ft_strdup(cmd_abs_path);
				counter++;
				break;
			}
		}
	}
	if(counter == data->nbr_cmd)
		return true;
	return (false);
}

void check_files(t_pipex *data)
{
    if(access(data->infile.name, R_OK) != 0)
		exit_error("Permission denied or infile does not exist");
	data->outfile.fd = open(data->outfile.name,O_RDWR | O_CREAT | O_TRUNC, 0666);
	if(data->outfile.fd == -1)
		exit_error("Outfile cannot be created or opened");
}
void    init_data(t_pipex *data ,char **av)
{
	int i = -1;
	data->cmd = malloc(sizeof(t_cmd) * data->nbr_cmd);
	while(++i < data->nbr_cmd)
	    data->cmd[i].name = ft_split( av[i+2], ' ');  // command not splitted
    data->infile.name = av[1];
    data->outfile.name = av[data->nbr_cmd + 2];

    return ;
}
int main(int ac, char **av, char *env[])
{
    t_pipex data;

    // five cmdline args ./pipex infile cmd1 cmd2 outfile
    if(ac < 5 )
        return (printf("%s infile cmd1 cmd2 outfile\n",av[0]),0);
    // 1) init data
	data.nbr_cmd = ac - 3;
	init_data(&data ,av);
    // 2) chck files and cmds
    check_files(&data);
	if(!check_cmd(&data))
		exit_error("command not found !");
	// 3) execute commands
	exec_cmds(&data, env);
}