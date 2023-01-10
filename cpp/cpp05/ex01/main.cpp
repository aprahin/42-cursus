/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:48:57 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 11:05:40 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include "colours.hpp"

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's instance a Bureaucrat...");
	
	try
	{
		Bureaucrat	b_instance("Goddess", 30);
	
		ftLog("Let's announce her...");

		std::cout << _BLUE << b_instance << _END << std::endl;	

		ftLog("And now, let's write a form!");

		Form	f_instance("Hero license", 42, 20);

		ftLog("That form is...");

		std::cout << _BLUE << f_instance << _END << std::endl;

		ftLog("Let's make her sign it!");

		b_instance.signForm(f_instance);
		std::cout << _BLUE << f_instance << _END << std::endl;

		ftLog("OK, no problem so far.");
		ftLog("What about this form?");

		Form	f_instance2("Pacte de non-agression germano-soviétique", 5, 1);
		std::cout << _BLUE << f_instance2 << _END << std::endl;
		b_instance.signForm(f_instance2);
		std::cout << _BLUE << f_instance2 << _END << std::endl;
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
	ftLog("That's too bad.");
	
	return (0);
}
