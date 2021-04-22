#!/usr/bin/env python3
import sys
import os
import subprocess
import random
import sh

DEFAULT_AMOUNT = 4


def tester(*args) -> tuple:
	if len(args) > 1:
		my_nbs = list(args)
	else:
		amount_nbs = args[0]
		my_nbs = set()
		for i in range(amount_nbs):
			my_nbs.add(random.randint(0, 10000))
		my_nbs = list(my_nbs)
		random.shuffle(my_nbs)
		random.shuffle(my_nbs)
	arg = [str(x) for x in my_nbs]

	# print(f'list_nbs is {list_nbs}, arg is {arg}')
	p1 = subprocess.Popen(['./push_swap'] + arg, stdout=subprocess.PIPE)
	p2 = subprocess.Popen(['./checker'] + arg, stdin=p1.stdout, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL)
	output = p2.stdout.read().decode('ascii')
	split_output = output.split()
	return split_output[0][1:-1], int(split_output[2])


def assert_outcome(test_input, desired_outcome):
	assert test_input[0] == desired_outcome


def moulinette(argv):
	tester(0, 1, 2)
	# tester(3)


if __name__ == "__main__":
	moulinette(sys.argv)