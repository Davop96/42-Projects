/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:33:38 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:41:53 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(Cat const &src);
		Cat &operator=(Cat const &src);
		virtual ~Cat();
		void buildCatIdeas (std::string const &idea, int const i);
		void getCatIdeas (int const index);
		void makeSound() const;
		Brain *getBrain(void) const
		{
			return (this->_brain);
		};
};