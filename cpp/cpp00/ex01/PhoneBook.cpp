/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:39:09 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 13:14:55 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _oldest_idx(0)
{
	std::cout << _GREY << _DIM << "PhoneBook constructor called" << _END << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << _GREY << _DIM << "PhoneBook destructor called" << _END << std::endl;
	return ;
}

void	PhoneBook::addContact(
	std::string	first_name,
	std::string	last_name,
	std::string	nickname,
	std::string	phone_number,
	std::string	secret
)
{
	if (this->_size < 8)
	{
		((this->_contacts)[this->_size]).setInfo(
			first_name,
			last_name,
			nickname,
			phone_number,
			secret
		);
		++(_size);
	}
	else
	{
		((this->_contacts)[this->_oldest_idx]).setInfo(
			first_name,
			last_name,
			nickname,
			phone_number,
			secret
		);	
		this->_oldest_idx = (this->_oldest_idx + 1) % 8;
	}
	return ;
}

void	PhoneBook::printContacts(void)
{
	for (int i = 0; i < 8; i++)
	{
		(this->_contacts)[(this->_oldest_idx + i) % 8].printShortInfo(i);
	}
	return ;
}

void	PhoneBook::printOneContact(int index)
{
	if ((this->_oldest_idx + index) % 8 >= this->_size)
	{
		std::cout <<
		"First name: N/A" <<
		std::endl <<
		"Last name: N/A" <<
		std::endl <<
		"Nickname: N/A" <<
		std::endl <<
		"Phone number: N/A" <<
		std::endl <<
		"Darkest secret: N/A" <<
		std::endl;	
	}
	else
		(this->_contacts)[(this->_oldest_idx + index) % 8].printLongInfo();
	return ;
}