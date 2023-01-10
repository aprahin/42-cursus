/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:08:59 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 19:50:58 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*ret = new Zombie[N];
	if (ret == NULL)
		return (NULL);
	for (int i = 0; i < N; i++)
		ret[i].setName(name);
	return (ret);
}