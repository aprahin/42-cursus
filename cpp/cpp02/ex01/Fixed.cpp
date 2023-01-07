/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:18:57 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 09:52:44 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0)
{
	std::cout << _DIM << _GREY << "Fixed default constructor called" << _END
	<< std::endl;
	return ;
}

Fixed::Fixed(const Fixed &other) : _number(other._number)
{
	std::cout << _DIM << _GREY << "Fixed copy constructor called" << _END
	<< std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << _DIM << _GREY << "Fixed assignment operator called" << _END
	<< std::endl;
	this->_number = other._number;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << _DIM << _GREY << "Fixed destructor called" << _END
	<< std::endl;
	return ;
}

Fixed::Fixed(int n) 
{
	for (int i = Fixed::_bits; i > 0; i--)
	{
		n *= 2;
	}
	this->_number = n;
	std::cout << _DIM << _GREY << "Fixed integer constructor called, setting _number to "
	<< _END << _YELLOW << this->_number << _END << std::endl;
	return ;
}

Fixed::Fixed(float f)  
{
	for (int i = Fixed::_bits; i > 0; i--)
	{
		f *= 2;
	}
	this->_number = roundf(f);
	std::cout << _DIM << _GREY << "Fixed float constructor called, setting _number to "
	<< _END << _YELLOW << this->_number << _END << std::endl;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	ret;

	ret = this->_number;
	for (int i = Fixed::_bits; i > 0; i--)
	{
		ret /= 2;
	}
	std::cout << _DIM << _GREY << "toFloat called, returning "
	<< _END << _YELLOW << ret << _END << _DIM << _GREY << " converted from "
	<< _END << _YELLOW << this->_number << _END << std::endl;
	return (ret);
}

int		Fixed::toInt(void) const
{
	int	ret;
	
	ret = this->_number;
	for (int i = Fixed::_bits; i > 0; i--)
	{
		ret /= 2;
	}
	std::cout << _DIM << _GREY << "toInt called, returning "
	<< _END << _YELLOW << ret << _END << _DIM << _GREY << " converted from "
	<< _END << _YELLOW << this->_number << _END << std::endl;
	return (ret);
}

int	Fixed::getRawBits(void)	const
{
	std::cout << _DIM << _GREY << "getRawBits called, returning "
	<< _END << _YELLOW << this->_number << _END << std::endl;
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << _DIM << _GREY << "setRawBits called, setting _number to "
	<< _END << _YELLOW << raw << _DIM << _GREY << " from old value " << _END
	<< _YELLOW << this->_number << _END << std::endl;
	this->_number = raw;
	return ;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &other)
{
	o << other.toFloat();
	return (o);
}