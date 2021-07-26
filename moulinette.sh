#!/usr/bin/env bash
make -s


function exit_fatal {
  echo "Failed './$*'"
  exit 1
}

# $1 is the program name
# $2 is the list of arguments to pass to ./push_swap
# $3 is the expected outcome
function test_outcome {
  if [[ "$2" == "" ]]; then
    output=$(./"$1" 2>&1) # './push_swap' behaves differently than './push_swap "" '
  else
    output=$(./$"$1" "$2" 2>&1)
  fi
  if [[ "$output" != "$3" ]]; then
    exit_fatal "$1" "$2"
  fi
}

# $1 is the list of arguments to pass to the program
# $2 is the maximum amount of allowed instructions
function test_amount_instructions {
  ./push_swap "$1" 2>&1 | tee /tmp/push_swap_output.txt | ./checker "$1" > /tmp/checker_output.txt 2>&1
  if grep -q "Error" /tmp/push_swap_output.txt || ! grep -q "[OK]" /tmp/checker_output.txt; then
    exit_fatal "push_swap" "$1"
  fi
  instructionAmount=$(wc -l < /tmp/push_swap_output.txt)
  if [[ instructionAmount -gt "$2" ]]; then
    echo "$instructionAmount instructions is too many!"
    exit_fatal "$*"
  fi
}


test_outcome  "push_swap" "hats"  "Error"
test_outcome  "checker"   "hats"  "Error"

test_outcome  "push_swap" "8 2 4 2"  "Error"
test_outcome  "checker"   "8 2 4 2"  "Error"

test_outcome  "push_swap" "1 1000 2147483648" "Error"
test_outcome  "checker"   "1 1000 2147483648" "Error"

test_outcome  "push_swap" "" ""
test_outcome  "checker" "" ""

test_outcome  "push_swap" "42" ""
test_outcome  "push_swap" "0 1 2 3" ""
test_outcome  "push_swap" "0 1 2 3 4 5 6 7 8 9" ""


test_amount_instructions  "2 1 0"     3
# check that instruciton is list is 2 OR 3
test_amount_instructions  "1 5 2 4 3" 7

test_amount_instructions  "1 5 2 4 3"     12

random_range=$(shuf -i 0-10 -n 5 | tr '\n' ' ')
test_amount_instructions  "$random_range" 12

# ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG

# ARG=<5 random values>; ./push_swap $ARG | ./checker $ARG
# check that its no more than 12 instructions
