#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : Name_("default"), Signed_(0), SignGrade_(1), ExecGrade_(1)
{
}

Form::Form(std::string const name, int const signed_grade, int const exec_grade) :
	Name_(name),
	Signed_(0),
	SignGrade_(signed_grade),
	ExecGrade_(exec_grade)
{
	if (SignGrade_ < 1)
		throw GradeTooHighException();
	if (SignGrade_ > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src) :
	Name_(src.Name_),
	Signed_(src.Signed_),
	SignGrade_(src.SignGrade_),
	ExecGrade_(src.ExecGrade_)
{
}

Form::~Form()
{
}

Form&			Form::operator=(Form const &src)
{
	if (this != &src)
		this->Signed_ = src.Signed_;	
	return *this;
}

std::string const&	Form::getName(void) const
{
	return Name_;
}

int				Form::getSignGrade(void) const
{
	return SignGrade_;
}

int				Form::getExecGrade(void) const
{
	return ExecGrade_;
}

bool			Form::getSigned(void) const
{
	return Signed_;
}

void			Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > this->SignGrade_)
		throw GradeTooLowException();
	this->Signed_ = 1;
}

char const*			Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

char const*			Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream&		operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", form status is " << form.getSigned();
	out << ", request grade to sign is " << form.getSignGrade();
	out << ", request grade is to exec is " << form.getExecGrade() << ".\n";

	return out;
}
