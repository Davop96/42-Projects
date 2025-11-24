/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:33:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/30 10:53:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	bob_rundown(void)
{
	ClapTrap	bob("Bob");
	bob.attack("a tree");
	bob.takeDamage(5);
	bob.attack("another tree");
	bob.beRepaired(5);
	bob.attack("a third tree");
	bob.attack("a fourth tree");
	bob.attack("a fifth tree");
	bob.attack("a sixth tree");
	bob.attack("a seventh tree");
	bob.attack("an eighth tree");
	bob.attack("a ninth tree");
	bob.attack("a tenth tree");
	bob.takeDamage(10);
	bob.attack("an eleventh tree");
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Without HP: Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}
