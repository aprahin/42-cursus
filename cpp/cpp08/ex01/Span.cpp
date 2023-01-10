/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:37:22 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/08 12:37:22 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0), _elems()
{
	std::cerr << _GREY << _DIM << "Span default constructor called" << _END << std::endl;
	return ;
}

Span::Span(Span const &other)
{
	std::cerr << _GREY << _DIM << "Span copy constructor called" << _END << std::endl;
	*this = other;
	return ;
}

Span	&Span::operator=(Span const &other)
{
	std::cerr << _GREY << _DIM << "Span assignment operator called" << _END << std::endl;
	this->_elems = other._elems;
	this->_size = other._size;
	return (*this);
}

Span::~Span(void)
{
	std::cerr << _GREY << _DIM << "Span default destructor called" << _END << std::endl;
	return ;
}

Span::Span(unsigned int n) : _size(n), _elems(0)
{
	std::cerr << _GREY << _DIM << "Span size constructor called with size "
	<< _YELLOW << n << _END << std::endl;
	return ;
}

void	Span::addNumber(int n)
{
	if (this->_elems.size() >= this->_size)
		throw(NotEnoughSpaceException());
	else
		this->_elems.push_back(n);
	return ;
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int	add_size = std::vector<int>(begin, end).size();

	if (this->_elems.size() + add_size > this->_size)
		throw(NotEnoughSpaceException());
	else
		this->_elems.insert(this->_elems.end(), begin, end);
	return ;
}

int	Span::shortestSpan(void) const
{
	if (this->_elems.size() <= 1)
	{
		throw(SpanNotFoundException());
		return (0);
	}
	std::vector<int>	spans;
	std::vector<int>	tmp = this->_elems;
	sort(tmp.begin(), tmp.end());
	for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end() - 1; it++)
		spans.push_back(abs(*it - *(it + 1)));
	return (*std::min_element(spans.begin(), spans.end()));
}

int	Span::longestSpan(void) const
{
	if (this->_elems.size() <= 1)
	{
		throw(SpanNotFoundException());
		return (0);
	}
	int	min = *std::min_element(this->_elems.begin(), this->_elems.end());
	int	max = *std::max_element(this->_elems.begin(), this->_elems.end());
	return (max - min);
}

std::vector<int>::iterator const	Span::begin(void)
{
	return (this->_elems.begin());
}

std::vector<int>::iterator const	Span::end(void)
{
	return (this->_elems.end());
}
