/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:17:14 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 11:44:45 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>
# include <cstdlib>

class	RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const &executor) const;
};

#endif