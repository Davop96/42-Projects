/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:06:39 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 10:51:23 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int const signgrade, int const executegrade);
		AForm(AForm const &copy);
		virtual ~AForm();

		AForm const &operator=(AForm const &copy);

		std::string const	&getName() const;
		std::string const	getIsSigned() const;
		int const			&getSignGrade() const;
		int const			&getExecGrade() const;

		virtual void		beSigned(Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		beExecuted(Bureaucrat const &bureaucrat) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNoSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);