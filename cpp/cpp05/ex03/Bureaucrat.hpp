/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:13:27 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 11:39:49 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include "colours.hpp"
# include <string>
# include <iostream>

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator=(Bureaucrat const &other);
		~Bureaucrat(void);

		Bureaucrat(std::string name, int grade);
		std::string const	&getName(void) const;
		int const			&getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(Form &f);
		
		void				executeForm(Form const &form);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Bureaucrat grade should be bigger than 0.");
				};
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Bureaucrat grade should be smaller than 151.");
				};
		};
	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &other);

#endif