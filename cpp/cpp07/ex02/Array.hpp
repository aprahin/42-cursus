/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:04:51 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/07 22:04:51 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "colours.hpp"
# include <string>
# include <iostream>

template	<typename T>
class	Array
{
	public:
		Array<T>(void);
		Array<T>(Array const &other);
		Array<T>	&operator=(Array const &other);
		~Array<T>(void);

		Array<T>(int n);
		T	&operator[](int i);
		int const	&size(void) const;
		int const	&getSize(void) const;
		void		setSize(int n);

		class	BadIndexException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Couldn't access requested index in array.");
				};
		};
	private:
		T	*_elems;
		int	_size;
};

template	<typename T>
Array<T>::Array(void)
{
	std::cerr << _GREY << _DIM << "Array default constructor called" << _END << std::endl;
	this->_elems = new T[0]();
	this->_size = 0;
	return ;
}

template	<typename T>
Array<T>::Array(Array<T> const &other)
{
	std::cerr << _GREY << _DIM << "Array copy constructor called" << _END << std::endl;
	this->setSize(other.getSize());
	this->_elems = new T[this->getSize()]();
	for (int i = 0; i < this->getSize(); i++)
		this->_elems[i] = other._elems[i];
	return ;
}

template	<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &other)
{
	std::cerr << _GREY << _DIM << "Array assignment operator called" << _END << std::endl;
	delete [] this->_elems;
	this->setSize(other.getSize());
	this->_elems = new T[this->getSize()]();
	for (int i = 0; i < this->getSize(); i++)
		this->_elems[i] = other._elems[i];
	return (*this);
}

template	<typename T>
Array<T>::~Array(void)
{
	std::cerr << _GREY << _DIM << "Array default destructor called" << _END << std::endl;
	delete [] this->_elems;
	return ;
}

template	<typename T>
Array<T>::Array(int	n)
{
	std::cerr << _GREY << _DIM << "Array size constructor called" << _END << std::endl;
	if (n <= 0)
	{
		this->_elems = new T[1]();
		this->_size = 1;
	}
	else
	{
		this->_elems = new T[n]();
		this->_size = n;
	}
	return ;
}

template	<typename T>
int const	&Array<T>::size(void) const
{
	return (this->getSize());
}

template	<typename T>
int const	&Array<T>::getSize(void) const
{
	return (this->_size);
}

template	<typename T>
void	Array<T>::setSize(int n)
{
	this->_size = n;
	return ;
}

template	<typename T>
T	&Array<T>::operator[](int i)
{
	if (i >= this->_size || i < 0)
		throw (BadIndexException());
	else
		return (this->_elems[i]);
	return (this->_elems[0]);
}
#endif
