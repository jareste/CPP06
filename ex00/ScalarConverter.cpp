/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:41:43 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 20:38:53 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter){
	(void) scalarconverter;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& scalarconverter){
	(void) scalarconverter;
	return (*this);
}

bool	ScalarConverter::isChar(std::string scalar)
{
	std::cout << "char" << std::endl;

	if ((int)scalar.length() == 3 && scalar[0] == '\'' && scalar[2] == '\'')
		if (std::isprint(scalar[1]))
			return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string scalar)
{
	std::cout << "int" << std::endl;
	for (int i = 0; i < (int)scalar.length(); i++)
		if (scalar[i] == '.' && !std::isdigit(scalar[i]))
			return (false);
	return (true);
}

bool	ScalarConverter::isFloat(std::string scalar)		
{
	bool	dot = false;
	std::cout << "float" << std::endl;

	for (int i = 0; i < (int)scalar.length(); i++)
		if (!std::isdigit(scalar[i]))
		{
			if (scalar[i] == '.' && dot == false)
				dot = true;
			else if (scalar[i] == '.' && dot == true)
				return (false); //aqui puedo tirar un error incluso
			if (i == (int)scalar.length() - 1 && scalar[i] == 'f')
				return (true);
		}
	return (false);
}

bool	ScalarConverter::isDouble(std::string scalar)
{
	bool	dot = false;
	std::cout << "double" << std::endl;

	for (int i = 0; i < (int)scalar.length(); i++)
	{
		if (scalar[i] == '.' && dot == false)
			dot = true;
		else if (scalar[i] == '.' && dot == true)
			return (false); //aqui puedo tirar un error incluso
	}
	return (true);
}

int		ScalarConverter::checkType(std::string scalar)
{
	bool	(ScalarConverter::*whichType[4])(std::string scalar) = 
	{&ScalarConverter::isChar, \
	 &ScalarConverter::isInt , \
	 &ScalarConverter::isFloat , \
	 &ScalarConverter::isDouble };

	for (int i = 0; i <  5; i++)
	{
		if (i == 4)
			return (4);
		if ((this->*whichType[i])(scalar) == true)
			return (i);
	}
	return (0);
}

bool	ScalarConverter::parseInput(std::string scalar)
{
	bool			dot = false;
	unsigned int	quote = 0;

	if (isChar(scalar))
		return (true);//si es char es valid input
	for (int i = 0; i < (int)scalar.length(); i++)
	{
		if (scalar[i] == '.' && dot == false)
			dot = true;
		else if (scalar[i] == '.' && dot == true)
			throw std::logic_error("Parsing error, double dot.");
		else if (scalar[i] == '\'')
		{
			if (++quote >= 3)
				throw std::logic_error("Parsing error, quote not closed or more than 2 quotes.");
		}
		else if (!std::isdigit(scalar[i]))
				throw std::logic_error("Parsing error, invalid digit.");
	}
	if (quote != 2)
		throw std::logic_error("Parsing error, quote not closed or more than 2 quotes.");
	return (true);
}

void	ScalarConverter::convert(std::string scalar)
{
	ScalarConverter aux;
	// std::cout << 
	aux.parseInput(scalar);
	 // << std::endl;
}


