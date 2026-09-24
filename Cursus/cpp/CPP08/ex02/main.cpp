/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:10:44 by dbohoyo-          #+#    #+#             */
/*   Updated: 2026/09/24 11:31:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(20);
	//mstack.push(20);
	std::cout << "After push the stack:" << std::endl;
	std::cout << "  size: " << mstack.size() << std::endl;
	std::cout << "  top: " << mstack.top() << std::endl << std::endl;
	mstack.pop();
	std::cout << "After pop the stack:" << std::endl;
	std::cout << "  size: " << mstack.size() << std::endl;
	std::cout << "  top: " << mstack.top() << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Forward iteration (begin to end):" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl << "Reverse iteration (rbegin to rend):" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rte = mstack.rend();
	while (rit != rte)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl << "Copied to std::stack, top: " << s.top()
		<< std::endl;
	return 0;
}