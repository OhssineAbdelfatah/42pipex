#include"header.h"

char	*ft_strndup(const char *s1, size_t size)
{
	int		i;
	char	*new;
	// char	*temp;

	i = ft_strlen(s1);
	if(size > (size_t)i )
		return NULL;
	new = (char *)malloc(i * sizeof(char) + 1);
	if (!new)
		return (NULL);
	// temp = new;
	i = 0;
	while (*s1 && (size_t)i < size){
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int sub_path(char *path, int i)
{
	int j = i;
	while(path[++j]){
		if(path[j] == ':')
			return j;
	}
	return i;
}

char **split_path(char *path)
{	
	int i = -1;
	int j ;
	int pt = 0 ;
	int count_sub_path = 0 ;
	int _count_sub_path = 0 ;
	char **path_2d ;
	while(path[++i])
	{
		if(path[i] == ':')
			count_sub_path++;
	}
	count_sub_path++;
	path_2d = malloc(count_sub_path * sizeof(char *));
	i = 0;
	while(path[i])
	{
		j = sub_path(path,i);
		if (j > i){
            _count_sub_path++;
			path_2d[pt++] = ft_strndup(path + i, j - i);
			i = j+1;
		}else if(_count_sub_path == count_sub_path - 1){
            path_2d[pt++] = ft_strndup(path + j, ft_strlen(path + j));
            break;
        }
	}
	path_2d[pt] = NULL;
	return path_2d;
}