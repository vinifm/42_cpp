#!/bin/bash

# ANSI escape codes for color
RESET="\033[0m"
WHITE="\033[1;37m"
YELLOW="\033[1;33m"

# Executable
convert="./convert"

# Test files
test_dir="_tests"
char="$test_dir/char_test.txt"
int="$test_dir/int_test.txt"
float="$test_dir/float_test.txt"
double="$test_dir/double_test.txt"

if [ $# -ne 1 ]; then
	echo "Usage: $0 <test_mode>"
	exit 1
fi

if [ $1 = "char" ] || [ $1 = "all" ]; then
	echo -e "${YELLOW}/*--- CHAR CONVERSIONS ---*/${RESET}"
	while read line; do
		echo -e "${WHITE}String literal:${RESET} $line"
		$convert "$line"
		echo ""
	done < $char
fi

if [ $1 = "int" ] || [ $1 = "all" ]; then
	echo -e "${YELLOW}/*--- INT CONVERSIONS ---*/${RESET}"
	while read line; do
		echo -e "${WHITE}String literal:${RESET} $line"
		$convert "$line"
		echo ""
	done < $int
fi

if [ $1 = "float" ] || [ $1 = "all" ]; then
	echo -e "${YELLOW}/*--- FLOAT CONVERSIONS ---*/${RESET}"
	while read line; do
		echo -e "${WHITE}String literal:${RESET} $line"
		$convert "$line"
		echo ""
	done < $float
fi

if [ $1 = "double" ] || [ $1 = "all" ]; then
	echo -e "${YELLOW}/*--- DOUBLE CONVERSIONS ---*/${RESET}"
	while read line; do
		echo -e "${WHITE}String literal:${RESET} $line"
		$convert "$line"
		echo ""
	done < $double
fi
