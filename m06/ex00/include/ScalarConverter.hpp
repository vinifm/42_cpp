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
#include <limits>

#define	WHITE	"\033[1;37m"
#define	RESET	"\033[0m"

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
	static size_t		_precision;

	static void			_convertFloat();
	static void			_convertDouble();
	static void			_convertInt();
	static void			_convertChar();
	static std::string	_floatPseudoLiteral();
	static std::string	_doublePseudoLiteral();

	// _detect.cpp
	static bool	_isFloat();
	static bool	_isDouble();
	static bool	_isInt();
	static bool	_isChar();
	static bool	_isPseudoLiteral();
	static bool _isdigit(int c);
	static bool	_isDisplayableChar(char c);
	static bool	_hasSign();

	// _print.cpp
	static void	_printChar();
	static void	_printInt();
	static void	_printFloat();
	static void	_printDouble();
	static void	_printConversions();
	static void	_printPseudoLiteral();

	// _exceptions.cpp
	static bool	_intOverflow();
	static bool	_floatOverflow();
	static bool	_charOverflow();

	class InvalidTypeException: public std::exception {
		public: virtual const char* what() const throw();
	};

	class InvalidIntException: public std::exception {
		public: virtual const char* what() const throw();
	};

	class InvalidFloatException: public std::exception {
		public: virtual const char* what() const throw();
	};

	class InvalidDoubleException: public std::exception {
		public: virtual const char* what() const throw();
	};
};

#endif
