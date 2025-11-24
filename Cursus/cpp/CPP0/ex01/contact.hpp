/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:05:51 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/07/28 19:06:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "phonebook.hpp"

class Contact
{
	public:

		void	add_first_name(std::string str);
		void	add_last_name(std::string str);
		void	add_nickname(std::string str);
		void	add_phone_number(std::string nbr);
		void	add_secret(std::string str);
		void	print_first_name_contact();
		void	print_last_name_contact();
		void	print_nickname_contact();
		void	print_phone_number_contact();
		void	print_secret_contact();
		void	print_contact();

	private:

		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif