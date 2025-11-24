/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:39 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:46:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : virtual public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		Dog &operator=(Dog const &src);
		virtual ~Dog();
		void makeSound() const;
};