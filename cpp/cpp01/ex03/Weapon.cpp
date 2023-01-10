/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:29:31 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 22:06:27 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "colours.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << _GREY << _DIM << "Weapon constructor called with type " <<
	_GREEN << this->_type << _END << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << _GREY << _DIM << "Weapon destructor called for type " <<
	_RED << this->_type << _END << std::endl;
}

const std::string&	Weapon::getType(void) const 
{
	return (this->_type);	
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}