/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:45:54 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/02 17:38:56 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

Base * generate(void)
{
	int	randomNumber = rand() % 3;

	switch (randomNumber)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (p == nullptr)
	{
		std::cout << "NULL pointer" << std::endl;
	}
	else if (dynamic_cast<A*>(p))
	{
		std::cout << "Clase A pointer" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "Clase B pointer" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "Clase C pointer" << std::endl;
	}
}

void identify(Base& p)
{
	identify(&p);
}

int	main( void )
{
	std::srand(std::time(0));

	Base *a = generate();
	identify(*a);
	identify(a);
	std::cout << std::endl;
	Base *b = generate();
	identify(*b);
	identify(b);
	std::cout << std::endl;
	Base *c = generate();
	identify(*c);
	identify(c);
	std::cout << std::endl;
	Base *d = generate();
	identify(*d);
	identify(d);
	std::cout << std::endl;
		

	Base *f = NULL;
	identify(f);
	identify(*f);
	delete	a;
	delete	b;
	delete	c;
	delete	d;
	return ( 0 );
}
