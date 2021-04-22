//
// Created by peerdebakker on 22-04-21.
//

#include "operations.h"
#include "libft.h"

static void	print_operation(const t_opcode opcode)
{
	static const char			*op_stringcodes[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr", [ERROR] = "Error"
	};

	if (opcode != ERROR)
		ft_putendl_fd(op_stringcodes[opcode], STDOUT_FILENO);
}

void	execute_and_print(const t_opcode op, t_collection *coll)
{
	execute_operation(op, coll);
	print_operation(op);
}