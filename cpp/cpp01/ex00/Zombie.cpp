/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:43 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 19:01:05 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string	name) : _name(name)
{
	std::cout << _GREY << _DIM << "Zombie " <<
	_GREEN << this->_name <<
	_GREY << " constructor called" << _END << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _GREY << _DIM << "Zombie " <<
	_RED << this->_name << _GREY <<
	" destructor called" << _END << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << _GREEN << this->_name <<
	_WHITE << ": BraiiiiiiinnnzzzZ..." << _END << std::endl;
	return ;
}