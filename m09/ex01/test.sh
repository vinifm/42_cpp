#!/bin/bash

# ANSI escape codes for color
RESET="\033[0m"
WHITE="\033[1;37m"
YELLOW="\033[1;33m"

# Executable
RPN="./RPN"

# Test file
input_file="test_input.txt"

if [ ! -f $input_file ]; then
	echo -e "Error: Input file ${input_file} not found."
	exit 1
fi

echo -e "\n${YELLOW}/*--- TESTING INPUT FILE ---*/${RESET}\n"
make re > /dev/null
while IFS= read -r line; do
	echo -e "Input: ${line}"
	echo -n "Output: "
	$RPN "$line"
	echo ""
done < "$input_file"
