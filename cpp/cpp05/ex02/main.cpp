/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:48:57 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 14:09:54 by aprahin          ###   ########.fr       */
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

void	ftLog(std::string log);

int	main(void)
{
	try
	{
		ftLog("Let's make three different forms!");

		ShrubberyCreationForm	s("Grisaia");
		RobotomyRequestForm		r("Ellen Mathers");
		PresidentialPardonForm	p("Sydonay");

		ftLog("And let's instance a Bureaucrat with enough rights to sign them and execute them...");
		
		Bureaucrat	b("Saitama", 1);

		ftLog("Let's sign the forms...");

		b.signForm(s);
		b.signForm(r);
		b.signForm(p);

		ftLog("...and execute them!");

		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);

		ftLog("What if we try to execute a form that wasn't signed?");

		ShrubberyCreationForm	s2("Eden");
		b.executeForm(s2);
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
	
	ftLog("Well that failed.");

	return (0);
}