/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:20:52 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 10:53:10 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("anyone") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm::AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm const &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return(*this);
}

std::string const &PresidentialPardonForm::getTarget() const
{
	return(this->_target);
}

void PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	(void)bureaucrat;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}