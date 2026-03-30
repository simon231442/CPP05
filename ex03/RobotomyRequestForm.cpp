#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include  <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	Target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
	}
	return (*this);
}

void		RobotomyRequestForm::action(void) const
{
	std::cout << "bzzzzbzzz.." << std::endl;
	if (std::rand() % 2)
		std::cout << Target_ << " has been robotomized." << std::endl;
	else
		std::cout << Target_ << ", the robotomy failed." << std::endl;
}

