//
// Created by peerdb on 30-03-21.
//

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "stack.h"

void			fatal_error(const char *s);
unsigned int	amount_digits(int n);
int				atoi_exit_on_error(const char *s);
unsigned int	get_max_bits(unsigned int max_num);
void			clearscreen(void);
size_t			get_max_element(const t_stack *stack);

#endif //UTILS_H
