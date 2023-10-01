/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:41:39 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/01 19:42:26 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter& scalarconverter);
		static bool	isChar(std::string scalar);
		static bool	isInt(std::string scalar);
		static bool	isFloat(std::string scalar);
		static bool	isDouble(std::string scalar);
		static int	checkType(std::string scalar);
		static bool	parseInput(std::string scalar);

		static void	writeChar(char c);
		static void	writeInt(int i);
 		static void	writeFloat(float f);
		static void	writeDouble(double d);
	public:
		static void	convert(std::string scalar);
};

#endif
