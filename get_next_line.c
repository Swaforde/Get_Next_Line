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

char *get_next_line(int fd)
{
	static char *line_got;
	char		*gBuffer;
	char		*tmp1;
	char		*tmp2;
	char		*res_read;
	int			size;

	gBuffer = NULL;
	tmp1 = NULL;
	tmp2 = NULL;
	size = 20;
	res_read = malloc (sizeof(char) * (size) + 1);
	if (!res_read)
		return (NULL);
	res_read[size + 1] = '\0';
	while (ft_strchr(res_read, '\n') == NULL)
	{
		read(fd, res_read, size);
		if (gBuffer == NULL)
		{
			gBuffer = ft_strdup(res_read);
		}
		if (tmp1 != NULL)
			free (tmp1);
		tmp1 = ft_strdup(gBuffer);
		free (gBuffer);
		gBuffer = ft_strdup(res_read);
		gBuffer = ft_strjoin(tmp1, gBuffer);
	}
	return (gBuffer);
}