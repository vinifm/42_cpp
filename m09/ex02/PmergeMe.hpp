/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:47:13 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 20:11:06 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

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

	static std::vector<unsigned int>			_sequence;
	static int									_straggler;
	static std::vector< std::pair <int, int> >	_vecPairs;
	static std::deque< std::pair <int, int> >	_deqPairs;
	static std::vector<int>						_sortedVec;
	static std::deque<int>						_sortedDeq;
	static clock_t								_startTime;
	static clock_t								_vecEndTime;
	static clock_t								_deqEndTime;
	static bool									_DEBUG;

	static void				_saveStraggler();
	static void				_savePairs();
	static std::vector<int>	_returnJacobSeq(std::vector<int>& pend);
	static int				_jacobsthal(int index);
	static void				_displayTiming(const t_type& type);
	static double 			_ElapsedTime(clock_t endTime);

	template < typename Container >
	static void	_displaySequence(const std::string& desc, const Container& seq);

	template < typename Container >
	static void	_sort(Container& cont, const t_type type);

	template < typename Container >
	static void	_mergeSort(Container& cont);

	template < typename Container >
	static void	_createSequence(Container& cont, const t_type& type);

	template < typename Container >
	static void	_insertItem(Container& sequence, const int& item);

	template < typename Container >
	static void	_assignArray(Container& sequence, const t_type& type);

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

	/* Debugging templates */
	template <typename Container >
	static void	_displayPairArr(const std::string& desc, const Container& cont);

	template < typename Container >
	static void	_displayArr(const std::string& desc, const Container& cont);
};

#include "PmergeMe.tpp"
#include "debug.tpp"

#endif
