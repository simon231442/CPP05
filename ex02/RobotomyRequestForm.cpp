#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include  <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), Target_("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), Target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src), Target_(src.Target_)
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
		this->Target_ = src.Target_;
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

