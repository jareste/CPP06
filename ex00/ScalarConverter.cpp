/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:41:43 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/02 15:35:31 by jareste-         ###   ########.fr       */
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
	if ((int)scalar.length() == 3 && scalar[0] == '\'' && scalar[2] == '\'')
	{
		if (std::isprint(scalar[1]))
			return (true);
	}
	else if ((int)scalar.length() != 3 && scalar[0] == '\'')
		throw std::logic_error("Parsing error, invalid input.");
	return (false);
}

bool	ScalarConverter::isInt(std::string scalar)
{
	for (int i = 0; i < (int)scalar.length(); i++)
		if (scalar[i] == '.' && !std::isdigit(scalar[i]))
			return (false);
	return (true);
}

bool	ScalarConverter::isFloat(std::string scalar)		
{
	bool	dot = false;

	for (int i = 0; i < (int)scalar.length(); i++)
		if (!std::isdigit(scalar[i]))
		{
			if (scalar[i] == '.' && dot == false)
				dot = true;
			if (i == (int)scalar.length() - 1 && scalar[i] == 'f' && scalar.length() > 2)
				return (true);
		}
	return (false);
}

bool	ScalarConverter::isDouble(std::string scalar)
{
	bool	dot = false;

	for (int i = 0; i < (int)scalar.length(); i++)
	{
		if (!std::isdigit(scalar[i]) && scalar[i] != '.')
			return (false);
		if (scalar[i] == '.' && dot == false)
			dot = true;
		else if (scalar[i] == '.' && dot == true)
			return (false);
	}
	if (scalar.length() < 2)
		return (false);
	return (true);
}

int		ScalarConverter::checkType(std::string scalar)
{
	bool	(*whichType[4])(std::string scalar) = 
	{&ScalarConverter::isChar, \
	 &ScalarConverter::isInt , \
	 &ScalarConverter::isFloat , \
	 &ScalarConverter::isDouble };
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			return (4);
		if ((whichType[i])(scalar) == true)
			return (i + 1);
	}
	return (0); 
}

bool	ScalarConverter::parseInput(std::string scalar)
{
	bool			dot = false;
	unsigned int	quote = 0;

	try
	{
		if (scalar == "." || scalar == ".f" || scalar == "" || scalar == "-" || scalar == "-." || scalar == "-.f" )
			throw std::logic_error("Parsing error, invalid digit.");
		if (isChar(scalar))
			return (true);
		for (int i = 0; i < (int)scalar.length(); i++)
		{
			if (scalar[i] == '-' && i == 0)
				continue ;
			if (scalar[i] == '.' && dot == false)
				dot = true;
			else if (scalar[i] == '.' && dot == true)
				throw std::logic_error("Parsing error, double dot.");
			else if (scalar[i] == '\'')
			{
				if (++quote >= 3)
					throw std::logic_error("Parsing error, quote not closed or more than 2 quotes.");
			}
			else if (i == (int)scalar.length() - 1 && scalar[i] == 'f' && dot == true)
				return (true);
			else if (!std::isdigit(scalar[i]))
					throw std::logic_error("Parsing error, invalid digit.");
		}
		if (quote != 2 && quote != 0)
			throw std::logic_error("Parsing error, quote not closed or more than 2 quotes.");
	}
	catch (const std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}

void	ScalarConverter::writeChar(char c)
{
	std::cout << "Char: " << c << std::endl;
	int i = static_cast<int>(c);
	std::cout << "Int: " << i << std::endl;
	float f = static_cast<float>(c);
	std::cout << "Float: " << f << "f" << std::endl;
	double d = static_cast<double>(c);
	std::cout << "Double: " << d << std::endl;
}

void	ScalarConverter::writeInt(int i)
{
	char c = static_cast<char>(i);
	if (std::isprint(c) && (i < 127 && i > 0))
		std::cout << "Char: " << c << std::endl;
	else	
		std::cout << "Char: " << "Out of range" << std::endl;

	std::cout << "Int: " << i << std::endl;
	
	float f = static_cast<float>(i);
	if (i < FLT_MAX && i > -FLT_MAX)
		std::cout << "Float: " << f << "f" << std::endl;
	else
		std::cout << "Float: " << "Out of range" << std::endl;
	
	double d = static_cast<double>(i);
	std::cout << "Double: " << d << std::endl;
}

void	ScalarConverter::writeFloat(float f)
{
	char c = static_cast<char>(f);
	if (std::isprint(c) && (f < 127 && f > 0))
		std::cout << "Char: " << c << std::endl;
	else	
		std::cout << "Char: " << "Out of range" << std::endl;
	
	int i = static_cast<int>(f);
	if (f < INT_MAX && f > INT_MIN)
		std::cout << "Int: " << i << std::endl;
	else
		std::cout << "Int: " << "Out of range" << std::endl;

	std::cout << "Float: " << f << "f" << std::endl;
	
	double d = static_cast<double>(f);
	std::cout << "Double: " << d << std::endl;
}

void	ScalarConverter::writeDouble(double d)
{
	char c = static_cast<char>(d);
	if (std::isprint(c) && (d < 127 && d > 0))
		std::cout << "Char: " << c << std::endl;
	else
		std::cout << "Char: " << "Out of range" << std::endl;
	
	int i = static_cast<int>(d);
	if (d < INT_MAX && d > INT_MIN)
		std::cout << "Int: " << i << std::endl;
	else
		std::cout << "Int: " << "Out of range" << std::endl;
	
	float f = static_cast<float>(d);
	if (d < FLT_MAX && d > -FLT_MAX)
		std::cout << "Float: " << f << "f" << std::endl;
	else
		std::cout << "Float: " << "Out of range" << std::endl;
	
	std::cout << "Double: " << d << std::endl;
}

void	ScalarConverter::writeInfCase(std::string scalar)
{
	if (scalar == "-inf" || scalar == "+inf" || scalar == "nan")
	{
		std::cout << "Char: Out of range" << std::endl;
		std::cout << "Int: Out of range" << std::endl;
		std::cout << "Float: " << scalar << "f" << std::endl;
		std::cout << "Double: " << scalar << std::endl;
		}
	else
	{
		std::cout << "Char: Out of range" << std::endl;
		std::cout << "Int: Out of range" << std::endl;
		std::cout << "Float: " << scalar << std::endl;
		std::cout << "Double: " << scalar.substr(0, scalar.length() - 1) << std::endl;
	}
}

void	ScalarConverter::convert(std::string scalar)
{
	std::cout << std::fixed << std::setprecision(1);

	if (scalar == "-inf" || scalar == "-inff" || scalar == "+inf" || scalar == "+inff" || scalar == "nanf" || scalar == "nan")
		writeInfCase(scalar);
	else if (parseInput(scalar))
		try
		{
			switch (checkType(scalar))
			{
				case 1: 
				{
					char c = scalar[1];
					writeChar(c);
					break ;
				}
				case 2:	
				{
					int i = std::stoi(scalar);
					writeInt(i);
					break ;
				}
				case 3: 
				{
					float f = stof(scalar);
					writeFloat(f);
					break ;
				}
				case 4: 
				{
					double d = stod(scalar);
					writeDouble(d);
					break ;
				}
				default:
					std::cout << "switch default::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
					break ;	
			}
		}
		catch (const std::out_of_range &e)
		{
			std::cout << e.what() << std::endl;
		}
}


