/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:49 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:50:55 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();
    const WrongCat      *c = new WrongCat();

	std::cout << "-------------------------------------\n";

	meta->makeSound();
	j->makeSound();
	i->makeSound();
	k->makeSound();
    c->makeSound();

	std::cout << "-------------------------------------\n";
	
	delete meta;
	delete j;
	delete i;
	delete k;
    delete c;
}