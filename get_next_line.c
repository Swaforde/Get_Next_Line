/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:35 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/19 14:26:51 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_size(const char *ptr)
{
	int	index;
	
	index = 0;
	while (ptr[index] != '\0' && ptr[index] != '\n')
		index ++;
	return (index);
}

char	*get_first_line(const char *ptr)
{
	char	*ptr_d;
	int	index;

	index = 0;
	ptr_d = malloc (sizeof(char) * index + 1);
	if (!ptr)
		return (NULL);
	while (index != get_line_size(ptr))
	{
		ptr_d[index] = ptr[index];
		index ++;
	}
	ptr_d[index] = '\0';
	return (ptr_d);
}

char *get_next_line(int fd)
{
	static char *line_got;
	static char		*gBuffer;
	static char		*tmp1;
	char		*res_read;
	int			size;

	tmp1 = NULL;
	size = 10;
	gBuffer = malloc(sizeof(char) * 1);
	if (!gBuffer)
		return (NULL);
	gBuffer[0] = '\0';
	res_read = malloc (sizeof(char) * (size) + 1);
	if (!res_read)
		return (NULL);
	res_read[size + 1] = '\0';
	while (ft_strchr(gBuffer, '\n') == NULL)
	{
		if (tmp1 != NULL)
			free (tmp1);
		tmp1 = ft_strdup(gBuffer);
		free(gBuffer);
		gBuffer = ft_strjoin(tmp1, res_read);
		read(fd, res_read, size);
	}
	line_got = get_first_line(gBuffer);
	return (line_got);
}