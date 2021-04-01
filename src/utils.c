//
// Created by peerdb on 30-03-21.
//

#include "utils.h"
#include "libft.h"

void	fatal_error(const char* s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

unsigned int amount_digits(int n) {
	unsigned int	digits;

	digits = 0;
	if (n < 0)
		digits = 1;
	while (n <= -10 || n >= 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}
