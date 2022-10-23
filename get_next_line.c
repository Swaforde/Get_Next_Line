#include "get_next_line.h"
#define BUFFER_SIZE 11

char	*ft_get_first_line(char *buffer)
{
	char	*ptr;
	int		i;
	
	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	ptr = malloc (sizeof(char) * (i) + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		ptr[i] = buffer[i];
		i ++;
	}
	if (buffer[i] != '\n')
	{
		ptr[i] = '\n';
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*save_read(int fd, char *buffer)
{
	char	*res;
	int		byte_read;

	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	ft_bzero(res, BUFFER_SIZE + 1);
	read(fd, res, BUFFER_SIZE);
	if (ft_strchr(res, '\0') != NULL)
		printf ("trouver");

	byte_read = 1;
	while (byte_read > 0 && ft_strchr(res, '\n') == NULL)
	{
		if (byte_read == -1)
		{
			free (res);
			return (NULL);
		}
		byte_read = read(fd, res, BUFFER_SIZE);
		res[byte_read] = '\0';
		buffer = ft_strjoin(buffer, res);
	}
	free (res);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	char		*line;
	char		*test;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 ,0) < 0)
		return (NULL);
	test = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!test)
		return (NULL);
	ft_bzero(test, BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		buffer = malloc (sizeof(char) * 1);
		buffer[0] = '\0';
		if (!buffer)
		{
			free (test);
			return (NULL);
		}
	}
	buffer = save_read(fd, buffer);
	line = ft_get_first_line(buffer);
	if (read(fd, test, BUFFER_SIZE) == 0)
		free (buffer);
	free (test);
	return (line);
}