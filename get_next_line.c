#include "get_next_line.h"
//#define BUFFER_SIZE 11

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
	if (buffer[i] == '\n')
	{
		ptr[i] = '\n';
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*save_read(int fd, char *buffer)
{
	char	*buff;
	char	*tmp;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buff);
			return (buffer);
		}
		buff[read_bytes] = '\0';
		tmp = ft_strdup(buffer);
		free(buffer);
		buffer = ft_strjoin(tmp, buff);
	}
	free(buff);
	free(tmp);
	return (buffer);
}

char	*ft_save(char *buffer)
{
	char	*ptr;
	int		i;
	int		s;
	int		t;
	
	i = 0;
	s = 0;
	t = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
			return (NULL);
		i++;
	}
	i ++;
	t = i;
	while (buffer[i] != '\0')
	{
		i ++;
		s ++;
	}
	ptr = (char *)malloc (sizeof(char) * (s + 1));
	if (!ptr)
		return (NULL);
	s = 0;
	while (buffer[t] != '\0')
	{
		ptr[s] = buffer[t];
		s ++;
		t ++;
	}
	ptr[s] = '\0';
	free(buffer);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	char		*line;
	char		*test;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
	buffer = ft_save(buffer);
	free (test);
	return (line);
}