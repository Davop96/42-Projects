/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:41:24 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/29 12:00:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	/* Create a form with grade too high */
	{
		try
		{
			Form form0("A99", 0, 5);
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n --------------------- \n\n";

	/* Create form and sign it without exceptions */
	{
		try
		{
			Bureaucrat dani("Dani", 15);
			Form form("B50", 20, 45);
			std::cout << dani << std::endl;
			std::cout << form << std::endl;
			dani.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	/* Create form and try to sign it but the grade is not enough */
	{
		try
		{
			Bureaucrat jon("Jon", 35);
			Form form2("C_303", 20, 45);
			std::cout << jon << std::endl;
			std::cout << form2 << std::endl;
			jon.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}