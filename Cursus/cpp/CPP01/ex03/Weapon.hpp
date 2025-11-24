/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:43:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/30 18:43:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class	Weapon
{
	public:

		typedef	Weapon	t;

		Weapon( std::string weapon );
		~Weapon( void );

		const std::string&			getType( void );
		void				setType( std::string newType );

	private:
		std::string	_type;
};

#endif