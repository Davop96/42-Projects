/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:25 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:46:48 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : virtual public Animal
{
	public:
		Cat();
		Cat(Cat const &src);
		Cat &operator=(Cat const &src);
		virtual ~Cat();
		void makeSound() const;
};