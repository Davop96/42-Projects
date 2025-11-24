/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:14:29 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 18:19:41 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool isnumber(std::string str)
{
	if (!str[0])
		return false;
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

int main()
{
	std::string input;
	while (1)
	{
		std::cout << "Enter the number of zombies in the horde: " << std::endl;
		std::cin >> input;
		while ((isnumber(input) == false))
		{
			std::cout << "Invalid input. Please enter a unsigned and positive number." << std::endl;
			std::cin >> input;
		}
		break;
	}
	std::istringstream iss(input);
	int size;
	if (!(iss >> size))
	{
		std::cerr << "Invalid input: not a valid integer" << std::endl;
		return 1;
	}
	Zombie  *horde = ZombieHorde(size, "Walker");
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << "º ";
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
