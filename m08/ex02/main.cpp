/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:51:04 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/01 17:04:55by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>

void	title(std::string msg, std::string color, size_t size);
void	pdfTest();

void	testIntDeque()
{
	title("INT STACK WITH DEFAULT DEQUE CONTAINER", MAGENTA, 50);
	MutantStack<int>	int_stack;
	MutantStack<int>	empty;

	if (int_stack.empty())
		std::cout << "empty stack" << std::endl;
	for (size_t i = 0; i < 5; ++i) {
		int rand_num = rand() % 10;
		int_stack.push(rand_num);
		std::cout << rand_num << " added to stack" << std::endl;
	}
	std::cout << "Stack size: " << int_stack.size() << std::endl;
	std::cout << "Top element: " << int_stack.top() << std::endl;
	int_stack.pop();
	std::cout << "Top element removed. New top: "
		<< int_stack.top() << std::endl;

	title("ITERATOR", BLUE, 30);
	std::cout << "Iterator: " << std::endl;
	for (MutantStack<int>::iterator it = int_stack.begin();
			it != int_stack.end();
			++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	title("REVERSE ITERATOR", BLUE, 30);
	std::cout << "Iterator: " << std::endl;
	for (MutantStack<int>::reverse_iterator it = int_stack.rbegin();
			it != int_stack.rend();
			++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	testStringList()
{
	title("STRING STACK WITH LIST CONTAINER", MAGENTA, 50);
	MutantStack< std::string, std::list<std::string> >	string_stack;
	MutantStack< std::string, std::list<std::string> >	empty;

	if (string_stack.empty())
		std::cout << "empty stack" << std::endl;
	string_stack.push("hello");
	string_stack.push("big");
	string_stack.push("wide");
	string_stack.push("world");
	string_stack.push("baby!");
	std::cout << "Stack size: " << string_stack.size() << std::endl;
	std::cout << "Top element: " << string_stack.top() << std::endl;
	string_stack.pop();
	std::cout << "Top element removed. New top: "
		<< string_stack.top() << std::endl;

	title("ITERATOR", BLUE, 30);
	std::cout << "Iterator: " << std::endl;
	for (MutantStack< std::string, std::list<std::string> >::iterator \
			it = string_stack.begin();
			it != string_stack.end();
			++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	title("REVERSE ITERATOR", BLUE, 30);
	std::cout << "Iterator: " << std::endl;
	for (MutantStack< std::string, std::list<std::string> >::reverse_iterator \
			it = string_stack.rbegin();
			it != string_stack.rend();
			++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main(void)
{
	testIntDeque();
	testStringList();
	pdfTest();
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
