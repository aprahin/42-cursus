/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:37:44 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 23:21:42 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>
#include <string.h>

void	ftLog(std::string log);

void	myMain(void)
{
	ftLog("Instancing a weapon with type Knife...");
	
	Weapon	knife("Knife");

	ftLog("...along with a HumanA called Red Imposter.");

	HumanA	red_imposter("Red Imposter", knife);

	ftLog("He already has a knife and is ready to attack!");

	red_imposter.attack();

	ftLog("Changing Knife for a Crowbar in the main...");

	knife.setType("Crowbar");

	ftLog("Let's attack again!");

	red_imposter.attack();

	ftLog("Now instancing a Glock-18...");

	Weapon	glock("Glock-18");

	ftLog("...along with a HumanB called Blue Crewmate.");

	HumanB	blue_crewmate("Blue Crewmate");

	ftLog("He can't be constructed with a weapon :( What if he attacks?");

	blue_crewmate.attack();

	ftLog("Let's give him the Glock-18 and let him attack!");

	blue_crewmate.setWeapon(glock);
	blue_crewmate.attack();
	
	ftLog("Level up! Let's turn this Glock-18 into a Rocket launcher in main...");
	
	glock.setType("Rocket launcher");

	ftLog("Blue Crewmate will now attack!");

	blue_crewmate.attack();

	ftLog("Well, time to return...");
	
	return ;
}

void	givenMain(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 2 || (strncmp(av[1], "ap", 3) && strncmp(av[1], "42", 3)))
	{
		ftLog("Usage: ./violence [ap, 42]");
		return (1);
	}
	else if (!strncmp(av[1], "ap", 3))
		myMain();
	else if (!strncmp(av[1], "42", 3))
		givenMain();
	else
		main(1, av);
	return (0);
}
