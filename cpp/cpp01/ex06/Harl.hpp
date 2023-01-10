/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:43:38 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/26 02:52:04 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include "colours.hpp"
# include <string>
# include <iostream>

class	Harl
{
	public:
		Harl(void);
		~Harl(void);
		void		complain(std::string level);
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
};

#endif