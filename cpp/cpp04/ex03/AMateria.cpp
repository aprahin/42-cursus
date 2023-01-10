/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:02:03 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:02:03 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cerr << _GREY << _DIM << "Default AMateria constructor called"
	<< _END << std::endl;
	this->type = "default";
	return ;
}

AMateria::AMateria(AMateria const &other)
{
	std::cerr << _GREY << _DIM << "AMateria copy constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	std::cerr << _GREY << _DIM << "AMateria assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cerr << _GREY << _DIM << "Default AMateria destructor called"
	<< _END << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type)
{
	std::cerr << _GREY << _DIM << "Typed AMateria constructor called with type "
	<< _END << _YELLOW << type << _END << std::endl;
	this->type = type;
	return ;
}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << _PURPLE << "* default dances over " << _RED
	<< target.getName() << _PURPLE << " *" << _END << std::endl;
	return ;
}