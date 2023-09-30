/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:41:39 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/30 20:25:13 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter& scalarconverter);
		bool	isChar(std::string scalar);
		bool	isInt(std::string scalar);
		bool	isFloat(std::string scalar);
		bool	isDouble(std::string scalar);
		int		checkType(std::string scalar);
		bool	parseInput(std::string scalar);

	public:
		static void	convert(std::string scalar);
};

#endif
