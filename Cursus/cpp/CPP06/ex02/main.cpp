/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 21:23:23 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/08/05 12:30:32 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base    *generate(void)
{
	switch (int success = rand() % 3)
	{
		case 0: 
			return (new A());
		case 1: 
			return (new B());
		case 2: 
			return (new C());
		default: return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << DEFAULT <<"The object is of type " << CYAN << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << DEFAULT <<"The object is of type " << CYAN << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << DEFAULT <<"The object is of type " << CYAN << "C" << std::endl;
	else
		std::cout << YELLOW << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << DEFAULT <<"The object is of type " << BLUE << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << DEFAULT <<"The object is of type " << BLUE << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << DEFAULT <<"The object is of type " << BLUE << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << CYAN << "Unknown type" << std::endl;
			}
			
		}	
	}
}

int main(void)
{
	srand((unsigned)time(NULL));
	Base *p;
	for (int i = 0; i < 5; i++) {
		std::cout << BROWN << i + 1 << ":" << std::endl;
		p = generate(); identify(p); identify(*p);
		delete p; std::cout << std::endl;
	}
	return 0;
}