/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:33:57 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/02 15:48:41 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iomanip>
# include <iostream>

typedef struct	s_Data
{
	char	c;
	int		i;
	int		*ptr;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &serializer);
		~Serializer();
		Serializer	&operator=(const Serializer& serializer);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);


};

#endif
