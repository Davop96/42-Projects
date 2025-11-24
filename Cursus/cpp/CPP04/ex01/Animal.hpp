/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:29:17 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:43:29 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"

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
		virtual Brain *getBrain() const = 0;
};
