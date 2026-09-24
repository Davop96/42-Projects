/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:07:42 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/23 12:57:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void printException(const std::exception &error)
{
	std::cout << error.what() << std::endl;
}

int main(void)
{
	std::cout << "----------------------" << std::endl;
	std::cout << "|||   NUMBER TEST ||||" << std::endl;
	std::cout << "----------------------" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "|||   ARRAY  TEST ||||" << std::endl;
	std::cout << "----------------------" << std::endl;
		Span string(5);
		string.addNumber(sp.getArray()->begin(), sp.getArray()->end());
		std::cout << string.shortestSpan() << std::endl;
		std::cout << string.longestSpan() << std::endl;
		std::cout << string << std::endl;
		try
		{
			Span tooSmall(4);
			tooSmall.addNumber(sp.getArray()->begin(), sp.getArray()->end());
		}
		catch (const std::exception &error)
		{
			printException(error);
		}
	std::cout << "----------------------" << std::endl;
	std::cout << "||| EXCEPTION TEST |||" << std::endl;
	std::cout << "----------------------" << std::endl;
		Span full(2);
		full.addNumber(1);
		full.addNumber(2);
		try
		{
			full.addNumber(3);
		}
		catch (const std::exception &error)
		{
			printException(error);
		}
		try
		{
			/*Span empty(2);
			empty.addNumber(10);
			empty.addNumber(52);
			std::cout << empty.shortestSpan() << std::endl;*/
			
			Span empty(0);
			empty.shortestSpan();
		}
		catch (const std::exception &error)
		{
			printException(error);
		}
		try
		{
			/*Span values(2);
    		values.addNumber(10);
    		values.addNumber(52);

    		std::cout << "Longest span: "
        		<< values.longestSpan() << std::endl;*/
			
			Span one(1);
			one.addNumber(42);
			one.longestSpan();
		}
		catch (const std::exception &error)
		{
			printException(error);
		}
		return 0;
}