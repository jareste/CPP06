/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:45:54 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/02 15:53:13 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main( void )
{
	Data		*ptr;
	Data		*newPtr;
	uintptr_t	raw;
	int			number;

	number = 49;
	ptr = new Data;
	ptr->c = number;
	ptr->i = number;
	ptr->ptr = &number;
	std::cout << "[ BEFORE ] Data *ptr stats -> ptr: " << ptr \
				<< " && ptr->c: " << ptr->c \
				<< " && ptr->i: " << ptr->i \
				<< " && ptr->ptr: " << ptr->ptr \
				<< " && *( ptr->ptr ): " << *( ptr->ptr ) \
				<< std::endl;
	raw = Serializer::serialize( ptr );
	newPtr = Serializer::deserialize( raw );
	std::cout << "[ AFTER ] Data *newPtr stats -> ptr: " << newPtr \
				<< " && newPtr->c: " << newPtr->c \
				<< " && newPtr->i: " << newPtr->i \
				<< " && newPtr->ptr: " << newPtr->ptr \
				<< " && *( newPtr->ptr ): " << *( newPtr->ptr ) \
				<< std::endl;
	delete ptr;
	return ( 0 );
}
