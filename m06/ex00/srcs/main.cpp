/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:57:45 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/25 18:02:50 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/colors.hpp"

void	title(std::string msg, std::string color, size_t size);
void	convert(std::string str)
{
	ScalarConverter::convert(str);
}

void	testFloat()
{
	title("FLOAT", MAGENTA, 50);
	convert(".42f");
	convert("42.f");
	convert("42f");
	convert("-42f");

	title("INVALID CASES", BLUE, 30);
	try { convert("4ff"); }
	catch (std::exception& e) {std::cout << e.what() << std::endl; }
	try { convert("4.09.8f"); }
	catch (std::exception& e) {std::cout << e.what() << std::endl; }
}

void	testDouble()
{
	title("DOUBLE", MAGENTA, 50);
	convert("4.2");
	convert(".3");
	convert("-.09");
	convert("42.");
}

void	testInt()
{
	title("INT", MAGENTA, 50);
	convert("4");
	convert("2147483648");
	convert("42");
	convert("-200");
}

void	testChar() {
	title("CHAR", MAGENTA, 50);
	convert("a");
	convert("!");
	convert("~");
}

void	testPseudoLiteral() {
	title("PSEUDO LITERAL", MAGENTA, 50);
	convert("+inf");
	convert("-inf");
	convert("nan");
	convert("+inff");
	convert("-inff");
	convert("nanf");
}

int	main()
{
	// ScalarConverter	foo;	// Should not work since constructor is private;
	// testFloat();
	// testDouble();
	testInt();
	// testChar();
	// testPseudoLiteral();
	return 0;
}

/* Print formatted title */
void	title(std::string msg, std::string color, size_t size) {
	if (size < msg.size())
		size = msg.size();
	size_t	chars_left = size - msg.size();

	std::cout << std::endl << color << "/*--- " << msg << " ";
	for (size_t i = 0; i < chars_left; i++)
		std::cout << "-";
	std::cout << "*/" << RESET << std::endl;
}
