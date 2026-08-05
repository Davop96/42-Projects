/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:19:37 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 11:00:10 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	private:
		typedef AForm *(Intern::*FormCreator)(std::string const &target) const;

		AForm *createPresidentialPardonForm(std::string const &target) const;
		AForm *createRobotomyRequestForm(std::string const &target) const;
		AForm *createShrubberyCreationForm(std::string const &target) const;

	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();

		Intern const &operator=(Intern const &copy);

		AForm *makeForm(std::string const &form, std::string const &target);

		class FormNoExist : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};