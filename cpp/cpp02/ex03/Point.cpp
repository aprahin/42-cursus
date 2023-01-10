/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:48:36 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/29 21:48:36 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cerr << _DIM << _GREY << "Point default constructor called" << _END
	<< std::endl;
	return ;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	std::cerr << _DIM << _GREY << "Point copy constructor called" << _END
	<< std::endl;
	return ;
}

Point	&Point::operator=(const Point &other)
{
	std::cerr << _DIM << _GREY << "Point assignment operator called but can't assign! (x,y) constants" << _END
	<< std::endl;
	(void) other;
	return (*this);
}

Point::~Point(void)
{
	std::cerr << _DIM << _GREY << "Point destructor called" << _END
	<< std::endl;
	return ;
}

Point::Point(const Fixed a, const Fixed b) : _x(a), _y(b)
{
	std::cerr << _DIM << _GREY << "Point Fixed constructor called" << _END
	<< std::endl;
	return ;
}

bool	Point::cross_product_pos(
	const Point &a,
	const Point &b,
	const Point &s,
	const Point &t)
{
	Fixed	res;

	res = (b._x - a._x) * (t._y - s._y) - (t._x - s._x) * (b._y - a._y);
	return (res > 0);
}