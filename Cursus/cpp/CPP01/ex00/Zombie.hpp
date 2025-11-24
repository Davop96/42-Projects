/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:58:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 17:59:10 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>
# include <iostream>

class Zombie
{
public:

	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );

private:
	std::string name;
};

void	randomChump(std::string name);
Zombie 	*newZombie(std::string name);

#endif