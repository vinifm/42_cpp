/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:13:31 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/01 17:31:08 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <sstream>

void	title(std::string msg, std::string color, size_t size);
void	pdfTest_mstack();
void	pdfTest_list_stack();

/* PDF TESTS */

void	pdfTest()
{
	title("PDF TEST", MAGENTA, 50);
	std::ostringstream	mstack_output;
	std::ostringstream	lstack_output;
	std::streambuf*		coutBuffer = std::cout.rdbuf();

	std::cout.rdbuf(mstack_output.rdbuf());
	pdfTest_mstack();

	std::cout.rdbuf(lstack_output.rdbuf());
	pdfTest_list_stack();

	std::cout.rdbuf(coutBuffer);
	if (mstack_output.str() == lstack_output.str())
		std::cout << "Outputs are the same :)\n" << std::endl;
	else
		std::cout << "Outputs differ :(\n" << std::endl;
}

void	pdfTest_mstack()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	pdfTest_list_stack()
{
	MutantStack<int> list_stack;
	list_stack.push(5);
	list_stack.push(17);
	std::cout << list_stack.top() << std::endl;
	list_stack.pop();
	std::cout << list_stack.size() << std::endl;
	list_stack.push(3);
	list_stack.push(5);
	list_stack.push(737);
	//[...]
	list_stack.push(0);
	MutantStack<int>::iterator it = list_stack.begin();
	MutantStack<int>::iterator ite = list_stack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(list_stack);
}
