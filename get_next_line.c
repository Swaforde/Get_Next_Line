#include "get_next_line.h"
//#define BUFFER_SIZE 10

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
	buff[0] = '\0';
	read_bytes = 1;
	tmp = malloc (sizeof(char) * 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	while (read_bytes != 0 && !ft_strchr(buff, '\n'))
	{
		if (read_bytes == -1)
		{
			free (buff);
			free(tmp);
			return (NULL);
		}
		if (read_bytes == 0)
		{
			free(buff);
			free(tmp);
			return (buffer);
		}
		read_bytes = read(fd, buff, BUFFER_SIZE);
		buff[read_bytes] = '\0';
		if (tmp != NULL)
			free (tmp);
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
	{
		return (NULL);
	}
	s = 0;
	while (buffer[t] != '\0')
	{
		ptr[s] = buffer[t];
		s ++;
		t ++;
	}
	ptr[s] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer != NULL)
			free (buffer);
		return (NULL);
	}
	if (buffer == NULL)
	{
		buffer = malloc (sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = save_read(fd, buffer);
	if (buffer == NULL)
	{
		return (NULL);
	}
	tmp = ft_strdup(buffer);
	line = ft_get_first_line(buffer);
	free (buffer);
	buffer = ft_save(tmp);
	free (tmp);
	return (line);
}