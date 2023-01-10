/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:47:29 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 19:41:10 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdio>
Harl::Harl(void)
{
	std::cout << _GREY << _DIM << "Harl constructor called" << _END << std::endl;
	return ;	
}

Harl::~Harl(void)
{
	std::cout << _GREY << _DIM << "Harl destructor called" << _END << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "I can only complain if you input one of the following levels:";
	std::cout << std::endl << "DEBUG, INFO, WARNING, ERROR" << std::endl;
	return ;
}

void	Harl::debug(void)
{
	std::cout << _GREEN << "I love having extra bacon for my 7XL-double-\
cheese-triple-pickle-special-ketchup burger. I really do!" << _END << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << _BLUE << "I cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! If you did, I woudln't be asking \
for more!" << _END << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << _YELLOW << "I think I deserve to have some extra bacon for free. \
I've been coming for years whereas you started working here since last month."
	<< _END << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << _RED << "This is unacceptable! I want to speak to the manager now."
	<< _END << std::endl;
	return ;
}