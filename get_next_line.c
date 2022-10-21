/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:35 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/21 13:29:29 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char = ft_get_first_line(char *save)
{
	return ();
}

char	*ft_read_save(int fd, char *save)
{
	char	*read_res;
	int		byte_readed;

	read_res = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!read_res)
		return (NULL);
	byte_readed = 1;
	while (!ft_strchr(save, '\n'))
	{
		byte_readed = read(fd, read_res, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free (read_res);
			return (save);
		}
		read_res[byte_readed] = '\0';
		save = ft_strjoin(save, read_res);
	}
	free (read_res);
	return (save);
}

char *get_next_line(int fd)
{
	static char		*save;
	char			*line;
	
	save = ft_calloc (sizeof(char), 1);
	if (fd == 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	printf ("%s", save);
	return (line);
}