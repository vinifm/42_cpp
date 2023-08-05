/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:43:08 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/05 17:45:46 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <cctype>	// isdigit
#include "MutantStack.hpp"

#define RED		"\033[1;31m"
#define	RESET	"\033[0m"

typedef enum	e_type
{
	INVALID,
	OPERATOR,
	OPERAND
}				t_type;

typedef struct	s_elem {
	t_type	type;
	char	value;
}				t_elem;

class RPN
{
public:
	static void	execute(const std::string input);

private:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& rhs);
	~RPN();

	static const std::string	_operators;
	static MutantStack<t_elem>	_stack;

	static bool		_createStack(const std::string& input);
	static t_elem	_returnElem(const char& value, const t_type& type);
	static char		_strToChar(const std::string& str);
	static bool		_isOperator(const char& c);
	static bool		_errorMsg(std::string desc, std::string val);
};

#endif
