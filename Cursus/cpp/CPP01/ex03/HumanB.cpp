/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:42:40 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/31 10:56:11 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_weapon = NULL;

    this->_name = name;
    std::cout << "HumanB " << this->_name << " created without weapon." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->_name << " destroyed." << std::endl;
}

void    HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << "HumanB " << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    else
        std::cout << "HumanB " << this->_name << " attacks with his bare hands." << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << "HumanB " << this->_name << " has equipped a " << this->_weapon->getType() << std::endl;
}
