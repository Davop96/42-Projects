/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:17 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:46:43 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	this->_type = copy._type;
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Default Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void Cat::makeSound(void)const
{
	std::cout << "Miau Miau" << std::endl;
}