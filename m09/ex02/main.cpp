/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:51:49 by viferrei          #+#    #+#             */
/*   Updated: 2023/08/06 01:50:54 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	std::vector<std::string>	args(argv + 1, argv + argc);
	std::vector<unsigned int>	sequence;

	if (argc < 3)
		return PmergeMe::errorMsg("too few arguments");
	for (std::vector<std::string>::iterator it = args.begin();
		it != args.end();
		++it)
	{
		int					num;
		std::istringstream	iss(*it);

		if (!(iss >> num) || !iss.eof() || num < 0)
			return PmergeMe::errorMsg("not a sequence of unsigned integers");
		if (std::find(sequence.begin(), sequence.end(), num) != sequence.end())
			return PmergeMe::errorMsg("duplicate found");
		sequence.push_back(num);
	}
	PmergeMe::execute(sequence);
}
