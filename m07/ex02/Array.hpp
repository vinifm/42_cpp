/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:07:05 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/28 17:20:36y viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
private:
	T*				_arr;
	unsigned int	_size;

public:
	Array<T>() : _arr(NULL), _size(0) {};

	Array<T>(unsigned int n) : _size(n)
	{
		if (_size)
			_arr = new T[n];
		for (size_t i = 0; i < _size; i++)
			_arr[i] = T();
	};

	Array<T>(const Array& copy) : _arr(NULL), _size(copy.size())
	{
		if (_size)
			_arr = new T[_size];
	};

	~Array<T>()
	{
		if (_arr)
			delete[] _arr;
	};

	Array<T>& operator=(const Array& rhs)
	{
		if (this != &rhs) {
			if (_arr)
				delete[] _arr;
			_size = rhs.size();
			_arr = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_arr[i] = rhs._arr[i];
		}
		return *this;
	};

	T&	operator[](size_t i)
	{
		if (i >= 0 && i < _size)
			return _arr[i];
		throw IndexOutOfBoundsException();
	};

	const T&	operator[](size_t i) const
	{
		if (i >= 0 && i < _size)
			return _arr[i];
		throw IndexOutOfBoundsException();
	};

	size_t	size() const { return _size; };

private:
	class	IndexOutOfBoundsException: public std::exception {
		public: virtual const char* what() const throw() {
			return "Index out of bounds!!!";
		}
	};
};

template <typename T>
void	displayArray(const Array<T>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

#endif
