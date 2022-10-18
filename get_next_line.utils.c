/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:11:48 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 16:16:25 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  index;

    index = 0;
    while (str[index] != 0)
            index++;
    return (index);
}

static char    *ft_strchr(const char *s, int c)
{
    int     index;

    index = 0;
    while (s[index] != ((char)c))
        {
        if (s[index] == '\0')
        {
            return (NULL);
        }
        index++;
    }
    return ((char *)s + index);
}

char    *ft_strdup(const char *s1)
{
    char    *dest;
    size_t  str_size;
    int             index;

    str_size = ft_strlen(s1);
    dest = (char *)malloc (sizeof (char) * str_size + 1);
    if (!dest)
        return (NULL);
    index = 0;
    while (s1[index] != '\0')
    {
        dest[index] = s1[index];
        index++;
    }
    dest[index] = '\0';
    return (dest);
}