/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:33:12 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/11/18 16:41:42 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain (void)
{
	std::cout << "Brain created by default." << std::endl;
}

Brain::Brain (Brain const &copy)
{
	*this = copy;
	std::cout << "Brain has been copied." << std::endl;
}

Brain::~Brain ()
{
	std::cout << "Brain has been destroyed." << std::endl;
}

Brain const &Brain::operator=(Brain const &copy)
{
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	std::cout << "Assignment operator for Brain called." << std::endl;
	return (*this);
}

std::string const Brain::getIdea(int const &index)const
{
	if (index >= 0 && index < 100)
	{
		return (this->_ideas[index]);        
	}
	return (this->_ideas[0]);
}

void Brain::setIdea(std::string const &idea, int const index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}