/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:07:05 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/28 12:27:13 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class	Array
{
public:
	Array()
	{

	};
	Array(unsigned int n);
	Array(const Array& copy);
	Array& operator=(const Array& rhs);

	T&	operator[](size-t i);
	size_t	size() const;

private:
	class	IndexOutOfBoundsException: public std::exception {
		public: virtual const char* what() const throw();
	}

};

#endif
