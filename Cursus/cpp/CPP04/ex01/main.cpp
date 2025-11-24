/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:30:26 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:44:01 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 4

int main()
{
	{
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
 
  std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		dogA->getBrain()->setIdea("First idea", 0);

		Dog *dogB = new Dog(*dogA);

		std::cout << "dogA idea: " << dogA->getBrain()->getIdea(0) << std::endl;
		std::cout << "dogB idea: " << dogB->getBrain()->getIdea(0) << std::endl;

		dogB->getBrain()->setIdea("Changed idea", 0);

		std::cout << "After changing dogB's idea:" << std::endl;
		std::cout << "dogA idea: " << dogA->getBrain()->getIdea(0) << std::endl;
		std::cout << "dogB idea: " << dogB->getBrain()->getIdea(0) << std::endl;

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;
		dogB->getBrain()->setIdea("Treats!", 0);

		*dogA = *dogB;

		std::cout << "dogA idea: " << dogA->getBrain()->getIdea(0) << std::endl;
		std::cout << "dogB idea: " << dogB->getBrain()->getIdea(0) << std::endl;

		dogA->getBrain()->setIdea("Walk!", 0);

		std::cout << "After changing dogA's idea:" << std::endl;
		std::cout << "dogA idea: " << dogA->getBrain()->getIdea(0) << std::endl;
		std::cout << "dogB idea: " << dogB->getBrain()->getIdea(0) << std::endl;

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		catA->getBrain()->setIdea("Nap time", 0);

		Cat *catB = new Cat(*catA);

		std::cout << "catA idea: " << catA->getBrain()->getIdea(0) << std::endl;
		std::cout << "catB idea: " << catB->getBrain()->getIdea(0) << std::endl;

		catB->getBrain()->setIdea("Play time", 0);

		std::cout << "After changing catB's idea:" << std::endl;
		std::cout << "catA idea: " << catA->getBrain()->getIdea(0) << std::endl;
		std::cout << "catB idea: " << catB->getBrain()->getIdea(0) << std::endl;

		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;
		catB->getBrain()->setIdea("Eat!", 0);

		*catA = *catB;

		std::cout << "catA idea: " << catA->getBrain()->getIdea(0) << std::endl;
		std::cout << "catB idea: " << catB->getBrain()->getIdea(0) << std::endl;

		catA->getBrain()->setIdea("Jump!", 0);

		std::cout << "After changing catA's idea:" << std::endl;
		std::cout << "catA idea: " << catA->getBrain()->getIdea(0) << std::endl;
		std::cout << "catB idea: " << catB->getBrain()->getIdea(0) << std::endl;

		delete catA;
		delete catB;
	}
	return (0);
}
