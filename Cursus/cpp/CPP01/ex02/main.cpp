/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:33:50 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 18:36:17 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string		&stringREF = string;

	std::cout << "memory string:\t\t" << &string << std::endl;
	std::cout << "memory stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory stringREF:\t" << &stringREF << std::endl;

	std::cout << "value string:\t\t" << string << std::endl;
	std::cout << "value stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value stringREF:\t" << stringREF << std::endl << std::endl;

	stringREF = "THIS IS BRAIN AGAIN";

	std::cout << "memory string:\t\t" << &string << std::endl;
	std::cout << "memory stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory stringREF:\t" << &stringREF << std::endl;

	std::cout << "value string:\t\t" << string << std::endl;
	std::cout << "value stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value stringREF:\t" << stringREF << std::endl << std::endl;

	*stringPTR = "BYE THIS IS BRAIN";

	std::cout << "memory string:\t\t" << &string << std::endl;
	std::cout << "memory stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory stringREF:\t" << &stringREF << std::endl;

	std::cout << "value string:\t\t" << string << std::endl;
	std::cout << "value stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value stringREF:\t" << stringREF << std::endl;

	return (0);
}
