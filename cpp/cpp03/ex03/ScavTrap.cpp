/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:36:35 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 18:36:35 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cerr << _GREY << _DIM << "Default ScavTrap constructor called"
	<< _END << std::endl;
	this->_name = "Default";
	this->_hp = 100;
	this->_ep = 50;
	this->_dmg = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
{
	std::cerr << _GREY << _DIM << "Copy ScavTrap constructor called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cerr << _GREY << _DIM << "ScavTrap assignment operator called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cerr
	<< _YELLOW << "ScavTrap" << _END << _GREY << _DIM << " destructor called"
	<< _END << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cerr << _GREY << _DIM << "Named " << _END
	<< _YELLOW << "ScavTrap" << _END << _GREY << _DIM << " constructor called for "
	<< _YELLOW << name
	<< _END << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_ep <= 0)
	{
		std::cout << _BLUE << this->_name << " tried to attack but has no energy points left!"
		<< _END << std::endl;
	}
	else if (this->_hp <= 0)
	{
		std::cout << _BLUE << this->_name << " tried to attack but has no health points left!"
		<< _END << std::endl;
	}
	else
	{
		std::cout << _GREEN << this->_name << _PURPLE << " scavenges his opponents organs " << _RED
		<< target << _WHITE << " with attack damage of " << _GREEN << this->_dmg
		<< _END << std::endl;
		std::cout << _BLUE << "(From " << this->_ep << " energy point(s) to " <<
		this->_ep - 1 << " energy point(s))" << _END << std::endl;
		this->_ep -= 1;
	}
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << _GREEN << this->_name << _WHITE << " activated " << _PURPLE
	<< "Guard Gate" << _WHITE << "." << _END << std::endl;
}