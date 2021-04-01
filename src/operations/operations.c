//
// Created by Peer De bakker on 3/29/21.
//

#include "operations.h"
#include "libft.h"

static void	error(t_collection *coll)
{
	(void)coll;
	ft_putendl_fd("Error. bad instruction", STDERR_FILENO);
}

t_opcode	string2opcode(const char *str)
{
	unsigned long int			i;
	static const char			*opcode_strings[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr"
	};

	i = 0;
	while (i < sizeof(opcode_strings))
	{
		if (ft_strncmp(str, opcode_strings[i], ft_strlen(str)) == 0)
			return (i);
		++i;
	}
	return (ERROR);
}

void	execute_operation(const t_opcode opcode, t_collection *collection)
{
	static const char			*op_stringcodes[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr", [ERROR] = "Error"
	};
	static const t_operation	operations[] = {
			[SA] = &sa, [SB] = &sb, [SS] = &ss,
			[PA] = &pa, [PB] = &pb,
			[RA] = &ra, [RB] = &rb, [RR] = &rr,
			[RRA] = &rra, [RRB] = &rrb, [RRR] = &rrr, [ERROR] = &error
	};

	ft_putendl_fd(op_stringcodes[opcode], STDOUT_FILENO);
	operations[opcode](collection);
}
