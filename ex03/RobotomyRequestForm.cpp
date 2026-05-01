#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include  <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{}

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
		std::cout << getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << getTarget() << ", the robotomy failed." << std::endl;
}

