/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:05:58 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/24 11:28:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

template<typename T>
void printResult(T &container, int value)
{
	typename T::iterator found = easyfind(container, value);
	typename T::iterator expected = std::find(container.begin(),
		container.end(), value);
	if (found == expected)
	{
		if (expected == container.end())
			std::cout << GREEN << "Value " << value << " not found"
				<< RESET << "\n";
		else
			std::cout << GREEN << "Found first occurrence of " << value
				<< RESET << "\n";
	}
	else
		std::cout << RED << "Unexpected result\n" << RESET;
}

int main (void)
{
	std::cout << YELLOW "\n---------------\n";
	std::cout << "||VECTOR TEST||\n";
	std::cout << "---------------\n\n" RESET;
	{
		std::vector<int> container;
		container.push_back(55);
		container.push_back(8);
		container.push_back(3);
		container.push_back(74);
		printResult(container, 55);
		printResult(container, 9);
		container.push_back(6);
		printResult(container, 4);
	}
	std::cout << YELLOW "\n-------------\n";
	std::cout << "||LIST TEST||\n";
	std::cout << "-------------\n\n" RESET;
	{
		std::list<int> container2;
		container2.push_back(55);
		container2.push_back(8);
		container2.push_back(3);
		container2.push_back(74);
		printResult(container2, 54);
		printResult(container2, 9);
	}
	return 0;
}