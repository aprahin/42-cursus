/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:55:08 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 10:35:21 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cerr << _GREY << _DIM << "Default MateriaSource constructor called"
	<< _END << std::endl;
	for (int i = 0; i < 4; i++)
		(this->_materias)[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cerr << _GREY << _DIM << "MateriaSource copy constructor called"
	<< _END << std::endl;
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

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	std::cerr << _GREY << _DIM << "MateriaSource assignment operator called"
	<< _END << std::endl;
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

MateriaSource::~MateriaSource(void)
{
	std::cerr << _GREY << _DIM << "Default MateriaSource destructor called"
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

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_materias)[i] == NULL)
		{
			(this->_materias)[i] = m->clone();
			return ;
		}
	}
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_materias)[i] != NULL && (this->_materias)[i]->getType() == type)
		{
			return ((this->_materias)[i]->clone());
		}
	}
	return (NULL);
}
