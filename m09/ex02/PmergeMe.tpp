/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:51:18 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 18:05:55 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PMERGE_TPP
# define PMERGE_TPP

#include "PmergeMe.hpp"

template < typename Container >
void	PmergeMe::_displaySequence(const Container& seq)
{
	for (typename Container::const_iterator it = seq.begin();
		it != seq.end();
		++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template < typename Container >
void	PmergeMe::_sort(Container& cont, const t_type type)
{
	struct timeval	start;
	(void) type;

	gettimeofday(&start, NULL);
	for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it)
		if (it->first > it->second)
			std::swap(it->first, it->second);
	_mergeSort(cont);
	_createSequence(cont, type);
}

/* Recursively sort the pair sequence by the greater value in the pair */
template < typename Container >
void	PmergeMe::_mergeSort(Container& cont)
{
	size_t	size = cont.size();
	if (size <= 1)
		return ;
	Container	left;
	Container	right;
	size_t		half = size / 2;
	typename Container::iterator it = cont.begin();
	Compare<Container>	cmp;

	for (size_t i = 0; i < half; ++i, ++it)
		left.push_back(*it);
	for (size_t i = half; i < size; ++i, ++it)
		right.push_back(*it);
	_mergeSort(left);
	_mergeSort(right);
	std::merge(
		left.begin(), left.end(),
		right.begin(), right.end(),
		cont.begin(), cmp
	);
}

/*
	- Split pairs into main sequence: larger elements go into sequence, smaller
	elements go into pend.
	- Since first element in pend is smaller than the first in sequence, insert
	it in the beginning of sequence.
*/
template < typename Container >
void	PmergeMe::_createSequence(Container& cont, const t_type type)
{
	std::vector<int>			sequence;
	std::vector<int>			pend;
	std::vector<int>			indexSeq;
	if (type == DEQUE) {
		std::deque<int>				sequence;
		std::deque<int>				pend;
		std::deque<int>				indexSeq;
	}
	for (typename Container::iterator it = cont.begin();
		it != cont.end();
		++it)
	{
		sequence.push_back(it->second);
		pend.push_back(it->first);
	}
	sequence.insert(sequence.begin(), pend[0]);
	pend.erase(pend.begin());

	std::vector<int>	jacobSeq = _returnJacobSeq(pend);
	size_t				iter = 0;
	int					item = -1;

	indexSeq.insert(indexSeq.begin(), 1);
	while (iter <= (size_t)pend.size()){
		if (jacobSeq.size() != 0) {
			indexSeq.push_back(jacobSeq[0]);
			item = pend.at(jacobSeq[0] - 1);
			jacobSeq.pop_back();
		} else {
			if (std::find(indexSeq.begin(), indexSeq.end(), item)
				!= indexSeq.end()) {
				iter++;
			}
			if (iter)
				item = pend.at(iter - 1);
			std::cout << "item is: " << item << std::endl;
			indexSeq.push_back(iter);
		}
		if (item != -1) {
			std::vector<int>::iterator it_s = std::lower_bound(sequence.begin(), sequence.end(), item);
			int insertIndex = std::distance(sequence.begin(), it_s);
			sequence.insert(sequence.begin() + insertIndex, item);
		}
		iter++;
	}
	if (_straggler != -1){
		std::vector<int>::iterator it_s = std::lower_bound(sequence.begin(), sequence.end(), _straggler);
		int insertIndex = std::distance(sequence.begin(), it_s);
		sequence.insert(sequence.begin() + insertIndex, _straggler);
	}
	if (type == VECTOR)
		_sortedVec.assign(sequence.begin(), sequence.end());
	else
		_sortedDeq.assign(sequence.begin(), sequence.end());
}

#endif
