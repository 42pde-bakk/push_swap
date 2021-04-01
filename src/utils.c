//
// Created by peerdb on 30-03-21.
//

#include "utils.h"
#include "libft.h"
#include "limits.h"

void	fatal_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

unsigned int	amount_digits(int n)
{
	unsigned int	digits;

	digits = 1;
	if (n < 0)
		digits = 1;
	while (n <= -10 || n >= 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

int	atoi_exit_on_error(const char *str)
{
	int			sign;
	int			i;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (iswhitespace(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++str;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (10 * result) + (str[i] - '0');
		if (result < INT_MIN || result > INT_MAX)
			fatal_error("Error");
		++i;
	}
	return (sign * (int)result);
}

void	clearscreen(void)
{
	write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
}
