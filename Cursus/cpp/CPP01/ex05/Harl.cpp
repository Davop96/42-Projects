/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:29:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/31 12:52:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

void	Harl::complain( std::string level )
{
    void    (Harl::*ptr_level[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (options[i] == level)
            (this->*ptr_level[i])();
    }
}

void	Harl::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl << std::endl;
}

void	Harl::info( void )
{
    std::cout << GRAY << "[INFO]" << DEFAULT << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
    std::cout << YELLOW << "[WARNING]" << DEFAULT << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl << std::endl;
}

void	Harl::error( void )
{
    std::cout << RED << "[ERROR]" << DEFAULT << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}
