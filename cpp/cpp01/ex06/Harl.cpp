/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:47:29 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 19:40:34 by aprahin          ###   ########.fr       */
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
	int	level_nbr;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (level_nbr = 0; level_nbr < 4; level_nbr++)
	{
		if (level == levels[level_nbr])
			break ;
	}
	
	switch (level_nbr)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
	return;
}

void	Harl::debug(void)
{
	std::cout << _GREEN << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-\
cheese-triple-pickle-special-ketchup burger. I really do!\n" << _END << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << _BLUE << "[ INFO ]\nI cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! If you did, I woudln't be asking \
for more!\n" << _END << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << _YELLOW << "[ WARNING ]\nI think I deserve to have some extra bacon for free. \
I've been coming for years whereas you started working here since last month.\n"
	<< _END << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << _RED << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n"
	<< _END << std::endl;
	return ;
}
