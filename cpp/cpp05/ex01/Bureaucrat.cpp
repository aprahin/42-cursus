/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:26:09 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 11:06:00 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("DefaultBureaucrat"), _grade(42)
{
	std::cerr << _GREY << _DIM << "Bureaucrat default constructor called"
	<< _END << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	std::cerr << _GREY << _DIM << "Bureaucrat copy constructor called (name can't be changed)"
	<< _END << std::endl;
	this->_grade = other.getGrade();
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cerr << _GREY << _DIM << "Bureaucrat assignment operator called (name can't be changed"
	<< _END << std::endl;
	this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cerr << _GREY << _DIM << "Bureaucrat default destructor called"
	<< _END << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cerr << _GREY << _DIM << "Bureaucrat multiple values constructor called for "
	<< _YELLOW << this->getName() << _GREY << " with grade "
	<< _YELLOW << this->getGrade() << _END << std::endl;
	if (this->getGrade() < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->getGrade() > 150)
		throw (Bureaucrat::GradeTooLowException());
	return ;
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);	
}

int const	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	if (this->getGrade() < 1)
		throw (Bureaucrat::GradeTooHighException());
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if (this->getGrade() > 150)
		throw (Bureaucrat::GradeTooLowException());
	return ;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &other)
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (o);
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _GREEN << this->getName() << _WHITE << " signed "
		<< _YELLOW << f.getName() << _END << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _GREEN << this->getName() << _WHITE << " couldn't sign "
		<< _YELLOW << f.getName() << _WHITE << " because "
		<< _RED << e.what() << _END << std::endl;
		throw;
	}
}