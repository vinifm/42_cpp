/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:13:53 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/24 16:58:30y viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <sstream>	// istringstream;
#include <iomanip>	// setprecision;

class ScalarConverter {
public:
	static void	convert(std::string str);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter();

	static std::string	_str;
	static std::string	_type;
	static int			_int;
	static float		_float;
	static double		_double;
	static char			_char;
	static long double	_check;

	static bool	_isFloat();
	static bool	_isDouble();
	static bool	_isInt();
	static bool	_isChar();
	static bool	_isPseudoLiteral();
	static bool _isdigit(int c);

	static void	_convertFloat();
	static void	_convertDouble();
	static void	_convertInt();
	static void	_convertChar();

	static void	_printConversions();
	static void	_printIntOverflow();
	static bool	_hasSign();

	class InvalidTypeException: public std::exception {
		public: virtual const char* what() const throw();
	};
};

#endif
