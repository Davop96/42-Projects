/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:06:28 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/29 11:40:32 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::init()
{
	this->_size = 0;
}

int main()
{
	std::string	command;
	PhoneBook	phonebook;

	phonebook.init();
	while (command != "EXIT")
	{
		if (std::cin.fail() || std::cin.eof())
		{
			if (DEBUG)
				std::cout << "EOF\n";
			return 1;
		}
		std::cin.clear();
		std::cout << "Welcome to your phonebook. Please, enter a command:\t-ADD- -SEARCH- -EXIT-" << std::endl;
		if (!std::getline(std::cin, command, '\n'))
			return 1;
		if (command == "ADD")
			phonebook.add_contact();
		if (command == "SEARCH")
			phonebook.search_contact();
		if (command == "PREGEN")
			phonebook.pregen_contacts();
	}
	return 0;
}