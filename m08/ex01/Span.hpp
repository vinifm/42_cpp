/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:36:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/04 16:35:28 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <numeric>	//adjacent_difference
#include <algorithm>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& rhs);
	~Span();

	void			addNumber(int num);
	void			addMany(
						std::vector<int>::iterator begin,
						std::vector<int>::iterator end
					);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	unsigned int		getMaxSize() const;
	unsigned int		getSize() const;
	std::vector<int>	getNums() const;

private:
	unsigned int		_maxSize;
	std::vector<int>	_nums;

	void				_checkFull();
	void				_checkNoSpan();
	std::vector<int>	_absSpan(std::vector<int> vec);

	class FullStorageException: public std::exception {
		public: virtual const char* what() const throw();
	};

	class NoSpanException: public std::exception {
		public: virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Span& rhs);

#endif
