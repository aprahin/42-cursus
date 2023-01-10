/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:09:39 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 15:09:39 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "colours.hpp"
# include "Animal.hpp"
# include <iostream>
# include <string>

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &other);
		Cat	&operator=(Cat const &other);
		virtual ~Cat(void);

		void	makeSound(void) const;
};

#endif
