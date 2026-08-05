/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:19:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 11:00:40 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
	(void)copy;
}

Intern::~Intern()
{
}

Intern const &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	std::string const formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	FormCreator const formCreators[3] = {&Intern::createPresidentialPardonForm,
										&Intern::createRobotomyRequestForm,
										&Intern::createShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == form)
		{
			AForm *document = (this->*formCreators[i])(target);
			std::cout << "Intern creates form: " << form << " with target: " << document->getTarget() << std::endl;
			return (document);
		}
	}
	throw FormNoExist();
}

char const *Intern::FormNoExist::what() const throw()
{
	return("This form doesn't exist");
}