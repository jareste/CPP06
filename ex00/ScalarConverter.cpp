/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:41:43 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 23:59:48 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& scalarconverter){}

bool	ScalarConverter::isChar(std::string scalar)
{
	if (scalar.length() == 3 && scalar[0] == "'" && scalar[2] == "'")
		if (std::isprint(scalar[1]))
			return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string scalar)
{
	for (int i = 0; i < scalar.length(); i++)
		if (scalar.[i] == '.' && !std::isdigit(scalar[i]))
			return (false);
	return (true);
}

bool	ScalarConverter::isFloat(std::string scalar)		
{
	bool	dot = false;

	for (int i = 0; i < scalar.length(); i++)
		if (!std::isdigit(scalar[i]))
		{
			if (scalar[i] == '.' && dot == false)
				dot = true;
			else
				return (false); //aqui puedo tirar un error incluso
		}
}

bool	ScalarConverter::isDouble(std::string scalar)
{
	bool	dot = false;
}

void	ScalarConverter::convert(std::string scalar)
{


}


