/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:24:28 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 17:24:28 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << _GREY << _DIM << "Default ClapTrap constructor called"
	<< _END << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cerr << _GREY << _DIM << "Copy ClapTrap constructor called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cerr << _GREY << _DIM << "ClapTrap assignment operator called"
	<< _END << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_dmg = other._dmg;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cerr
	<< _YELLOW << "ClapTrap" << _END << _GREY << _DIM << " destructor called"
	<< _END << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cerr << _GREY << _DIM << "Named " << _END
	<< _YELLOW << "ClapTrap" << _END << _GREY << _DIM << " constructor called for "
	<< _YELLOW << name
	<< _END << std::endl;
	return ;
}

ClapTrap::ClapTrap(
	std::string name,
	int hp,
	int ep,
	int dmg
) : _name(name), _hp(hp), _ep(ep), _dmg(dmg)
{
	std::cerr << _GREY << _DIM << "Multiple values " << _END
	<< _YELLOW << "ClapTrap" << _END << _GREY << _DIM << " constructor called with values "
	<< _END << _YELLOW << name << " " << hp << " " << ep << " " << dmg << _END << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
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
		std::cout << _GREEN << this->_name << _PURPLE << " claps way too loudly " << _RED
		<< target << _WHITE << " with attack damage of " << _GREEN << this->_dmg
		<< _END << std::endl;
		std::cout << _BLUE << "(From " << this->_ep << " energy point(s) to " <<
		this->_ep - 1 << " energy point(s))" << _END << std::endl;
		this->_ep -= 1;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << _GREEN << this->_name << _WHITE << " receives " << _RED << amount
	<< _WHITE << " points worth of damage!" << _END << std::endl;
	std::cout << _BLUE << "(From " << this->_hp << " health point(s) to " <<
	this->_hp - static_cast<int>(amount) << " health point(s))" << _END << std::endl;
	this->_hp -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep <= 0)
	{
		std::cout << _BLUE << this->_name << " tried to repair but has no energy points left!"
		<< _END << std::endl;
	}
	else if (this->_hp <= 0)
	{
		std::cout << _BLUE << this->_name << " tried to repair but has no health points left!"
		<< _END << std::endl;
	}
	else
	{
		std::cout << _GREEN << this->_name << _WHITE << " repairs " << _GREEN
		<< amount << _WHITE << " health point(s)."
		<< _END << std::endl;
		std::cout << _BLUE << "(From " << this->_ep << " energy point(s) to " <<
		this->_ep - 1 << " energy point(s))" << _END << std::endl;
		std::cout << _BLUE << "(From " << this->_hp << " health point(s) to " <<
		this->_hp + amount << " health point(s))" << _END << std::endl;
		this->_ep -= 1;
		this->_hp += amount;
	}
	return ;
}