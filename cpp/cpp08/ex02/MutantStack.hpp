/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:53:08 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/08 14:53:08 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template	<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void);
		MutantStack<T>(MutantStack<T> const &other);
		MutantStack<T>	&operator=(MutantStack<T> const &other);
		~MutantStack<T>(void);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void);
		iterator	end(void);
};

template	<typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << _GREY << _DIM << "MutantStack default constructor called"
	<< _END << std::endl;
	return ;
}

template	<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other)
{
	std::cout << _GREY << _DIM << "MutantStack copy constructor called"
	<< _END << std::endl;
	*this = other;
	return ;
}

template	<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &other)
{
	std::cout << _GREY << _DIM << "MutantStack assignment operator called"
	<< _END << std::endl;
	*this = other;
	return (*this);
}

template	<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << _GREY << _DIM << "MutantStack default destructor called"
	<< _END << std::endl;
	return ;
}

template	<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template	<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif