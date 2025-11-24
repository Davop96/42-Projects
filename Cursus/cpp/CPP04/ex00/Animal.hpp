/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:08 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:46:36 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
};


