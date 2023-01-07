/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:28:56 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 19:42:51 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include "Harl.hpp"
#include <iostream>

void	ftLog(std::string log);

int	main(int ac, char **av)
{
	Harl	harl_instance;

	if (ac == 1)
	{
		std::cout << "Usage: ./HarlFilter [LEVEL]" << std::endl;
		return (1);
	}
	else
	{
		harl_instance.complain(av[1]);
	}
	return (0);
}