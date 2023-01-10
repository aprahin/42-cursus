/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:33:47 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/07 18:51:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template	<typename T>
void	iter(T *array, int size, void (&f)(T &))
{
	for (int i = 0; i < size; ++i)
	{
		f(array[i]);
	}	
	return ;
}

template	<typename T>
void	test_template(std::string name, T *array, int size, void (&f)(T &))
{
	std::cout << _GREY << "================================" << _END << std::endl;
	std::cout << _CYAN << _BOLD << "TEST: " << name << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "ARRAY BEFORE" << _END << std::endl;
	std::cout << _GREEN << "[";
	for (int i = 0; i < size; i++)
	{
		std::cout << _GREEN << array[i];
		if (i != size - 1)
			std::cout << _GREEN << ", ";
	}
	std::cout << "]" << _END << std::endl;
	iter(array, size, f);
	std::cout << _YELLOW << _BOLD << "ARRAY AFTER" << _END << std::endl;
	std::cout << _GREEN << "[";
	for (int i = 0; i < size; i++)
	{
		std::cout << _GREEN << array[i];
		if (i != size - 1)
			std::cout << _GREEN << ", ";
	}
	std::cout << "]" << _END << std::endl;
	std::cout << _GREY << "================================" << _END << std::endl << std::endl;
}

#endif