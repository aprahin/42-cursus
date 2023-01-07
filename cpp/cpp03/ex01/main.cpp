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
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's instance a ScavTrap named Atraks-1");

	ScavTrap	st_instance("Atraks-1");

	ftLog("As well as a ClapTrap named Taniks for reference");

	{
		ClapTrap	ct_instance("Taniks");

		ftLog("Atraks-1 has different stats compared to Taniks.");

		st_instance.takeDamage(5);
		ct_instance.takeDamage(5);

		ftLog("They have different attacks!");

		st_instance.attack("Guardian");
		ct_instance.attack("Guardian");

		ftLog("And Atraks-1 can also Guard Gate!");

		st_instance.guardGate();

		ftLog("Otherwise, everything should be the same.");

		st_instance.beRepaired(30);
		ct_instance.beRepaired(30);

		ftLog("Let's say goodbye to Taniks...");
	}

	ftLog("And now, time to finish this encounter...");

	return (0);
}