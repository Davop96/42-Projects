/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:19:03 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/29 13:19:19 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();
		Bureaucrat const &operator=(Bureaucrat const &copy);
		std::string const getName() const;
		int getGrade() const;
		void Upgrade();
		void Downgrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, const Bureaucrat &bureaucrat);