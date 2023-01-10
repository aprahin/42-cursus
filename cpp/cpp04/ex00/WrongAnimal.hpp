/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:59 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:38:59 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "colours.hpp"
# include <iostream>
# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal	&operator=(WrongAnimal const &other);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void	makeSound(void) const;
	protected:
		std::string	type;
};

#endif