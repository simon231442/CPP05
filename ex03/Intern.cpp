#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern&		Intern::operator=(Intern const & src)
{
	(void)src;
	return *this;
}

AForm*		Intern::makeShrubberyCreationForm(std::string const & target) const
{
	return new ShrubberyCreationForm(target);
}

AForm*		Intern::makeRobotomyRequestForm(std::string const & target) const
{
	return new RobotomyRequestForm(target);
}

AForm*		Intern::makePresidentialPardonForm(std::string const & target) const
{
	return new PresidentialPardonForm(target);
}

AForm*		Intern::makeForm(std::string const & formName, std::string const & target) const
{
	static std::string const		FormType[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm*	(Intern::*constructor[3])(std::string const & target) const = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	AForm*	formNew;

	for (int i = 0; i < 3; i++)
	{
		if (FormType[i] == formName)
		{
			formNew = (this->*constructor[i])(target);
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return formNew;
		}
	}
	std::cout << "Intern failed to create '" << formName << "' because the form does not exist." << std::endl;
	throw Intern::UnknownFormException();
}

const char*	Intern::UnknownFormException::what() const throw()
{
	return "unknown form";
}

//faire des methode pour chaque constructeur
//faire un tableau de string
//un autre avec des pointeur sur constructeur
