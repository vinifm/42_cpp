/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:51:38 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 07:00:59 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*--- STATIC VARIABLES -------------------------------------------------------*/

size_t								PmergeMe::_size;
std::vector<unsigned int>			PmergeMe::_sequence;
int									PmergeMe::_straggler = -1;
std::vector< std::pair <int, int> >	PmergeMe::_vecPairs;
std::deque< std::pair <int, int> >	PmergeMe::_deqPairs;
std::vector<int>					PmergeMe::_sortedVec;
std::deque<int>						PmergeMe::_sortedDeq;

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
	_size = sequence.size();
	std::cout << "Before: ";
	_displaySequence(sequence);
	_saveStraggler();
	_savePairs();
	_sort(_vecPairs, VECTOR);
	// _sort(_deqPairs, DEQUE);

	for (std::vector<int>::iterator it = _sortedVec.begin();
		it != _sortedVec.end();
		++it)
		std::cout << *it << " ";
	std::cout << std::endl;
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

/* Return sequence of jacobsthal numbers. */
std::vector<int>	PmergeMe::_returnJacobSeq(std::vector<int>& pend)
{
	int 				i = 0;
	int					size = pend.size();
	std::vector<int>	returnSeq;
	int					jacobIndex = 3;

	while (_jacobsthal(jacobIndex) < size - 1) {
		returnSeq.push_back(_jacobsthal(jacobIndex));
		++jacobIndex;
		++i;
	}
	return returnSeq;
}

int	PmergeMe::_jacobsthal(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return _jacobsthal(index - 1) + 2 * _jacobsthal(index - 2);
}

bool	PmergeMe::errorMsg(std::string desc)
{
	std::cout << RED "Error: " RESET << desc << std::endl;
	return false;
}

