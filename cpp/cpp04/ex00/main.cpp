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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

void	ftLog(std::string log);

void	myMain(void)
{
	ftLog("Let's instance an Animal pointer to an Animal!");

	Animal	*a_ptr = new Animal();

	ftLog("This Animal has a default behaviour.");

	a_ptr->makeSound();

	ftLog("OK let's get rid of it.");

	delete a_ptr;

	ftLog("What if we make it point towards a Dog?");

	a_ptr = new Dog();

	ftLog("Now, since we used the virtual keyword in its member function, it \
will use its own method without having to precise which one to use!");

	a_ptr->makeSound();

	ftLog("Same if we make it point towards a Cat!");

	delete a_ptr;
	a_ptr = new Cat();
	a_ptr->makeSound();
	delete a_ptr;

	ftLog("OK. Now what if we didn't use the virtual keyword?");

	WrongAnimal *w_ptr = new WrongAnimal();
	w_ptr->makeSound();

	ftLog("The parent class uses its own sound as expected...");
	ftLog("But I've written a different sound for its child class.");

	delete w_ptr;
	w_ptr = new WrongCat();
	w_ptr->makeSound();

	ftLog("Damn.");
	ftLog("By not using the virtual keyword, our WrongAnimal pointer pointing \
towards a WrongCat will continue using its base member function.");
	ftLog("Time to wrap this up...");

	delete w_ptr;

	return ;
}

void	givenMain(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	wrong_i->makeSound();
	wrong_meta->makeSound();

	delete meta;
	delete j;
	delete i;

	delete wrong_i;
	delete wrong_meta;
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