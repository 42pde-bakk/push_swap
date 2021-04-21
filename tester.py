#!/usr/bin/env python3
import sys
import os
import random

DEFAULT_AMOUNT = 4

if len(sys.argv) > 2:
	my_nbs = list(sys.argv[1:])
else:
	amount_nbs = DEFAULT_AMOUNT
	if len(sys.argv) > 1:
		amount_nbs = int(sys.argv[1])
	my_nbs = set()
	for i in range(amount_nbs):
		my_nbs.add(random.randint(0, 10000))

list_nbs = list(my_nbs)
random.shuffle(list_nbs)
random.shuffle(list_nbs)
random.shuffle(list_nbs)
arg = " ".join(str(x) for x in list_nbs)

os.system(f'make; ./push_swap {arg} | ./checker {arg}')
