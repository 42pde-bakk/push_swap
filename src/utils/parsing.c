//
// Created by peerdb on 02-04-21.
//

#include <stdbool.h>
#include "stack.h"
#include "utils.h"
#include "libft.h"

int	is_valid_arg(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9')))
			return (false);
		++i;
	}
	return (true);
}

void	parse_array(t_collection *coll, char **argv, int i)
{
	int				item;
	unsigned int	digits_amount;

	while (argv[i])
	{
		if (!is_valid_arg(argv[i]))
		{
			delete_stack(coll->a);
			fatal_error("Error");
		}
		item = atoi_exit_on_error(argv[i]);
		digits_amount = amount_digits(item);
		if (stack_duplicate_check(coll->a, item))
		{
			delete_stack(coll->a);
			fatal_error("Error");
		}
		if (digits_amount > coll->max_amount_digits)
			coll->max_amount_digits = digits_amount;
		stack_push_under(coll->a, ft_atoi(argv[i]));
		++i;
	}
}

void	parse_split_array(t_collection *coll, char *s)
{
	char	**array;
	int		i;

	array = ft_split(s, ' ');
	if (array == NULL)
		fatal_error("Error");
	parse_array(coll, array, 0);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		++i;
	}
	free(array);
	array = NULL;
}

int	cleanup(t_collection *coll)
{
	delete_stack(coll->a);
	delete_stack(coll->b);
	free(coll);
	return (0);
}
