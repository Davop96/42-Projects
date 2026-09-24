/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:11:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/20 20:11:33 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <stack>

template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack <T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		MutantStack() {}
		MutantStack(const MutantStack &rhs)
		{
			*this = rhs;
		}
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &src)
		{
			std::stack<T, Container>::operator=(src);
			return (*this);
		}
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
};