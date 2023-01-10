/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:31 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:14:31 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cerr << _GREY << _DIM << "Default WrongCat constructor called"
	<< _END << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal()
{
	std::cerr << _GREY << _DIM << "Copy WrongCat constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	std::cerr << _GREY << _DIM << "WrongCat assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cerr << _GREY << _DIM << "Default WrongCat destructor called"
	<< _END << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << _GREEN << this->type << _WHITE << " be like: " << _YELLOW << "*cat noises*"
	<< _END << std::endl;
	return ;
}