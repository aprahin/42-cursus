/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:19:35 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 16:31:40 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "colours.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &other);
		Intern	&operator=(Intern const &other);
		~Intern(void);
		
		Form	*makeForm(std::string name, std::string target) const;
		
		class	FormNotFoundException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Intern could not find form with that name.");
				};
		};
	private:
		typedef struct s_form
		{
			std::string	name;
			Form		*type;
		}	t_form;
		
};

#endif