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
