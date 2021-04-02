//
// Created by peerdb on 02-04-21.
//

#include "stack.h"
#include "libft.h"
#include "ft_printf.h"

static void	printf_wrapper(const int fd, const t_stacknode *node,
							  int max_digits, const char *end)
{
	if (node)
		ft_dprintf(fd, "%*d%s", max_digits, node->data, end);
	else
		ft_dprintf(fd, "%*c%s", max_digits, ' ', end);
}

void	print_stacks(const t_collection *stacks)
{
	int			fd;
	int			field_width;
	t_stacknode	*tmp_a;
	t_stacknode	*tmp_b;

//	clearscreen();
	fd = STDOUT_FILENO;
	field_width = (int)stacks->max_amount_digits + 2;
	tmp_a = stacks->a->top;
	tmp_b = stacks->b->top;
	ft_dprintf(fd, "\n%*c|%*c\n\n", -field_width, 'A', field_width, 'B');
	while (tmp_a || tmp_b)
	{
		printf_wrapper(fd, tmp_a, -field_width, "|");
		printf_wrapper(fd, tmp_b, field_width, "\n");
		if (tmp_a)
			tmp_a = tmp_a->prev;
		if (tmp_b)
			tmp_b = tmp_b->prev;
	}
	ft_putchar_fd('\n', fd);
}
