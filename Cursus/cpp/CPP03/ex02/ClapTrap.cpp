/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:36:40 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/30 11:00:52 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << this->_name <<" has been assembled by default" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << this->_name <<" has been assembled" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "Claptrap " << this->_name <<" has been assembled by copy" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->_name <<" has been disassembled" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is destroyed!" << std::endl;
		return ;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " has 0 energy points!" << std::endl;
		return ;
	}
	std::cout << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
	}
	if (this->_hitPoints == 0)
		std::cout << this->_name << " has been destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
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
	std::cout << this->_name << " has been repaired by " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	if (this->_hitPoints > 10)
	{
		this->_hitPoints = 10;
		std::cout << this->_name << " has 10 hit points!" << std::endl;
	}
	this->_energyPoints -= 1;
}
