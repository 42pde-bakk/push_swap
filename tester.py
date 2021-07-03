#!/usr/bin/env python3
import sys
import subprocess
import random

DEFAULT_AMOUNT = 4


def create_array(args):
	if len(args) == 1 and type(args[0]) == int:
		print("int")
		amount_nbs = args[0]
		print(f'amount_nbs is {amount_nbs}')
		my_nbs = set()
		for i in range(amount_nbs):
			my_nbs.add(random.randint(0, 10000))
		my_nbs = list(my_nbs)
		random.shuffle(my_nbs)
		random.shuffle(my_nbs)
	else:
		my_nbs = args
	return [str(x) for x in my_nbs]


def test_checker_parsing(*args) -> str:
	arg = create_array(list(args))
	status, output = subprocess.getstatusoutput(f'./checker "{arg}"')
	return output


def test_checker_operations(nbs, checker_input) -> str:
	checker_input = "\n".join(checker_input)
	print(f'checker_input is {checker_input}')
	status, output = subprocess.getstatusoutput(f'echo "{checker_input}" | ./checker {nbs}')
	print(f'stauts is {status}, output is {output}')
	return output


def assert_checker_outcome(test_output, desired_outcome):
	# if test_output != desired_outcome:
		# print(f"Test failed for '{test_output}'")
	assert test_output == desired_outcome
	return 5


def tester(*args) -> tuple:
	arg = create_array(args)
	p = subprocess.Popen(f'ARG="{" ".join(arg)}"; ./push_swap $ARG | ./checker $ARG', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	stdout = p.stdout.read().decode('ascii')
	stderr = p.stderr.read().decode('ascii')
	print(f'stdout is {stdout}')
	print(f'stderr is {stderr}')
	result, amount_ops = stdout[1:3], int(''.join(c for c in stdout if c.isdigit()))
	print(f'{result} in {amount_ops}')
	return result, amount_ops


def assert_outcome(test_input, desired_outcome):
	assert test_input[0] == desired_outcome
	return 5


def moulinette(argv):
	# score = 0
	# try:
	# 	# score += assert_checker_outcome(test_checker_parsing('hallo', 1, 2), 'Error')
	# 	# score += assert_checker_outcome(test_checker_parsing(2, 1, 2), 'Error')
	# 	# score += assert_checker_outcome(test_checker_parsing(238972, 2147483649, 789), 'Error')
	# 	# score += assert_checker_outcome(test_checker_parsing(""), 'Error')
	# 	# score += assert_checker_outcome(test_checker_operations([0, 9, 1, 8, 2, 7, 3, 6, 4, 5], ['sa', 'pb', 'rr']), 'KO')
	# 	# score += tester(0, 1, 2)
	# 	print(f'All tests passed, final score is {score}')
	# except AssertionError as e:
	# 	print(f'Test failed because {e}, final score is {score}')

	# print(tester(1043, 6630, 239, 4551, 9159))
	# print(tester(1750, 9715, 3048, 3453, 9149))
	# print(tester(8, 5, 6, 3, 2, 1))
	# print(tester(5))
	# print(tester(27))
	for i in range(1, len(argv)):
		print(f'sys.argv[{i}] is {argv[i]}')
		tester(int(argv[i]))


if __name__ == "__main__":
	moulinette(sys.argv)
