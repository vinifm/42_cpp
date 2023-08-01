/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:37:49 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/01 12:50:51 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

#define	RESET	"\033[0m"
#define	MAGENTA	"\033[1;35m"
#define	BLUE	"\033[1;34m"

void				title(std::string msg, std::string color, size_t size);
void				fillEmptySpan(Span& span);
std::vector<int>	randomVector(unsigned int N);

void	testConstructors()
{
	title("CONSTRUCTORS", MAGENTA, 50);
	Span	empty;
	Span	copy(empty);
	Span	small(5);

	std::cout << empty << std::endl;
	std::cout << copy << std::endl;
	for (size_t i = 0; i < small.getMaxSize() - 1; ++i)
		small.addNumber(i);
	copy = small;
	small.addNumber(42);
	std::cout << small << std::endl;
	std::cout << copy << std::endl;
}

void	testSmall()
{
	title("SMALL SPAN", MAGENTA, 50);
	Span span(5);
	fillEmptySpan(span);

	std::cout << span << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	title("Exceptions", BLUE, 30);
	try { span.addNumber(42); }
	catch (std::exception& e ) { std::cout << e.what() << std::endl; }

	Span empty;
	Span single(1);
	single.addNumber(42);
	try { single.shortestSpan(); }
	catch (std::exception& e ) { std::cout << e.what() << std::endl; }
	try { empty.longestSpan(); }
	catch (std::exception& e ) { std::cout << e.what() << std::endl; }
}

void	testBig()
{
	title("BIG SPAN", MAGENTA, 50);
	Span span(10000);
	std::vector<int>	vec(randomVector(10000));
	span.addMany(vec.begin(), vec.end());
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::cout << "Limit reached exception: ";
	try { fillEmptySpan(span); }
	catch (std::exception& e ) { std::cout << e.what() << std::endl; }
}

void	testAddMany()
{
	title("ADD WITH ITERATORS", MAGENTA, 50);
	unsigned int		size = 50;
	Span				span(100);
	std::vector<int>	vec = randomVector(size);

	span.addMany(vec.begin(), vec.end());
	std::cout << span << std::endl;
}

int	main(void)
{
	srand(static_cast<unsigned int>(std::time(NULL)));
	testConstructors();
	testSmall();
	testBig();
	testAddMany();
}

/* return a vector with N numbers between 0 and 999 */
std::vector<int> randomVector(unsigned int N)
{
	std::vector<int>	vec;
	vec.resize(N);
	for (size_t i = 0; i < N; ++i) {
		vec[i] = rand() % 1000;
	}
	return vec;
}

/* Fill empty span with random values between 0 and 99 */
void	fillEmptySpan(Span& span)
{
	for (size_t i = 0; i < span.getMaxSize(); ++i)
		span.addNumber(rand() % 100);
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
