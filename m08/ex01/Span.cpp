/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:37:39 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/03 18:45:44 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Span::Span() : _maxSize(0) {};
Span::Span(unsigned int N) : _maxSize(N) {}
Span::Span(const Span& copy) { *this = copy; }
Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_nums = rhs._nums;
	}
	return *this;
}
Span::~Span() {}

/*--- MEMBER FUNCTIONS -------------------------------------------------------*/

void	Span::addNumber(int num)
{
	_checkFull();
	_nums.push_back(num);
}

void	Span::addMany(
	std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	while (begin != end) {
		_checkFull();
		_nums.push_back(*begin);
		begin++;
	}
}

/* return the shortest span between adjacent numbers */
unsigned int	Span::shortestSpan()
{
	_checkNoSpan();
	std::vector<int> spans(_absSpan(_nums));
	return *std::min_element(spans.begin(), spans.end());
}

unsigned int	Span::longestSpan()
{
	_checkNoSpan();
	std::vector<int> spans(_absSpan(_nums));
	return *std::max_element(spans.begin(), spans.end());
}

void	Span::_checkFull()
{
	if (_nums.size() == _maxSize)
		throw FullStorageException();
}

void	Span::_checkNoSpan()
{
	if (_nums.size() < 2)
		throw NoSpanException();
}

/* Return a vector with the absolute differences of its adjacent values */
std::vector<int>	Span::_absSpan(std::vector<int> vec)
{
	std::vector<int>	spans(vec.size(), 0);

	std::adjacent_difference(vec.begin(), vec.end(), spans.begin());
	spans.erase(spans.begin());
	for (std::vector<int>::iterator it = spans.begin(); it != spans.end(); ++it)
		*it = std::abs(*it);
	return spans;
}

/*--- ACCESSORS --------------------------------------------------------------*/

unsigned int		Span::getMaxSize() const { return _maxSize; }
unsigned int		Span::getSize() const { return _nums.size(); }
std::vector<int>	Span::getNums() const { return _nums; }

/*--- EXCEPTIONS -------------------------------------------------------------*/

const char*	Span::FullStorageException::what() const throw() {
	return "Maximum number of integers reached";
}

const char*	Span::NoSpanException::what() const throw() {
	return "No span can be found";
}

/*--- INSERTION OPERATOR -----------------------------------------------------*/

std::ostream& operator<<(std::ostream& os, const Span& rhs)
{
	std::vector<int>	vec = rhs.getNums();
	os << "Max size: " << rhs.getMaxSize()
		<< " Current size: " << rhs.getSize()
		<< " Vector: " << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		os << vec[i] << " ";
	return os;
}
