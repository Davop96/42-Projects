/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:33:57 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:42:46 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 4

int main()
{
	{
		//Animal *a = new Animal();
		
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i < N_ANIMALS / 2)
				lotsOfAnimals[i] = new Dog();
			else
				lotsOfAnimals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		const int dogId = 0;
		const int catId = N_ANIMALS / 2;
		const Animal *dog = lotsOfAnimals[dogId];
		const Animal *cat = lotsOfAnimals[catId];

		std::cout << "First animal type: " << dog->getType() << std::endl;
		std::cout << "Second animal type: " << cat->getType() << std::endl << std::endl;

		std::cout << "Dog's original thought is \"" << dog->getBrain()->getIdea(0) << "\"" << std::endl;
		std::cout << "Cat's original thought is \"" << cat->getBrain()->getIdea(0) << "\"" << std::endl << std::endl;

		dog->getBrain()->setIdea("I have to bite the postman", 0);
		cat->getBrain()->setIdea("I have to hunt that mouse", 0);

		std::cout << "Dog's new thought is \"" << dog->getBrain()->getIdea(0) << "\"" << std::endl;
		std::cout << "Cat's new thought is \"" << cat->getBrain()->getIdea(0) << "\"" << std::endl << std::endl;

		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
}