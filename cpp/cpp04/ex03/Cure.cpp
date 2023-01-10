/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:16:12 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:16:12 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	std::cerr << _GREY << _DIM << "Default Cure constructor called"
	<< _END << std::endl;
	this->type = "cure";
	return ;
}

Cure::Cure(Cure const &other) : AMateria()
{
	std::cerr << _GREY << _DIM << "Cure copy constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

Cure	&Cure::operator=(Cure const &other)
{
	std::cerr << _GREY << _DIM << "Cure assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

Cure::~Cure(void)
{
	std::cerr << _GREY << _DIM << "Default Cure destructor called"
	<< _END << std::endl;
	return ;
}

AMateria	*Cure::clone(void) const
{
	AMateria	*ret = new Cure(*this);
	return (ret);
}

void	Cure::use(ICharacter &target)
{
	std::cout << _PURPLE << "* heals " << _GREEN
	<< target.getName() << _PURPLE << "'s wounds *" << _END << std::endl;
	return ;
}