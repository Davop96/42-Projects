/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:46:55 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	this->_type = copy._type;
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Default Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void Dog::makeSound(void)const
{
	std::cout << "Wuau Wuau" << std::endl;
}