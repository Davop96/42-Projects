/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 21:20:19 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/08/05 11:21:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void ) {
	{
		std::cout <<       " ======================================" << std::endl
				  << GREEN "             SERIALIZE TESTS           " DEFAULT << std::endl
				  <<       " ======================================" << std::endl << std::endl;

		Data data1;
		Data data2;

        data1.Something = 42;
		data2.Something = 1234;
		
		Data *data = &data1;
		std::cout << GREEN " Data" CYAN " has changed his pointer to " GREEN "Data 1" CYAN " and his address is:\t" CYAN << data << std::endl
				  << CYAN " Variable " CYAN "Something" CYAN " of " BLUE "Data" CYAN " is \t\t\t\t\t" GREEN << data->Something << DEFAULT << std::endl << std::endl;

        uintptr_t Serialized = Serializer::serialize(data);
		std::cout << GREEN " Data" CYAN " Serialized:\t" CYAN << Serialized << DEFAULT << std::endl << std::endl;

		data = &data2;
		std::cout << GREEN " Data" CYAN " has changed his pointer to " GREEN "Data 2" CYAN " and his address is:\t" YELLOW << data << std::endl
				  << CYAN " Variable " CYAN "Something" CYAN " of " BLUE "Data" CYAN " is \t\t\t\t\t" GREEN << data->Something << DEFAULT << std::endl << std::endl;

		data = Serializer::deserialize(Serialized);
		std::cout << GREEN " Data" CYAN " Des-Serialized:\t" CYAN << Serialized << DEFAULT << std::endl
				  << GREEN " Data" CYAN " has changed his pointer to the value Des-Serialized" << std::endl << std::endl;
		
		std::cout << GREEN " Data" CYAN " has his pointer now in the address:\t\t\t" CYAN << data << std::endl
				  << CYAN " Variable " CYAN "Something" CYAN " of " BLUE "Data" CYAN " is \t\t\t\t\t" GREEN << data->Something << DEFAULT << std::endl << std::endl;
	}
	std::cout << " =======================================" << std::endl << std::endl;
}