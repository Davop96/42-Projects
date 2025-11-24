/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:16:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/29 11:40:32 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "contact.hpp"

#define DEBUG 1

class PhoneBook
{
	private:

		Contact	_contacts[8];
		int		_size;

	public:

		void	init();
		int		get_size();
		void	add_contact();
		void	when_full_contacts();
		void	search_contact();
		void	pregen_contacts();
};

int		number_control(std::string str, int flag);

#endif