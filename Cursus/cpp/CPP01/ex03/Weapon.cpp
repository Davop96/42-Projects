/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:43:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/31 10:56:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ): _type(weapon)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void    Weapon::setType( std::string newType )
{
    this->_type = newType;
}

const std::string&	Weapon::getType( void )
{
    return (this->_type);
}