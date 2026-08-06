/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 21:10:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/08/05 11:20:52 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	std::cout << std::endl;
	for (int i = 1; argv[i]; i++)
	{
		std::cout << CYAN << "[ARGV] -> " << RESET << argv[i] << std::endl;
		try {
			ScalarConverter::convert(argv[i]);}
		catch (const std::runtime_error &e){
			std::cerr << CYAN << "Error: " << e.what() << RESET << std::endl;}
		if ( i < argc - 1)
			std::cout << std::endl << CYAN << "---------------------------------------------------------------------" << std::endl << std::endl;
	}
	std::cout << std::endl;
	return (0);
}