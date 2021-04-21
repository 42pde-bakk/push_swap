#!/usr/bin/env python3

import sys
import os
import random
import subprocess

amount_nbs = 4
if len(sys.argv) > 1:
	amount_nbs = int(sys.argv[1])

my_nbs = set()

for i in range(amount_nbs):
	my_nbs.add(random.randint(0, 100))


nbs_list = " ".join(str(x) for x in my_nbs)

os.system(f'make re DEBUG=1; ./push_swap {nbs_list} | ./checker {nbs_list}')
