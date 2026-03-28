#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name_("default"), Grade_(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : Name_(name), Grade_(grade)
{
	if (Grade_ < 1)
		throw GradeTooHighException();
	if (Grade_ > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : Name_(src.Name_), Grade_(src.Grade_)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&			Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		Grade_ = src.Grade_;
	return *this;
}

std::string const&	Bureaucrat::getName(void) const
{
	return Name_;
}

int					Bureaucrat::getGrade(void) const
{
	return Grade_;
}

void				Bureaucrat::incrementGrade(void)
{
	if (Grade_ - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	Grade_++;
}

void				Bureaucrat::decrementGrade(void)
{
	if (Grade_ + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	Grade_--;
}

char const*			Bureaucrat::GradeTooHighException::what() const throw()
{
	return "a burocrat try to have a grade over the limit of 1";
}

char const*			Bureaucrat::GradeTooLowException::what() const throw()
{
	return "a burocrat try to have a grade under the limit of 150";
}


std::ostream&		operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}


void				Bureaucrat::setGrade(int grade)
{
	Grade_ = grade;
}

