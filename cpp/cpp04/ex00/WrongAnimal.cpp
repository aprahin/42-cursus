/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:31 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:14:31 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cerr << _GREY << _DIM << "Default WrongAnimal constructor called"
	<< _END << std::endl;
	this->type = "DefaultWrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cerr << _GREY << _DIM << "Copy WrongAnimal constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cerr << _GREY << _DIM << "WrongAnimal assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cerr << _GREY << _DIM << "Default WrongAnimal destructor called"
	<< _END << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << _GREEN << this->type << _WHITE << " be like: " << _YELLOW << "*animal noises*"
	<< _END << std::endl;
	return ;
}