/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:02:55 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/25 09:41:31 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	fd = open("text.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	return (1);
}
