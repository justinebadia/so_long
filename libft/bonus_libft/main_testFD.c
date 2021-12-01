#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
	int fd;
	
	fd = open("test_libft", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		printf("failed");
	else
	{	
		ft_putchar_fd('A', fd);
		ft_putendl_fd("Salut", fd);
		ft_putnbr_fd(12, fd);
		ft_putstr_fd("Salut\n", fd);
	}
	return (0);
}
