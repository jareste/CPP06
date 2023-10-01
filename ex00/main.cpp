/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:46:59 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/01 19:54:58 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	// try
	// {
		if (ac > 1)
			ScalarConverter::convert(av[1]);

		std::cout << std::endl;
		ScalarConverter::convert("'a'");
		std::cout << std::endl;
		ScalarConverter::convert("97");
		std::cout << std::endl;
		ScalarConverter::convert(".f");
		std::cout << std::endl;
		ScalarConverter::convert("97.06222211");
		std::cout << std::endl;
	// }
	// catch (std::logic_error &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
}


//+-inf
//".f"
//.
//''