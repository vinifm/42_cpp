/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:43:08 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/07 10:56:13 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <cctype>	// isdigit
#include <stack>
#include <limits>

#define RED		"\033[1;31m"
#define	RESET	"\033[0m"

class RPN
{
public:
	static bool	execute(const std::string& input);

private:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& rhs);
	~RPN();

	static const std::string			_operators;
	static std::stack<int>		_stack;

	static bool		_createStack(const std::string& input);
	static char		_strToChar(const std::string& str);
	static int		_strToInt(const std::string& str);
	static bool		_isOperator(const char& c);
	static bool		_errorMsg(std::string desc, std::string val);
	static bool		_tryOperation(char op);
	static bool		_isValidOperation(const unsigned int& operand1,
						const unsigned int& operand2, const char& op);
};

#endif
