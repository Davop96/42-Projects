/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:16:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:46:30 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	this->_type = copy._type;
	std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void Animal::makeSound(void)const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->_type);
}