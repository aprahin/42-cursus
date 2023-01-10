/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:09:39 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:09:39 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "colours.hpp"
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &other);
		Dog	&operator=(Dog const &other);
		virtual ~Dog(void);

		virtual void	makeSound(void) const;
	private:
		Brain	*_brain;
};

#endif