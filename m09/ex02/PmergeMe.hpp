/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:47:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 03:05:14 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>

#define RED		"\033[1;31m"
#define	RESET	"\033[0m"

typedef enum e_type
{
	VECTOR,
	DEQUE
}			t_type;

class PmergeMe
{
public:
	static void	execute(const std::vector<unsigned int>& sequence);
	static bool	errorMsg(std::string desc);

private:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe();

	static std::vector<unsigned int> _sequence;
	static int				_straggler;
	static std::vector< std::pair <int, int> >	_vecPairs;
	static std::deque< std::pair <int, int> >	_deqPairs;

	static void	_saveStraggler();
	static void	_savePairs();

	template < typename Container >
	static void	_displaySequence(const Container& seq);

	template < typename Container >
	static void	_sort(Container& cont, const t_type type);

	template < typename Container >
	static void	_mergeSort(Container& cont);

	/*
		Return ​true if the first argument is less than (i.e. is ordered before)
		the second.
	*/
	template < typename Container >
	struct Compare {
		bool operator()(
			const typename Container::value_type& a,
			const typename Container::value_type& b) const {
				return a.second < b.second;
			}
	};
};

#include "PmergeMe.tpp"

#endif