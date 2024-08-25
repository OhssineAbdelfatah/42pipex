#include"header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strndup("",0));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	while (*(s + start) && len--)
	{
		*(substr + i) = *(s + start++);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	if (*s == '\0')
		return (0);
	while (*(s + i) == c)
		i++;
	while (*(s + i))
	{
		if (*(s + i) == c && *(s + i + 1) != c)
			words++;
		i++;
	}
	if (*(s + i - 1) != c)
		words++;
	return (words);
}

static void	free_array(char **array, int k)
{
	while (k >= 0)
	{
		free(array[k]);
		k--;
	}
	free(array);
}

static int	alloc_words(char const *s, char c, char **array, int words)
{
	t_split	var;

	var.k = 0;
	var.i = 0;
	while (var.k < words)
	{
		var.j = 0;
		while (s[var.i] && s[var.i] == c)
			var.i++;
		while (s[var.i] && s[var.i] != c)
		{
			var.i++;
			var.j++;
		}
		array[var.k] = ft_substr(s, var.i - var.j, var.j);
		if (array[var.k] == NULL)
		{
			free_array(array, var.k);
			return (1);
		}
		var.k++;
	}
	array[var.k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (alloc_words(s, c, array, words))
		return (NULL);
	return (array);
}