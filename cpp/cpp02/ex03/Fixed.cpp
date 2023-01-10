/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:18:57 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 10:15:20 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0)
{
	std::cerr << _DIM << _GREY << "Fixed default constructor called" << _END
	<< std::endl;
	return ;
}

Fixed::Fixed(const Fixed &other) : _number(other._number)
{
	std::cerr << _DIM << _GREY << "Fixed copy constructor called" << _END
	<< std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cerr << _DIM << _GREY << "Fixed assignment operator called" << _END
	<< std::endl;
	this->_number = other._number;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cerr << _DIM << _GREY << "Fixed destructor called" << _END
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
	std::cerr << _DIM << _GREY << "Fixed integer constructor called, setting _number to "
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
	std::cerr << _DIM << _GREY << "Fixed float constructor called, setting _number to "
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
	return (ret);
}

int	Fixed::getRawBits(void)	const
{
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
	return ;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &other)
{
	o << other.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (ret);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (ret);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}