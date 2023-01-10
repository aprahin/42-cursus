/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:31 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:14:31 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cerr << _GREY << _DIM << "Default Cat constructor called"
	<< _END << std::endl;
	this->type = "Cat";
	return ;
}

Cat::Cat(Cat const &other) : Animal()
{
	std::cerr << _GREY << _DIM << "Copy Cat constructor called"
	<< _END << std::endl;
	this->type = other.type;
	return ;
}

Cat	&Cat::operator=(Cat const &other)
{
	std::cerr << _GREY << _DIM << "Cat assignment operator called"
	<< _END << std::endl;
	this->type = other.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cerr << _GREY << _DIM << "Default Cat destructor called"
	<< _END << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << _GREEN << this->type << _WHITE << " be like: " << _YELLOW << "*cat noises*"
	<< _END << std::endl;
	return ;
}