/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:46:59 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 20:25:42 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	try
	{
		// ScalarConverter::convert("f");
		// // ScalarConverter::convert("0.0f");
		// ScalarConverter::convert("'a'");
		// ScalarConverter::convert("0");
		ScalarConverter::convert("'00.");
		// std::cout << k << std::endl;
	}
	catch (std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}