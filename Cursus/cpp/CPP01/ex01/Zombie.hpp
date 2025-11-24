/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:14:53 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 18:14:56 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>
# include <sstream>
# include <iostream>
# include <cctype>


class Zombie
{

public:

	Zombie( std::string name );
	Zombie( void );
	~Zombie( void );

	void	announce( void );
	void	setName(std::string name);

private:
	std::string _name;

};

Zombie *ZombieHorde( int N, std::string name );

#endif