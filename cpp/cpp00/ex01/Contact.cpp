/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:46:15 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 13:17:56 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << _GREY << _DIM << "Contact constructor called" << _END << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << _GREY << _DIM << "Contact destructor called" << _END << std::endl;
	return ;
}

void	Contact::setInfo(
	std::string	first_name,
	std::string	last_name,
	std::string	nickname,
	std::string	phone_number,
	std::string	secret
)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_secret = secret;
	return ;
}

void	Contact::printShortInfo(int	index) const
{
	std::string	infos[3] = {
		_first_name,
		_last_name,
		_nickname
	};
	size_t		width = 10;

	std::cout << std::setw(width) << std::right << index << "|";
	for (int i = 0; i < 3; i++)
	{
		if (infos[i].length() > width)
		{
			std::cout <<
			std::setw(width) <<
			std::right <<
			infos[i].substr(0, 9) + ".";
		}
		else
		{
			std::cout <<
			std::setw(width) <<
			std::right <<
			infos[i];
		}
		if (i < 2)
			std::cout << "|";
	}
	std::cout << std::endl;
	return ;
}

void	Contact::printLongInfo(void) const
{
	std::cout <<
	"First name: " <<
	this->_first_name <<
	std::endl <<	
	"Last name: " <<
	this->_last_name <<
	std::endl <<
	"Nickname: " <<
	this->_nickname <<
	std::endl <<
	"Phone number: " <<
	this->_phone_number <<
	std::endl <<
	"Darkest secret: " <<
	this->_secret <<
	std::endl;
	return ;
}