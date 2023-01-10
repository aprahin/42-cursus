/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:22:19 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:22:19 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

void	ftLog(std::string log);

int	main(void)
{
	ftLog("I can't instance any Animal since it is now an Abstract class!!");
	ftLog("Since Cat and Dog have implemented their Animal abstract member function, \
I can instance them.");

	Animal	*c_ptr = new Cat();
	Animal	*d_ptr = new Dog();
	c_ptr->makeSound();
	d_ptr->makeSound();

	ftLog("That's it. (The whole exercise is changing one line of code)");

	delete c_ptr;
	delete d_ptr;

	return (0);
}
