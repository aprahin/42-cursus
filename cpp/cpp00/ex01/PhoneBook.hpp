/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:36:15 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 13:15:12 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include "colours.hpp"
# include <iostream>
# include <string>

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(
			std::string	first_name,
			std::string	last_name,
			std::string	nickname,
			std::string	phone_number,
			std::string	secret
		);
		void	printContacts(void);
		void	printOneContact(int index);
	private:
		Contact	_contacts[8];
		int		_size;
		int		_oldest_idx;
};

#endif