//
// Created by peerdb on 30-03-21.
//

#ifndef UTILS_H
#define UTILS_H

#include "stack.h"
#include <stdlib.h>

void fatal_error(t_collection *stacks, const char *s);
int cleanup(t_collection *stacks);

unsigned int amount_digits(int n);
int atoi_exit_on_error(const char *s, bool *error);
unsigned int get_max_bits(unsigned int max_num);
void clearscreen(void);
size_t get_max_element(const t_stack *stack);

// UTILS_H
#endif
