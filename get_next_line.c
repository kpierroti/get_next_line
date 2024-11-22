#include "get_next_line.h"

char	*free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
	return (NULL);
}

char	*read_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	char	*buf;
	int		byte_read;
	char	*tmp;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		if (byte_read == -1)
			return (free_buffer(buf));
		buf[byte_read] = '\0';
		tmp = ft_strjoin(buffer, buf);
		free(buffer);
		buffer = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*return_line(char **buffer)
{
	char	*line;
	char	*str;
	char	*tmp;

	line = read_line(*buffer);
	str = ft_strchr(*buffer, '\n');
	if (str)
	{
		tmp = ft_strdup(str + 1);
		free(*buffer);
		*buffer = tmp;
	}
	else
		*buffer = free_buffer(*buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*sbuffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, BUFFER_SIZE) < 0)
		return (NULL);
	//if (!sbuffer[fd])
	//	sbuffer[fd] = ft_calloc(1, 1);
	sbuffer[fd] = read_buffer(fd, sbuffer[fd]);
	if (!sbuffer[fd])
		return (NULL);
	line = return_line(&sbuffer[fd]);
	return (line);
}
