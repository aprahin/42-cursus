/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:48:57 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 16:36:54 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include "colours.hpp"
#include "Intern.hpp"

void	ftLog(std::string log);

int	main(void)
{
	try
	{
		ftLog("Let's instance a bureaucrat and an intern...");
		
		Bureaucrat	b("King", 2);
		Intern		i;

		ftLog("The intern will now try to make a Presidential Pardon form with a target named King");
		
		Form	*f_ptr = i.makeForm("presidential pardon", "King");
		
		ftLog("Looks like it worked.");

		b.signForm(*f_ptr);
		b.executeForm(*f_ptr);
		delete f_ptr;

		ftLog("What if we make a form that doesn't exist?");
		
		f_ptr = i.makeForm("yolo", "sheesh");
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl; 
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl; 
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl; 
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl; 
	}
	catch (Form::NotSignedException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl; 
	}
	catch (Intern::FormNotFoundException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	
	ftLog("Sheesh.");

	return (0);
}