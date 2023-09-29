/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:41:39 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/29 23:26:52 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter& scalarconverter);
	public:
		void	convert(std::string scalar);
};

#endif
