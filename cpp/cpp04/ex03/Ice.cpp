/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:16:12 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 17:16:12 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cerr << _GREY << _DIM << "Default Ice constructor called"
	<< _END << std::endl;
	this->type = "ice";
	return ;
}

Ice::Ice(Ice const &other) : AMateria()
{
	std::cerr << _GREY << _DIM << "Ice copy constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

Ice	&Ice::operator=(Ice const &other)
{
	std::cerr << _GREY << _DIM << "Ice assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

Ice::~Ice(void)
{
	std::cerr << _GREY << _DIM << "Default Ice destructor called"
	<< _END << std::endl;
	return ;
}

AMateria	*Ice::clone(void) const
{
	AMateria	*ret = new Ice(*this);
	return (ret);
}

void	Ice::use(ICharacter &target)
{
	std::cout << _PURPLE << "* shoots an ice bolt at " << _RED
	<< target.getName() << _PURPLE << " *" << _END << std::endl;
	return ;
}
