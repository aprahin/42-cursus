/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:31 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:14:31 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cerr << _GREY << _DIM << "Default Dog constructor called"
	<< _END << std::endl;
	this->type = "Dog";
	return ;
}

Dog::Dog(Dog const &other) : Animal()
{
	std::cerr << _GREY << _DIM << "Copy Dog constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

Dog	&Dog::operator=(Dog const &other)
{
	std::cerr << _GREY << _DIM << "Dog assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cerr << _GREY << _DIM << "Default Dog destructor called"
	<< _END << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << _GREEN << this->type << _WHITE << " be like: " << _YELLOW << "*dog noises*"
	<< _END << std::endl;
	return ;
}