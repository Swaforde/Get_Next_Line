/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:35 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/20 16:55:33 by tbouvera         ###   ########.fr       */
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

char	*save_the_extra(char *gBuffer)
{
	char	*ptr;
	int		index;
	int		size;

	index = 0;
	size = 0;
	index = ft_strlen(gBuffer);
	while (gBuffer[index] != '\n')
	{
		index --;
		size ++;
	}
	ptr = malloc (sizeof(char) * size);
	if (!ptr)
		return (NULL);
	index ++;
	size = 0;
	while (gBuffer[index] != '\0')
		ptr[size++] = gBuffer[index++];
	return (ptr);
}

char *get_next_line(int fd)
{
	char *line_got;
	static char		*gBuffer;
	char		*tmp1;
	char		*res_read;
	int			size;
	int			read_nb;

	//printf ("---->%s<----", gBuffer);
	tmp1 = NULL;
	size = 22;
	if(fd < 0 || size <= 0)
		return (NULL);
	if (gBuffer == NULL)
	{
		gBuffer = malloc(sizeof(char) * 1);
		if (!gBuffer)
			return (NULL);
		gBuffer[0] = '\0';
	}
	res_read = malloc (sizeof(char) * (size) + 1);
	if (!res_read)
		return (NULL);
	read_nb = 1;
	while (ft_strchr(gBuffer, '\n') == NULL && read_nb != 0)
	{
		read_nb = read(fd, res_read, size);
		res_read[read_nb] = '\0';
		tmp1 = ft_strdup(gBuffer);
		gBuffer = ft_strjoin(tmp1, res_read);
		if (tmp1 != NULL)
			free (tmp1);
	}
	line_got = get_first_line(gBuffer);
	gBuffer = ft_strdup(save_the_extra(gBuffer));
	//free (tmp1);
	return (line_got);
}