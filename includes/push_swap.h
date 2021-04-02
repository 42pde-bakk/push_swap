//
// Created by Peer De bakker on 3/29/21.
//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include "utils.h"

# ifndef CHECKER
#  define CHECKER -1
# endif

int		is_valid_arg(const char *s);
void	parse_array(t_collection *coll, char **argv, int i);
void	parse_split_array(t_collection *coll, char *s);

#endif //PUSH_SWAP_H
