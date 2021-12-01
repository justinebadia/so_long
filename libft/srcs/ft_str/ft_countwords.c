/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:09:41 by jbadia            #+#    #+#             */
/*   Updated: 2021/05/10 14:03:37 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int		count;

	count = 0;
	if (*s == 0)
		return (0);
	if (*s != '\0' && *s != c)
		count++;
	while (*++s != '\0')
		if (*s != c && *(s - 1) == c)
			count++;
	s++;
	return (count);
}
