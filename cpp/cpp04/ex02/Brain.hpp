/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:07:02 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/02 16:07:02 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "colours.hpp"
# include <string>
# include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		~Brain(void);
	private:
		std::string	_ideas[100];
};

#endif