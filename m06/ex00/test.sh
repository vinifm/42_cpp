#!/bin/bash

# ANSI escape codes for color
RESET="\033[0m"
YELLOW="\033[1;33m"

# Executable
convert="./convert"

# Test files
test_dir="_tests"
int="$test_dir/int_test.txt"

if [ $# -ne 1 ]; then
	echo "Usage: $0 <test_mode>"
	exit 1
fi

if [ $1 = "int" ] || [ $1 = "all" ]; then
	echo -e "${YELLOW}/*--- INT CONVERSIONS ---*/${RESET}"
	while read line; do
		$convert "$line"
	done < $int
fi
