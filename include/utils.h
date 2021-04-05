//
// Created by peerdb on 30-03-21.
//

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void			fatal_error(const char *s);
unsigned int	amount_digits(int n);
int				atoi_exit_on_error(const char *s);
void			clearscreen(void);

#endif //PUSH_SWAP_UTILS_H
