#include "get_next_line.h"

char	*ft_calloc(size_t n, size_t size)
{
	char	*m;
	size_t	i;

	i = 0;
	if (size != 0)
	{
		if (((n * size) / size) != n)
			return (NULL);
	}
	if (size == 0)
		return (NULL);
	m = malloc(n * size);
	if (m == NULL)
		return (NULL);
	while (i < n * size)
	{
		m[i] = '\0';
		i++;
	}
	return (m);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s || !*s)
		return (NULL);
	size = ft_strlen(s) + 1;
	while (i < size)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	int		n;
	int		i;
	char	*str;

	n = 0;
	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[n] != '\0')
		n++;
	str = (char *)ft_calloc(sizeof(char), (n + 1));
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*result;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = ft_calloc(size, sizeof(char));
	if (!result)
		return (free_buffer(s2));
	while (s1 && s1[i] && i < (ft_strlen(s1)))
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && j < (ft_strlen(s2)))
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	return (result);
}
