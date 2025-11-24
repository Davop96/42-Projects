/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:26:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:48:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat &operator=(WrongCat const &src);
		virtual ~WrongCat();
		void makeSound() const;
};