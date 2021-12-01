/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:25 by jbadia            #+#    #+#             */
/*   Updated: 2021/05/09 14:55:47 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strncat(char *dest, const char *src, size_t n)
{
    unsigned int i;
    unsigned int size;

    i = 0;
    size = 0; 
    while (dest[i] != '\0')
    {
        i++;
    }
    while(*src != '\0' && (size < n))
    {
        dest[i] = *src;
        src++;
        i++;
        size++;
    }
    dest[i] = '\0';
    return (dest);
}