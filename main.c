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

/*

 gnl(1000,  NULL);
 gnl(-1,  NULL); close(fd);
 gnl(fd,  NULL) 
*/

int	main(void)
{
	int	fd;
	fd = open("empty", O_RDONLY);
	
	printf ("%p\n", get_next_line(fd));
	close(fd);
	printf("%p\n", get_next_line(fd));
	return (1);
}
