/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:35 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 16:16:22 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *line_got;
	char		*gBuffer;
	char		*tmp;
	char		res_read[10];
	int			index;

	line_got = NULL;
	index = 0;
	read(fd, res_read, 10);
	while (ft_strchr(res_read, '\n') == NULL)
	{
		if (gBuffer == NULL)
			gBuffer = ft_strdup(res_read);
		read(fd, res_read, 10);
	}
	return (line_got);
}