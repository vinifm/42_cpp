/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:51:18 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 03:29:02 by viferrei         ###   ########.fr       */
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
	// _createSeq();
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

#endif
