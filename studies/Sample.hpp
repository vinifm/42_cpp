/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:37:59 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/10 16:23:39 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class Sample {
public:
	Sample();
	Sample(const Sample& copy);
	Sample& operator=(const Sample& rhs);
	~Sample();

private:
	int	_value;
};

#endif
