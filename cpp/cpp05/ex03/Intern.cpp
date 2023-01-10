#include "Intern.hpp"

Intern::Intern(void)
{
	std::cerr << _GREY << _DIM << "Intern default constructor called" << _END << std::endl;
	return ;
}

Intern::Intern(Intern const &other)
{
	std::cerr << _GREY << _DIM << "Intern copy constructor called" << _END << std::endl;
	(void) other;
	return ;
}

Intern	&Intern::operator=(Intern const &other)
{
	std::cerr << _GREY << _DIM << "Intern assignment operator called" << _END << std::endl;
	(void) other;
	return (*this);
}

Intern::~Intern(void)
{
	std::cerr << _GREY << _DIM << "Intern default destructor called" << _END << std::endl;
	return ;
}

Form	*Intern::makeForm(std::string name, std::string target) const
{
	Form	*ret = NULL;
	t_form	form_list[] = {
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}
	};
	for (int i = 0; i < 3; ++i)
	{
		if (name == form_list[i].name)
			ret = form_list[i].type;
		else
			delete form_list[i].type;
	}
	if (ret == NULL)
	{
		throw (Intern::FormNotFoundException());
		return (NULL);
	}
	std::cout << _YELLOW << "Intern creates " << name << _END << std::endl;
	return (ret);
}
