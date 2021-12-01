#include "libft.h"
#include <ctype.h>

int main (void)
{
    const char *str_test = "SALUT";
    char *src_test;
    src_test = "Hello World";
	//char dest_test[12];
    char	*str_base;
	char	dest[100];
	char	dest2[100];
	char	*src;
	int		index;
    const char *str1 = "Hello";
	const char *str2 = "Helloo";
    char string[48] = "Poulet au curry";
	char string2[] = "au curry";
    const char *str_chr = "FOO BAR BAZ";
    int chr = 'B';

	str_base = "Hellola";
	src = " Worldeeedd";
	index = 0;
	while (index < 20)
	{
		dest[index] = str_base[index];
		dest2[index] = str_base[index];
		index++;
	}

    printf("FT_STRLEN: %zu\n", ft_strlen(str_test));
    printf("STRLEN : %lu\n\n", strlen(str_test));

    printf("FT isalpha: %d\n", ft_isalpha(83));
    printf("C  isaplha : %d\n\n", isalpha(83));

    printf("FT isdigit: %d\n", ft_isdigit(77));
    printf("C  isdigit: %d\n\n", isdigit(77));

    printf("FT alnum: %d\n", ft_isalnum('z'));
    printf("C  alnum: %d\n\n", isalnum('z'));

    printf("FT isascii: %d\n", ft_isascii(20098));
    printf("C  isascii: %d\n\n", isascii(20098));

    printf("FT isprint: %d\n", ft_isprint('A'));
    printf("C  isprint: %d\n\n", isprint('A'));

    printf("FT toupper : %d\n", ft_toupper('a'));
    printf("C toupper : %d\n\n", toupper('a'));

    printf("FT toupper: %d\n", ft_tolower('A'));
    printf("C  toupper: %d\n\n", tolower('A'));

    // strcpy(dest_test, src_test);
	// printf("strcpy    : %s\n", dest_test);
	// ft_strcpy(dest_test, src_test);
	// printf("ft_strcpy : %s\n\n", dest_test);

    // strncpy(dest_test, src_test, 10);
	// printf("strncpy    : %s\n", dest_test);
	// ft_strncpy(dest_test, src_test, 10);
	// printf("ft_strncpy : %s\n", dest_test);

    printf("c  strlcat: (%lu) $%s$\n", strlcat(dest, src, 12), dest);
	printf("ft strlcat: (%zu) $%s$\n\n", ft_strlcat(dest2, src, 12), dest2);

    printf("c  strcmp: %d\n", strcmp(str1, str2));
	printf("ft strcmp : %d\n\n", ft_strcmp(str1, str2));

    printf("c  strncmp: %d\n", strncmp(str1, str2, 6));
	printf("ft strncmp: %d\n\n", ft_strncmp(str1, str2, 6));

    printf("c strlcpy : (%lu) $%s$\n", strlcpy(dest, src, 5), dest);
	printf("ft strlcpy: (%zu) $%s$\n", ft_strlcpy(dest2, src, 5), dest2);

    // printf(" FT strstr: %s\n", ft_strstr(string, string2));
	// printf("C strstr: %s\n\n", strstr(string, string2));

    printf("FT strnstr: %s\n", ft_strnstr(string, string2,20));
	printf("C strnstr: %s\n\n", strnstr(string, string2, 20));

    printf("FT strchr : %p\n", ft_strchr(str_chr, chr));
    printf("C strchr: %p\n\n", strchr(str_chr, chr));

    printf("FT strrchr : %p\n", ft_strrchr(str_chr, chr));
	printf("C strrchr: %p\n\n", strrchr(str_chr, chr));

    printf("C ATOI : %d\n",atoi("-12"));
    printf("FT ATOI : %d\n\n",ft_atoi("-12"));

    printf("ITOA : %s\n", ft_itoa(-2147483648));
    printf("ITOA : %s\n", ft_itoa(0));
    printf("ITOA : %s\n\n", ft_itoa(2147483647));

    printf("STRTRIM = bbbjjj  : %s\n\n", ft_strtrim("aaabbbjjjaaa", "aaa"));
}