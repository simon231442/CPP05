#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	Grade_--;
}

void				Bureaucrat::decrementGrade(void)
{
	if (Grade_ + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	Grade_++;
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


void				Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << Name_ << " signed " << form.getName() << ".\n";
	}
	catch (std::exception & e)// en savoir plus sur cette synthaxe
	{
		std::cout << Name_ << " couldn't sign " << form.getName() << " because " << e.what() << ".\n";
	}
}

void				Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << Name_ << " executed " << form.getName() << ".\n";
	}
	catch (std::exception & e)
	{
		std::cout << Name_ << " failed with the form " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}


void				Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	Grade_ = grade;
}

