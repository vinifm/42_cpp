/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:51:38 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 03:04:57 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

std::vector<unsigned int>	PmergeMe::_sequence;
int							PmergeMe::_straggler = -1;
std::vector< std::pair <int, int> >	PmergeMe::_vecPairs;
std::deque< std::pair <int, int> >	PmergeMe::_deqPairs;

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& copy) { (void)copy; }
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;
	return *this;
}
PmergeMe::~PmergeMe() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/
void	PmergeMe::execute(const std::vector<unsigned int>& sequence)
{
	_sequence = sequence;
	std::cout << "Before: ";
	_displaySequence(sequence);
	_saveStraggler();
	_savePairs();
	_sort(_vecPairs, VECTOR);
	_sort(_deqPairs, DEQUE);
}

/* Save sequence into containers of pairs */
void	PmergeMe::_savePairs()
{
	size_t	size = _sequence.size();
	if (_straggler != -1)
		--size;
	for (size_t i = 0; i < size; i += 2) {
		std::pair<int, int> pair(_sequence[i], _sequence[i + 1]);
		_vecPairs.push_back(pair);
		_deqPairs.push_back(pair);
	}
}

/* Save last number if sequence is odd */
void	PmergeMe::_saveStraggler()
{
	std::vector<unsigned int>::const_iterator it = _sequence.end();
	if (!(_sequence.size() % 2))
		_straggler = (*(--it));
}

bool	PmergeMe::errorMsg(std::string desc)
{
	std::cout << RED "Error: " RESET << desc << std::endl;
	return false;
}

