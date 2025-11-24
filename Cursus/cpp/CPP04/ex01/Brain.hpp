/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:29:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:43:36 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(Brain const &copy);
		~Brain(void);
		Brain const &operator=(Brain const &copy);
		std::string const getIdea(int const &index) const;
		void    setIdea(std::string const &idea, int const index);
};