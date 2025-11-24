/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:15:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 18:30:19 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *ZombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{  
		std::ostringstream oss;
		oss << name << "-" << i + 1;
		horde[i].setName(oss.str());
	}
	return (horde);
}