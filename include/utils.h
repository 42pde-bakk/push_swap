//
// Created by peerdb on 30-03-21.
//

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void			fatal_error(const char *s);
unsigned int	amount_digits(int n);
int				atoi_exit_on_error(const char *s);
unsigned int	get_max_bits(unsigned int max_num);
void			clearscreen(void);

#endif //UTILS_H
