/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:01:14 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/07 16:05:54 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template	<typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template	<typename T>
T const	&min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template	<typename T>
T const	&max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

template	<typename T>
void	test_template(std::string name, T &a, T &b)
{
	std::cout << _GREY << "================================" << _END << std::endl;
	std::cout << _CYAN << _BOLD << "TEST: " << name << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "SWAP" << _END << std::endl;
	std::cout << _GREEN << "Values before: " << a << " and " << b << _END << std::endl;
	::swap<T>(a, b);
	std::cout << _GREEN << "Values after: " << a << " and " << b << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "MIN" << _END << std::endl;
	std::cout << _GREEN << "Values: " << a << " and " << b << _END << std::endl;
	T	ret = ::min<T>(a, b);
	std::cout << _GREEN << "Return: " << ret << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "MAX" << _END << std::endl;
	std::cout << _GREEN << "Values: " << a << " and " << b << _END << std::endl;
	ret = ::max<T>(a, b);
	std::cout << _GREEN << "Return: " << ret << _END << std::endl;
	std::cout << _GREY << "================================" << _END << std::endl << std::endl;
}

#endif