/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:30:15 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:43:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : virtual public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &src);
		Dog &operator=(Dog const &src);
		virtual ~Dog();
		void buildDogIdeas (std::string const &idea, int const i);
		void getDogIdeas (int const index);
		void makeSound() const;
		Brain *getBrain(void) const
		{
			return (this->_brain);
		};
};