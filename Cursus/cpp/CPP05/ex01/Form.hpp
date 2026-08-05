/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:41:19 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 10:36:34 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		Form();
		Form(std::string name, int const signgrade, int const executegrade);
		Form(Form const &copy);
		~Form();

		Form const &operator=(Form const &copy);

		std::string const	&getName() const;
		bool				getIsSigned() const;
		int const			&getSignGrade() const;
		int const			&getExecGrade() const;

		void				beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream	&operator<<(std::ostream &output, Form const &form);