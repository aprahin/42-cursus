/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:09:08 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 16:09:08 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cerr << _GREY << _DIM << "Default Brain constructor called"
	<< _END << std::endl;
	return ;
}

Brain::Brain(Brain const &other)
{
	std::cerr << _GREY << _DIM << "Copy Brain constructor called"
	<< _END << std::endl;
	for (int i = 0; i < 100; i++)
		(this->_ideas)[i] = (other._ideas)[i];
	return ;
}

Brain	&Brain::operator=(Brain const &other)
{
	std::cerr << _GREY << _DIM << "Brain assignment operator called"
	<< _END << std::endl;
	for (int i = 0; i < 100; i++)
		(this->_ideas)[i] = (other._ideas)[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cerr << _GREY << _DIM << "Default Brain destructor called"
	<< _END << std::endl;
	return ;
}