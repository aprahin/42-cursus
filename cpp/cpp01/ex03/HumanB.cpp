/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:34:19 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 23:26:14 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) 
{
	std::cout << _GREY << _DIM << "Constructor HumanB called for " <<
	_GREEN << this->_name << _END << std::endl;	
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << _GREY << _DIM << "Destructor HumanB called for " <<
	_RED << this->_name;
	if (this->_weapon != NULL)
	{
		std::cout << _GREY << " with weapon of type " <<
		_RED << (this->_weapon)->getType() << _END << std::endl;
	}
	else
		std::cout << _END << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	if (this->_weapon != NULL)
	{
		std::cout << _YELLOW << this->_name << _WHITE <<
		" attacks with their " << _YELLOW << (this->_weapon)->getType() <<
		_END << std::endl;
	}
	else
	{
		std::cout << _YELLOW << this->_name << _WHITE <<
		" tried to attack, but has no weapon!" << _END << std::endl;
	}
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}