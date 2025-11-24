/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:37:03 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/30 10:58:01 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


void	bob_rundown(void)
{
	FragTrap	bob("Bob");
	bob.highFivesGuys();
	bob.takeDamage(50);
	bob.highFivesGuys();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}