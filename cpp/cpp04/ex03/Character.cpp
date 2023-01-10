/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:28:16 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:28:16 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cerr << _GREY << _DIM << "Default Character constructor called"
	<< _END << std::endl;
	this->_name = "default";
	for (int i = 0; i < 4; i++)
		(this->_materias)[i] = NULL;
	return ;
}

Character::Character(Character const &other)
{
	std::cerr << _GREY << _DIM << "Character copy constructor called"
	<< _END << std::endl;
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if ((other._materias)[i] == NULL)
		{
			(this->_materias)[i] = NULL;
		}
		else
		{
			(this->_materias)[i] = (other._materias)[i]->clone();
		}
	}
	return ;
}

Character	&Character::operator=(Character const &other)
{
	std::cerr << _GREY << _DIM << "Character assignment operator called"
	<< _END << std::endl;
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_materias)[i] != NULL)
		{
			delete (this->_materias)[i];
		}

		if ((other._materias)[i] == NULL)
		{
			(this->_materias)[i] = NULL;
		}
		else
		{
			(this->_materias)[i] = (other._materias)[i]->clone();
		}
	}
	return (*this);
}

Character::~Character(void)
{
	std::cerr << _GREY << _DIM << "Default Character destructor called"
	<< _END << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_materias)[i] != NULL)
		{
			delete (this->_materias)[i];
		}
	}
	return ;
}

Character::Character(std::string name)
{
	std::cerr << _GREY << _DIM << "Named Character constructor called for "
	<< _YELLOW << name << _END << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		(this->_materias)[i] = NULL;
	return ;
}
std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_materias)[i] == NULL)
		{
			(this->_materias)[i] = m;
			break ;
		}
	}
	return ;
}

void	Character::unequip(int idx)
{
	AMateria	*dropped_materia = NULL;

	dropped_materia = (this->_materias)[idx];
	(this->_materias)[idx] = NULL;

	if (dropped_materia != NULL)
	{
		std::cout << _WHITE << "A materia is on the ground!" << _END << std::endl;	
	}
	return ;
}

void	Character::use(int idx, ICharacter &target)
{
	if ((this->_materias)[idx] != NULL)
	{
		(this->_materias)[idx]->use(target);
	}
	return ;
}
