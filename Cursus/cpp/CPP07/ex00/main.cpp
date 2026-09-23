/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 18:12:01 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/09 12:46:30 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <string>

int main(void)
{
	// Test swap, min and max with char values.
	std::cout << GREEN << "Char Test" << RESET << std::endl << std::endl;
	char cx = 'b';
	char cy = 'a';

	std::cout << "Prev X value: " << RED << cx << RESET << std::endl << "Prev Y value: " << RED << cy << RESET << std::endl;
	swap(cx, cy);
	std::cout << YELLOW << "<swap>" << RESET << std::endl;
	std::cout << "Prev X value: " << RED << cx << RESET << std::endl << "Prev Y value: " << RED << cy << RESET << std::endl;
	std::cout << "The min is: " << RED << min(cx, cy) << RESET << std::endl;
	std::cout << "The max is: " << RED << max(cx, cy) << RESET << std::endl << std::endl;
	
	// Test swap, min and max with int values.
	std::cout << GREEN << "Int Test" << RESET << std::endl << std::endl;
	int ix = 5;
	int iy = 10;

	std::cout << "Prev X value: " << RED << ix << RESET << std::endl << "Prev Y value: " << RED << iy << RESET << std::endl;
	swap(ix, iy);
	std::cout << YELLOW << "<swap>" RESET << std::endl;
	std::cout << "Prev X value: " << RED << ix << RESET << std::endl << "Prev Y value: " << RED << iy << RESET << std::endl;
	std::cout << "The min is: " << RED << min(ix, iy) << RESET << std::endl;
	std::cout << "The max is: " << RED << max(ix, iy) << RESET << std::endl << std::endl;

	// Test swap, min and max with double values.
	std::cout << GREEN << "Double Test" << RESET << std::endl << std::endl;
	double dx = 4.2;
	double dy = 42.0;

	std::cout << "Prev X value: " << RED << dx << RESET << std::endl << "Prev Y value: " << RED << dy << RESET << std::endl;
	swap(dx, dy);
	std::cout << YELLOW << "<swap>" << RESET << std::endl;
	std::cout << "Prev X value: " << RED << dx << RESET << std::endl << "Prev Y value: " << RED << dy << RESET << std::endl;
	std::cout << "The min is: " << RED << min(dx, dy) << RESET << std::endl;
	std::cout << "The max is: " << RED << max(dx, dy) << RESET << std::endl << std::endl;

	// Test swap, min and max with the complex type std::string.
	std::cout << GREEN << "String Test" << RESET << std::endl << std::endl;
	std::string sx = "chaine1";
	std::string sy = "chaine2";

	std::cout << "Prev X value: " << RED << sx << RESET << std::endl << "Prev Y value: " << RED << sy << RESET << std::endl;
	::swap(sx, sy);
	std::cout << YELLOW << "<swap>" << RESET << std::endl;
	std::cout << "Prev X value: " << RED << sx << RESET << std::endl << "Prev Y value: " << RED << sy << RESET << std::endl;
	std::cout << "The min is: " << RED << ::min(sx, sy) << RESET << std::endl;
	std::cout << "The max is: " << RED << ::max(sx, sy) << RESET << std::endl << std::endl;

	return 0;
}