/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:10:28 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 11:50:12 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("DefaultForm"), _is_signed(false), _sign_grade(42), _exec_grade(42)
{
	std::cerr << _GREY << _DIM << "Form default constructor called" << _END << std::endl;
	return ;
}

Form::Form(Form const &other) : _name(other.getName()), _is_signed(other.getSigned()), _sign_grade(other.getSignGrade()), _exec_grade(other.getExecGrade())
{
	std::cerr << _GREY << _DIM << "Form copy constructor called" << _END << std::endl;
	this->setSigned(other.getSigned());
	return ;
}

Form	&Form::operator=(Form const &other)
{
	std::cerr << _GREY << _DIM << "Form assignment operator called (name, sign grade and exec grade can't be changed" << _END << std::endl;
	this->setSigned(other.getSigned());
	return (*this);
}

Form::~Form()
{
	std::cerr << _GREY << _DIM << "Form default destructor called" << _END << std::endl;
	return ;
}

Form::Form(
	std::string name,
	int sign_grade,
	int exec_grade
) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cerr << _GREY << _DIM << "Form multiple values constructor called with values "
	<< _YELLOW << this->getName() << " "
	<< this->getSignGrade() << " " << this->getExecGrade()
	<< _END << std::endl;
	return ;
}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

bool const	&Form::getSigned(void) const
{
	return (this->_is_signed);
}

void	Form::setSigned(bool value)
{
	this->_is_signed = value;
	return ;
}

int const	&Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int const	&Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

std::string const	&Form::getTarget(void) const
{
	return (this->target);
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this->getSignGrade())
	{
		this->setSigned(true);
	}
	else
	{
		throw (Form::GradeTooLowException());
	}
	return ;
}

std::ostream	&operator<<(std::ostream &o, Form const &f)
{
	o << f.getName() << ", form ";
	if (f.getSigned())
		o << "is signed, ";
	else
		o << "isn't signed, ";
	o << "sign grade " << f.getSignGrade() << " and exec grade " << f.getExecGrade();
	return (o);
}