/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:41:30 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 13:10:29 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include "colours.hpp"
#include <cstdlib>

void	enterInfo(std::string *dst)
{
	std::string	input;
	while (1)
	{
		std::getline(std::cin, input);
		if (input.length() == 0)
		{
			std::cout <<
			"Can't leave field empty!" <<
			std::endl <<
			"> ";
		}
		else
		{
			*dst = input;
			break ;
		}
	}
}

void	promptAdd(PhoneBook &pb_instance)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
	std::cout << "Enter a new contact info:" << std::endl;
	std::cout << "First name:" << std::endl << "> ";
	enterInfo(&first_name);
	std::cout << "Last name:" << std::endl << "> ";
	enterInfo(&last_name);
	std::cout << "Nickname:" << std::endl << "> ";
	enterInfo(&nickname);
	std::cout << "Phone number:" << std::endl << "> ";
	enterInfo(&phone_number);
	std::cout << "Secret:" << std::endl << "> ";
	enterInfo(&secret);	
	pb_instance.addContact(
		first_name,
		last_name,
		nickname,
		phone_number,
		secret);
	return ;
}

bool	isIndex(std::string str)
{
	if (str.length() == 0)
		return (false);
	for (int i = 0; i < (int) str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	if (std::atoi(str.c_str()) < 0 ||std ::atoi(str.c_str()) > 7)
		return (false);
	return (true);
}

void	promptSearch(PhoneBook &pb_instance)
{
	std::cout << "Here are the currently saved contacts:" << std::endl;
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	pb_instance.printContacts();
	std::cout << "Input an index (0-7) to display detailled infos:";
	std::cout << std::endl << "> ";
	while (1)
	{
		std::string	input;
		std::getline(std::cin, input);
		if (isIndex(input))
		{
			pb_instance.printOneContact(std::atoi(input.c_str()));
			break ;
		}
		std::cout << "Invalid input!" << std::endl << "> ";
	}
	return ;
}
int	main(void)
{
	PhoneBook	pb_instance;
	std::cout <<
	"Input an instruction (ALL CAPS!):" <<
	std::endl <<
	"ADD, SEARCH, EXIT" <<
	std::endl <<
	"> ";
	while (1)
	{
		std::string	input;
		std::getline(std::cin, input);
		if (input == "ADD")
			promptAdd(pb_instance);
		else if (input == "SEARCH")
			promptSearch(pb_instance);
		else if (input == "EXIT")
			break ;
		std::cout << "> ";
	}
	return (0);
}
