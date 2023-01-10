/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:43 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 20:06:42 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << _GREY << _DIM << "Default Zombie constructor called" << _END << std::endl;
	return ;
}

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

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << _GREEN << this->_name <<
	_WHITE << ": BraiiiiiiinnnzzzZ..." << _END << std::endl;
	return ;
}