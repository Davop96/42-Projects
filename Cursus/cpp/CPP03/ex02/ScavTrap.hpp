/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:37:16 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/30 11:01:11 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &copy);
		void guardGate();
		void getEnergyPoints();
	private:
		bool _gateKeeperMode;
};