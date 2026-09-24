/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:08:42 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/23 12:19:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Span
{
	private:
		int _size;
		std::vector<int> _array;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		void addNumber(int number);
		void addNumber(std::vector<int>::const_iterator begin, std::vector <int> ::const_iterator end);
		size_t shortestSpan();
		size_t longestSpan();
		const std::vector<int> *getArray() const {return (&_array);}
		Span const &operator=(Span const &copy);
		friend std::ostream &operator<<(std::ostream &output, const Span &src);

		class VectorIsFull : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class VectorIsEmpty : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotEnoughElements : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
