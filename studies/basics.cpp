/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:42:54 by viferrei          #+#    #+#             */
/*   Updated: 2023/04/11 19:21:22 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace	std;

void	input_output_stream() {
	int		num;
	string	str;

	cout << "Hello world !" << endl;
	cout << "Enter an integer and a string, respectively:" << endl;
	cin >> num >> str;
	cout << "You entered " << num << " and " << str << endl;
}

void	parametric_manipulators() {

}

int main() {
	// input_output_stream();
	parametric_manipulators();
}
