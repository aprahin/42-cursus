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

void	myMain(void)
{
	ftLog("Let's instance an Animal pointer pointing towards a Dog!");

	Animal	*a_ptr = new Dog();

	ftLog("Our Dog should've created a new brain on the heap!");
	ftLog("What if we now delete the Dog?");

	delete a_ptr;

	ftLog("The brain also gets deleted!");

	ftLog("Let's create an array of animal...");

	Animal	*animals[2] = {new Dog, new Cat};
	
	ftLog("And delete them!");

	delete	animals[0];
	delete	animals[1];	

	return ;
}

void	givenMain(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ftLog("Usage: ./animal [ap, 42]");
		return (1);
	}
	else if (std::string("ap") == av[1])
	{
		myMain();
	}
	else if (std::string("42") == av[1])
	{
		givenMain();
	}
	else
	{
		main(1, NULL);
	}
	return (0);
}
