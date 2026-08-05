/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:41:13 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/30 10:37:40 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, int const signgrade, int const executegrade)
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

Form::Form(Form const &copy)
	: _name(copy._name),
	  _signed(copy._signed),
	  _gradeToSign(copy._gradeToSign),
	  _gradeToExecute(copy._gradeToExecute)
{
}

Form::~Form()
{
}

Form const &Form::operator=(Form const &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::string const &Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_signed);
}

int const &Form::getSignGrade() const
{
	return (this->_gradeToSign);
}

int const &Form::getExecGrade() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &output, Form const &form)
{
	output << form.getName()
		   << " form, signed: "
		   << (form.getIsSigned() ? "YES" : "NO")
		   << ", sign grade: "
		   << form.getSignGrade()
		   << ", exec grade: "
		   << form.getExecGrade();
	return (output);
}