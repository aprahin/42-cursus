/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:18:09 by aprahin           #+#    #+#             */
/*   Updated: 2023/01/05 14:15:58 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cerr << _GREY << _DIM << "ShrubberyCreationForm default constructor called" << _END << std::endl;
	this->target = "DefaultTarget";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cerr << _GREY << _DIM << "ShrubberyCreationForm copy constructor called" << _END << std::endl;
	*this = other;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	std::cerr << _GREY << _DIM << "ShrubberyCreationForm assignment operator called" << _END << std::endl;
	this->target = other.target;
	this->setSigned(other.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cerr << _GREY << _DIM << "ShrubberyCreationForm default destructor called" << _END << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	std::cerr << _GREY << _DIM << "ShrubberyCreationForm target constructor called with target "
	<< _YELLOW << target << _END << std::endl;
	this->target = target;
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (ShrubberyCreationForm::NotSignedException());
	else if (this->getExecGrade() < executor.getGrade())
		throw (ShrubberyCreationForm::GradeTooLowException());
	else
	{
		std::ofstream	file(this->getTarget() + std::string("_shrubbery"));
		file << "/\\ (I'm a binary tree)";
		file.close();
	}
	return ;
}