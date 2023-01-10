/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:59:44 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 21:15:04by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "colours.hpp"

void	ftLog(std::string);

int	main(void)
{
	std::string	brain_str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain_str;
	std::string	&stringREF = brain_str;
	
	ftLog("Display string addresses:");

	std::cout << _YELLOW << _BOLD << "brain_str: " <<
	_END << _WHITE << &brain_str << _END << std::endl;	
	std::cout << _YELLOW << _BOLD << "stringPTR: " <<
	_END << _WHITE << stringPTR << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "stringREF: " <<
	_END << _WHITE << &stringREF << _END << std::endl;

	ftLog("Display string values:");

	std::cout << _YELLOW << _BOLD << "brain_str: " <<
	_END << _WHITE << brain_str << _END << std::endl;	
	std::cout << _YELLOW << _BOLD << "stringPTR: " <<
	_END << _WHITE << *stringPTR << _END << std::endl;
	std::cout << _YELLOW << _BOLD << "stringREF: " <<
	_END << _WHITE << stringREF << _END << std::endl;
	return (0);
}