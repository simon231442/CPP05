#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include  <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
	}
	return (*this);
}

void		PresidentialPardonForm::action(void) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
