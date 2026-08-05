/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 11:03:26 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/07/29 11:32:42 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	/* Throw exception when calling constructor with grade too high */
	{
		try
		{
			Bureaucrat dani("Dani", 0);
			std::cout << dani << std::endl;
		}
		catch (std::exception &e) 
		//This catch block is designed to catch any exception that is of type std::exception
		//or derived from std::exception, such as GradeTooHighException.
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Throw exception when calling constructor with grade too low */
	{
		try
		{
			Bureaucrat david("David", 151);
			std::cout << david << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Throw exeception when calling gradeUp */
	{	
		try 
		{
			Bureaucrat alex("Alex", 3);
			std::cout << alex << std::endl;
			alex.Upgrade();
			std::cout << alex << std::endl;
			alex.Upgrade();
			std::cout << alex << std::endl;
			alex.Upgrade();
			std::cout << alex << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Throw exeception when calling gradeDown */
	{	
		try 
		{
			Bureaucrat alan("Alan", 149);
			std::cout << alan << std::endl;
			alan.Downgrade();
			std::cout << alan << std::endl;
			alan.Downgrade();
			std::cout << alan << std::endl;
			alan.Downgrade();
			std::cout << alan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}