/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:02:55 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/26 13:58:10 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	fd = open("open_close_open.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	close(fd);
	fd = open("open_close_open.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	close(fd);
	return (1);
}
