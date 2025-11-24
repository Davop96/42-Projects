/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:36:21 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/30 10:54:59 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void	bob_rundown(void)
{
	ScavTrap	bob("Bob");
	bob.guardGate();
	bob.attack("a tree");
	bob.guardGate();
	bob.attack("a tree");
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}
