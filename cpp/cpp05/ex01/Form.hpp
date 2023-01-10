/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:10:25 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 10:41:16 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "colours.hpp"
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(Form const &other);
		Form	&operator=(Form const &other);
		~Form(void);

		Form(
			std::string name,
			int sign_grade,
			int exec_grade
		);
		std::string const	&getName(void) const;
		bool const			&getSigned(void) const;
		void				setSigned(bool value);
		int	const			&getSignGrade(void) const;
		int const			&getExecGrade(void) const;

		void				beSigned(Bureaucrat const &b);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Form grade should be bigger than 0.");
				};
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Form grade should be smaller than 151 or Bureaucrat's grade is too low to sign Form.");
				};
		};

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_exec_grade;
};

std::ostream	&operator<<(std::ostream &o, Form const &f);

#endif
