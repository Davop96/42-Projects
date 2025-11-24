/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:26:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:48:40 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	this->_type = copy._type;
	std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void WrongCat::makeSound(void)const
{
	std::cout << "Wuau Wuau" << std::endl;
}