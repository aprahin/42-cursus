/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:36:35 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 18:36:35 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cerr << _GREY << _DIM << "Default FragTrap constructor called"
	<< _END << std::endl;
	this->_name = "Default";
	this->_hp = 100;
	this->_ep = 100;
	this->_dmg = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	std::cerr << _GREY << _DIM << "Copy FragTrap constructor called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cerr << _GREY << _DIM << "FragTrap assignment operator called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cerr
	<< _YELLOW << "FragTrap" << _END << _GREY << _DIM << " destructor called"
	<< _END << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cerr << _GREY << _DIM << "Named " << _END
	<< _YELLOW << "FragTrap" << _END << _GREY << _DIM << " constructor called for "
	<< _YELLOW << name
	<< _END << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _GREEN << this->_name << _WHITE << " is asking for a " << _PURPLE
	<< "high five" << _WHITE << "." << _END << std::endl;
}