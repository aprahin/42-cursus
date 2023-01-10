/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:48:54 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/01 17:48:54 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's instance a ClapTrap named Cayde-6 with 10 health points, \
	10 energy points and 0 attack damage!");

	ClapTrap	ct_instance("Cayde-6");

	ftLog("He will now attack three times!");

	ct_instance.attack("Training Dummy");
	ct_instance.attack("Training Dummy");
	ct_instance.attack("Training Dummy");

	ftLog("He will now take some damage!");

	ct_instance.takeDamage(2);
	ct_instance.takeDamage(1);
	ct_instance.takeDamage(2);

	ftLog("He will now repair itself!");

	ct_instance.beRepaired(1);
	ct_instance.beRepaired(2);
	ct_instance.beRepaired(1);

	ftLog("What if he runs out of energy points?");

	ct_instance.attack("Uldren Sov");
	ct_instance.attack("Uldren Sov");
	ct_instance.attack("Uldren Sov");
	ct_instance.attack("Uldren Sov");
	ct_instance.attack("Uldren Sov");

	ftLog("That's quite unfortunate.");
	ftLog("What if we give him back some energy points and kill him?");

	ct_instance = ClapTrap("Cayde-7", 5, 10, 0);
	ct_instance.takeDamage(30);
	ct_instance.beRepaired(5);
	ct_instance.attack("Uldren Sov");

	ftLog("Time to recycle Cayde-7");

	return (0);
}