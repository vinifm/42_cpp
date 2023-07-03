/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:37:59 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/03 20:15:43 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample {
public:
	Sample();								// constructor
	Sample(const Sample& copy);				// copy constructor
	Sample& operator=(const Sample& assign);// copy assignment operator
	~Sample();								// destructor

	int	getValue() const;

private:
	int			value;
};

#endif
