//
// Created by Peer De bakker on 3/29/21.
//

#include "operations.h"
#include "libft.h"

void	execute_operation(const t_opcode opcode, t_collection *collection)
{
	static const char			*op_stringcodes[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr"
	};
	static const t_operation	operations[] = {
			[SA] = &sa, [SB] = &sb, [SS] = &ss,
			[PA] = &pa, [PB] = &pb,
			[RA] = &ra, [RB] = &rb, [RR] = &rr,
			[RRA] = &rra, [RRB] = &rrb, [RRR] = &rrr
	};

	ft_putendl_fd(op_stringcodes[opcode], STDOUT_FILENO);
	operations[opcode](collection);
}
