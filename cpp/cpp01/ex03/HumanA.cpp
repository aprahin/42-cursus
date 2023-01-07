/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:55:05 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 23:26:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include "colours.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << _GREY << _DIM << "Constructor HumanA called for " <<
	_GREEN << this->_name << _GREY << " with weapon of type " <<
	_GREEN << (this->_weapon).getType() << _END << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << _GREY << _DIM << "Destructor HumanA called for " <<
	_RED << this->_name << _GREY << " with weapon of type " <<
	_RED << (this->_weapon).getType() << _END << std::endl;
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << _YELLOW << this->_name << _WHITE <<
	" attacks with their " << _YELLOW << (this->_weapon).getType() <<
	_END << std::endl;
	return ;
}