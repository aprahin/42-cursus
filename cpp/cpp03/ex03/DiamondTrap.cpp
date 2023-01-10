/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:36:35 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 18:36:35 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cerr << _GREY << _DIM << "Default DiamondTrap constructor called"
	<< _END << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cerr << _GREY << _DIM << "Copy DiamondTrap constructor called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cerr << _GREY << _DIM << "DiamondTrap assignment operator called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cerr
	<< _YELLOW << "DiamondTrap" << _END << _GREY << _DIM << " destructor called"
	<< _END << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cerr << _GREY << _DIM << "Named " << _END
	<< _YELLOW << "DiamondTrap" << _END << _GREY << _DIM << " constructor called for "
	<< _YELLOW << name
	<< _END << std::endl;
	this->_name = name;
	this->FragTrap::_hp = 100;
	this->ScavTrap::_ep = 50;
	this->FragTrap::_dmg = 30;
	this->ClapTrap::_name = name + "_clap_name";
	return ;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << _WHITE << "My name is " << _GREEN << this->_name
	<< _WHITE << " and my ClapTrap name is " << _GREEN << this->ClapTrap::_name
	<< _END << std::endl;
	return ; 
}
