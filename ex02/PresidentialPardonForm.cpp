#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include  <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), Target_("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), Target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src), Target_(src.Target_)
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
		this->Target_ = src.Target_;
	}
	return (*this);
}

void		PresidentialPardonForm::action(void) const
{
	std::cout << Target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
