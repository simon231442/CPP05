#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : Name_("default"), Signed_(0), SignGrade_(1), ExecGrade_(1)
{
}

AForm::AForm(std::string const name, int const signed_grade, int const exec_grade) :
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

AForm::AForm(AForm const &src) :
	Name_(src.Name_),
	Signed_(src.Signed_),
	SignGrade_(src.SignGrade_),
	ExecGrade_(src.ExecGrade_)
{
}

AForm::~AForm()
{
}

AForm&				AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->Signed_ = src.Signed_;	
	return *this;
}

std::string const&	AForm::getName(void) const
{
	return Name_;
}

int					AForm::getSignGrade(void) const
{
	return SignGrade_;
}

int					AForm::getExecGrade(void) const
{
	return ExecGrade_;
}

bool				AForm::getSigned(void) const
{
	return Signed_;
}

void				AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > this->SignGrade_)
		throw GradeTooLowException();
	this->Signed_ = 1;
}
  
void				AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw NotSignedException();
	this->action();
}

char const*			AForm::NotSignedException::what() const throw()
{
	return "form isn't signed";
}

char const*			AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

char const*			AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream&		operator<<(std::ostream &out, AForm const &form)
{
	out << form.getName() << ", form status is " << form.getSigned();
	out << ", request grade to sign is " << form.getSignGrade();
	out << ", request grade is to exec is " << form.getExecGrade() << ".\n";

	return out;
}

