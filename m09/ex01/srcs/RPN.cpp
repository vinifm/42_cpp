/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:44:18 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/07 11:01:00 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

const std::string	RPN::_operators = "+-/*";
std::stack<int>	RPN::_stack;

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

RPN::RPN() {}
RPN::RPN(const RPN& copy) { (void)copy; }
RPN& RPN::operator=(const RPN& rhs) {
	(void)rhs;
	return *this;
}
RPN::~RPN() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

/* Return true if stack is successfully created */
bool	RPN::execute(const std::string& input)
{
	std::stringstream	ss(input);
	std::string			token;
	char				c;

	while (ss >> token) {
		c = _strToChar(token);
		if (!c)
			return _errorMsg("Not a char", token);
		else if (!isdigit(c) && !_isOperator(c))
			return _errorMsg("Not a digit nor operand", token);
		else if (isdigit(c))
			_stack.push(_strToInt(token));
		else if (_isOperator(c))
			if (!_tryOperation(c))
				return false;
	}
 	if (_stack.size() != 1)
		return _errorMsg("Invalid RPN sequence", "\0");
	std::cout << _stack.top() << std::endl;
	return true;
}

bool	RPN::_tryOperation(char op)
{
	unsigned int	operand1;
	unsigned int	operand2;

	if (_stack.size() < 2)
		return _errorMsg("Not enough operands in the stack", "\0");
	operand2 = _stack.top();
	_stack.pop();
	operand1 = _stack.top();
	_stack.pop();
	if (!_isValidOperation(operand1, operand2, op))
		return _errorMsg("Result is not valid integer", "\0");
	switch (op) {
		case '+':
			_stack.push(operand1 + operand2);
			return true;
		case '-':
			_stack.push(operand1 - operand2);
			return true;
		case '*':
			_stack.push(operand1 * operand2);
			return true;
		case '/':
			if (operand2 == 0)
				return _errorMsg("Division by zero", "\0");
			_stack.push(operand1 / operand2);
			return true;
	}
	return false;
}

bool	RPN::_isValidOperation(const unsigned int& operand1,
	const unsigned int& operand2, const char& op
) {
	double result;
	switch (op) {
		case '+':
			result = operand1 + operand2;
		case '-':
			result = operand1 - operand2;
		case '*':
			result = operand1 * operand2;
		case '/':
			result = operand1 / operand2;
	}
	return result < std::numeric_limits<int>::max();
}

char	RPN::_strToChar(const std::string& str)
{
	if (str.length() > 1)
		return 0;
	return str[0];
}

int	RPN::_strToInt(const std::string& str)
{
	std::istringstream	ss(str);
	int					num;
	if (!(ss >> num)) {
		_errorMsg("Failed to convert string to int", str);
		return -1;
	}
	return num;
}

bool	RPN::_isOperator(const char& c)
{
	if (_operators.find(c) != std::string::npos)
		return true;
	return false;
}

bool		RPN::_errorMsg(std::string desc, std::string val)
{
	if (!val[0])
		std::cout << RED "Error: " RESET << desc << "." << std::endl;
	else
		std::cout << RED "Error: " RESET << desc << ": " << val << std::endl;
	return false;
}
