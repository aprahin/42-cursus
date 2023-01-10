/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:29:05 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/20 19:38:00 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include "colours.hpp"
# include <iostream>
# include <string>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	private:
		std::string const	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif