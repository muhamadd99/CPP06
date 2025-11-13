/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:19:48 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/13 14:40:28 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base	* generate(void)
{
	int	random = std::rand() % 3;
	switch(random)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}

int	main()
{
	std::cout << "=== PTR TESTING ===" << std::endl;
	//seed
	Base*	ptr1 = generate();
	Base*	ptr2 = generate();
	Base*	ptr3 = generate();

	identify(ptr1);
	identify(ptr2);
	identify(ptr3);

	std::cout << "\n=== REF TESTING ===" << std::endl;
	Base&	ref1 = *ptr1;
	Base&	ref2 = *ptr2;
	Base&	ref3 = *ptr3;

	identify(ref1);
	identify(ref2);
	identify(ref3);

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return (0);
}
