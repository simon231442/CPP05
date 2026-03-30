#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), Target_("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), Target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src), Target_(src.Target_)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
	if (this != &src)
	{
		this->AForm::operator=(src);
		this->Target_ = src.Target_;
	}
	return (*this);
}

void		ShrubberyCreationForm::action(void) const
{
	std::ofstream file((Target_ + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << BIEUTILFULLTREE << std::endl;
		file.close();
	}
}

