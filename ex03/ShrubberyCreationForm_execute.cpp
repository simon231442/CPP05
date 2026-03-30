#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

void		ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		// You might want to define a FormNotSignedException, but for now we won't execute if not signed
		return;

	std::ofstream file((Target_ + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << BIEUTILFULLTREE << std::endl;
		file.close();
	}
}


	

