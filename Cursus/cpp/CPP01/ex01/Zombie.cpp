/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:14:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 18:33:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << ": A has been created." << std::endl;
}

Zombie::Zombie(void)
{
	static int count = 1;

	this->_name = "(null)";
	std::cout << count++ << "º A zombie has been created." << std::endl;
}

Zombie::~Zombie()
{
	static int count = 1;

	std::cout << count++ << "º Zombie " << this->_name << " has been destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
