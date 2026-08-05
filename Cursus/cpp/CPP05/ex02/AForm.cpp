/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:06:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 10:44:05 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int const signgrade, int const executegrade)
	: _name(name), _signed(false),
	  _gradeToSign(signgrade), _gradeToExecute(executegrade)
{
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &copy)
	: _name(copy._name),
	  _signed(copy._signed),
	  _gradeToSign(copy._gradeToSign),
	  _gradeToExecute(copy._gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm const &AForm::operator=(AForm const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::string const &AForm::getName() const
{
	return (this->_name);
}

std::string const AForm::getIsSigned() const
{
	if (this->_signed)
		return ("YES");
	return ("NO");
}

int const &AForm::getSignGrade() const
{
	return (this->_gradeToSign);
}

int const &AForm::getExecGrade() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << this->_name << " has been signed by "
				  << bureaucrat.getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw FormNoSigned();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();

	std::cout << executor.getName()
			  << " executes form: "
			  << this->_name << std::endl;

	this->beExecuted(executor);
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

char const *AForm::FormNoSigned::what() const throw()
{
	return ("Form no signed");
}

std::ostream &operator<<(std::ostream &output, AForm const &form)
{
	output << form.getName()
		   << " form, signed: "
		   << form.getIsSigned()
		   << ", sign grade: "
		   << form.getSignGrade()
		   << ", exec grade: "
		   << form.getExecGrade();
	return (output);
}