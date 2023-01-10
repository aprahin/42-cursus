/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:00:21 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 18:00:21 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log);

void	myMain(void)
{
	ftLog("Let's start by creating a new Materia Source...");

	IMateriaSource	*src = new MateriaSource();

	ftLog("At this point, this source doesn't know how to create any Materia.");
	ftLog("We can instance a new Ice Materia and make the source learn it...");

	AMateria	*mat = new Ice();
	src->learnMateria(mat);

	ftLog("Now, the source should have cloned that Ice Materia and kept it in its inventory.");
	ftLog("Since we don't need this Ice Materia anymore, let's just delete it...");

	delete mat;

	ftLog("Let's make our source learn about Cure Materia by doing the same as before...");

	mat = new Cure();
	src->learnMateria(mat);
	delete mat;

	ftLog("Our source can now generate both Ice and Cure Materiae!");
	ftLog("Let's create an Ice Materia using the source...");

	mat = src->createMateria("ice");

	ftLog("Let's now create our first character named Zagreus...");

	ICharacter	*player = new Character("Zagreus");

	ftLog("Zagreus can equip Materiae. Let's give him our previously instanced Ice...");

	player->equip(mat);

	ftLog("Unlike the Materia Source, our player can't clone Materiae.");
	ftLog("Let's equip him with a Cure Materia now...");

	mat = src->createMateria("cure");
	player->equip(mat);

	ftLog("Zagreus is ready to use one of its two Materiae.");
	ftLog("We'll need someone to use them on...");

	ICharacter	*foe = new Character("Hades");

	ftLog("Let's try both Materiae!");

	player->use(0, *foe);
	player->use(1, *foe);

	ftLog("Zagreus can also unequip a Materia.");

	player->unequip(1);

	ftLog("Good thing we kept a pointer to the Materia in order to delete it.");

	delete mat;

	ftLog("Let's end this by deleting everyone!");

	delete player;
	delete foe;
	delete src;

	return ;
}

void	givenMain(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria *tmp;
	tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;
	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ftLog("Usage: ./materia [ap, 42]");
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