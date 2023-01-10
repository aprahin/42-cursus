/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:09:39 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:09:39 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "colours.hpp"
# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &other);
		WrongCat	&operator=(WrongCat const &other);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif