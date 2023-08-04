/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:01:24 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/04 16:39:50 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <algorithm>

#define	RESET	"\033[0m"
#define	MAGENTA	"\033[1;35m"
#define	BLUE	"\033[1;34m"

template < typename T, typename Container=std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:
	MutantStack() {};
	MutantStack(const MutantStack& copy) { *this = copy; };
	MutantStack& operator=(const MutantStack& rhs)
	{
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
	};
	~MutantStack() {};

	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	iterator			begin() { return this->c.begin(); };
	iterator			end() { return this->c.end(); };
	reverse_iterator	rbegin() { return this->c.rbegin(); };
	reverse_iterator	rend() { return this->c.rend(); };
};

#endif
