/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:31 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:14:31 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cerr << _GREY << _DIM << "Default Animal constructor called"
	<< _END << std::endl;
	this->type = "DefaultAnimal";
	return ;
}

Animal::Animal(Animal const &other)
{
	std::cerr << _GREY << _DIM << "Copy Animal constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

Animal	&Animal::operator=(Animal const &other)
{
	std::cerr << _GREY << _DIM << "Animal assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cerr << _GREY << _DIM << "Default Animal destructor called"
	<< _END << std::endl;
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << _GREEN << this->type << _WHITE << " be like: " << _YELLOW << "*animal noises*"
	<< _END << std::endl;
	return ;
}