/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:44:18 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/05 17:39:59 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

const std::string	RPN::_operators = "+-/*";
MutantStack<t_elem>	RPN::_stack;

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

RPN::RPN() {}
RPN::RPN(const RPN& copy) { (void)copy; }
RPN& RPN::operator=(const RPN& rhs) {
	(void)rhs;
	return *this;
}
RPN::~RPN() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	RPN::execute(const std::string input)
{
	if (!_createStack(input))
		return ;
}

/* Return true if stack is successfully created */
bool	RPN::_createStack(const std::string& input)
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
			_stack.push(_returnElem(c, OPERAND));
		else if (_isOperator(c))
			_stack.push(_returnElem(c, OPERATOR));
	}
	return true;
}

t_elem	RPN::_returnElem(const char& value, const t_type& type)
{
	t_elem elem;
	elem.value = value;
	elem.type = type;
	return elem;
}

char		RPN::_strToChar(const std::string& str)
{
	if (str.length() > 1)
		return 0;
	return str[0];
}

bool	RPN::_isOperator(const char& c)
{
	if (_operators.find(c) != std::string::npos)
		return true;
	return false;
}

bool		RPN::_errorMsg(std::string desc, std::string val)
{
	std::cout << RED "Error: " RESET << desc << ": " << val << std::endl;
	return false;
}
