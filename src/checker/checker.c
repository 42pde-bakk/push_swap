//
// Created by peerdb on 02-04-21.
//

#include "libft.h"
#include "get_next_line.h"
#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

static void	clearline(char **line)
{
	free(*line);
	*line = NULL;
}

void	checker(t_collection *coll)
{
	static const char	*is_sorted_msg[] = {"KO", "OK"};
	char				*line;
	t_opcode			opcode;
	unsigned int		op_count;

	op_count = 0;
	while (get_next_line(0, &line) > 0)
	{
		opcode = string2opcode(line);
		if (opcode != ERROR)
		{
			++op_count;
			execute_operation(opcode, coll);
			print_stacks(coll);
		}
		else if (ft_strlen(line) > 0)
			ft_putendl_fd("Error. Bad instruction.", STDERR_FILENO);
		clearline(&line);
		if (stack_is_sorted(coll))
			break;
	}
	clearline(&line);
	ft_dprintf(STDOUT_FILENO, "[%s] in %d instructions.\n", is_sorted_msg[(int)stack_is_sorted(coll)], op_count);
}
