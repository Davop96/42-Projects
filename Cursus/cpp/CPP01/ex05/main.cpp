/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:30:03 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/31 12:51:50 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(void)
{
    Harl manolo;

	manolo.complain("DEBUG");
	manolo.complain("INFO");
	manolo.complain("WARNING");
	manolo.complain("ERROR");
    return (0);
}