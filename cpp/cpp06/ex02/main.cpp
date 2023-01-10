/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:13:26 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 19:13:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "Base.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void	ftLog(std::string log);

Base	*generate(void)
{
	int		random = rand() % 3;
	if (random == 0)
	{
		std::cout << _GREY << "Generated " << _BLUE << "A" << _GREY << "..." << _END << std::endl;
		return (new A());
	}
	if (random == 1)
	{
		std::cout << _GREY << "Generated " << _YELLOW << "B" << _GREY << "..." << _END << std::endl;
		return (new B());
	}
	std::cout << _GREY << "Generated " << _RED << "C" << _GREY << "..." << _END << std::endl;
	return (new C());
}

void	identify(Base *p)
{
	A	*a;
	a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << _WHITE << "I identified a pointer to " << _BLUE << "A" << _WHITE << "!" << _END << std::endl;
		return ;
	}
	B	*b;
	b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << _WHITE << "I identified a pointer to " << _YELLOW << "B" << _WHITE << "!" << _END << std::endl;
		return ;
	}
	C	*c;
	c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << _WHITE << "I identified a pointer to " << _RED << "C" << _WHITE << "!" << _END << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		A	a;
		a = dynamic_cast<A&>(p);
		std::cout << _WHITE << "I identified a reference to " << _BLUE << "A" << _WHITE << "!" << _END << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		B	b;
		b = dynamic_cast<B&>(p);
		std::cout << _WHITE << "I identified a reference to " << _YELLOW << "B" << _WHITE << "!" << _END << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		C	c;
		c = dynamic_cast<C&>(p);
		std::cout << _WHITE << "I identified a reference to " << _RED << "C" << _WHITE << "!" << _END << std::endl;
		return ;
	}
	catch (std::exception &e) {}
}

int	main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base	*ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return (0);
}