/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:36:52 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/30 11:00:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been assembled by default" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been assembled" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout << "FragTrap " << this->_name << " has been assembled by copy" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been disassembled" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
	ClapTrap::operator=(copy);
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is destroyed!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " has 0 energy points!" << std::endl;
		return ;
	}
	std::cout << this->_name << "stands up his hand and say \"High five, dude!\"" << std::endl;
}
