/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testlibft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:11:01 by jbadia            #+#    #+#             */
/*   Updated: 2021/05/08 18:13:00 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    ft_teststrmapi(unsigned int i, char c)
{
    i = 1;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    else if (c >= 'A' && c <= 'Z')
        return (c + 32);
    else
        return (c);
}

int main (void)
{
    void    *str[10];
    int c = 83;
    char dest[20];
    char *src = "salut";
    char const *str_memchr = "FOO BAR BAZ ";
    int chr = 'B';
    char *str1_cmp = "dozen";
	char *str2_cmp = "zzzdouze";
    

    printf("FT memset: %p\n", ft_memset(str,c, 3));
    printf("C memset : %p\n\n", memset(str,c, 3));

    printf("FT memcpy: %p\n", ft_memcpy(dest, src, 4));
    printf("C memcpy : %p\n\n", memcpy(dest, src, 4));

    printf("FT memcpy: %p\n", ft_memccpy(dest, src, 'a', 4));
    printf("C memcpy: %p\n\n", memccpy(dest, src, 'a', 4));

    printf("FT memmove: %p\n", ft_memmove(dest, src, 2));
    printf("C  memmove: %p\n\n", memmove(dest, src, 2));

    printf("FT memchr: %p\n", ft_memchr(str_memchr, chr, 5));
    printf("C  memchr : %p\n\n", memchr(str_memchr, chr, 5));

    printf("FT memcmp: %d\n", ft_memcmp(str1_cmp, str2_cmp, 6));
	printf("C  memcmp: %d\n\n", memcmp(str1_cmp, str2_cmp, 6));

    printf("FT strdup: %s\n", ft_strdup(str_memchr));
    printf("C strdup : %s\n\n", strdup(str_memchr));
    free(ft_strdup(str_memchr));

    printf("SUBSTR: %s\n\n",ft_substr("salut ca va ", 6, 5));
    free(ft_substr("salut ca va ", 6, 5));

    printf("STRJOIN: %s\n\n", ft_strjoin(str_memchr, str_memchr));
    free (ft_strjoin(str_memchr, str_memchr));

    printf("%s\n\n", ft_strmapi("STRMAPI (doit etre en minuscule) : SALUT", ft_teststrmapi));



}