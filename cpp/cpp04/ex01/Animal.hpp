/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:09:39 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:09:39 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "colours.hpp"
# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal(void);
		Animal(Animal const &other);
		Animal	&operator=(Animal const &other);
		virtual	~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string	type;
};

#endif