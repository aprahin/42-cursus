/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:20:30 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/04 16:49:15 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colours.hpp"
#include <string>
#include <iostream>

void	ftLog(std::string log);

int	main(void)
{
	ftLog("Let's instance a Bureaucrat named NPC with a grade of 42...");

	try
	{
		Bureaucrat	b_instance = Bureaucrat("NPC", 42);
		
		ftLog("Now let's stream it to the standard output...");

		std::cout << _YELLOW << b_instance << _END << std::endl;

		ftLog("And let's try catching some exceptions!");
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}

	ftLog("Nothing happened as a grade of 42 is perfectly acceptable.");
	ftLog("Let's now instance a Bureaucrat named Hero with a grade of 1...");

	try
	{
		Bureaucrat	b_instance = Bureaucrat("Hero", 1);
		std::cout << _YELLOW << b_instance << _END << std::endl;

		ftLog("What if I increase its grade?");

		b_instance.incrementGrade();
		std::cout << _YELLOW << b_instance << _END << std::endl;

		ftLog("Let's catch some exceptions...");
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}

	ftLog("Seems the grade was too high.");
	ftLog("What about if we instance a Demon Lord with a grade of 200?");

	try
	{
		Bureaucrat	b_instance = Bureaucrat("Demon Lord", 200);
		std::cout << _YELLOW << b_instance << _END << std::endl;

		ftLog("Let's catch some exceptions...");
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << _RED << e.what() << _END << std::endl;
	}

	ftLog("Damn.");
	
	return (0);
}