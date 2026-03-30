#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iomanip>

int	main(void)
{
	Intern		larbin;
	Bureaucrat	vincent("vincent", 1);
	AForm*		formPtr = NULL;

	{
		std::cout << "----------" << std::setw(43) << std::right << "Test 1 : \"shrubbery creation\"" << std::setw(8) << "" << "----------" << std::endl;
		try	
		{
			formPtr = larbin.makeForm("shrubbery creation", "Aliens");
			vincent.signForm(*formPtr);
			vincent.executeForm(*formPtr);
		}
		catch (std::exception & e)
		{
			std::cout << vincent.getName() << " couldn't execute the form intern report : " << e.what() << std::endl;
		}
		delete formPtr;
		formPtr = NULL;
	}

	{
		std::cout << "----------" << std::setw(43) << std::right << "Test 2 : \"robotomy request\"" << std::setw(8) << "" << "----------" << std::endl;
		try	
		{
			formPtr = larbin.makeForm("robotomy request", "Aliens");
			vincent.signForm(*formPtr);
			vincent.executeForm(*formPtr);
		}
		catch (std::exception & e)
		{
			std::cout << vincent.getName() << " couldn't execute the form intern report : " << e.what() << std::endl;
		}
		delete formPtr;
		formPtr = NULL;
	}

	{
		std::cout << "----------" << std::setw(43) << std::right << "Test 3 : \"presidential pardon\"" << std::setw(8) << "" << "----------" << std::endl;
		try	
		{
			formPtr = larbin.makeForm("presidential pardon", "Aliens");
			vincent.signForm(*formPtr);
			vincent.executeForm(*formPtr);
		}
		catch (std::exception & e)
		{
			std::cout << vincent.getName() << " couldn't execute the form intern report : " << e.what() << std::endl;
		}
		delete formPtr;
		formPtr = NULL;
	}

	{
		std::cout << "----------" << std::setw(43) << std::right << "Test 4 : \"unknown action\"" << std::setw(8) << "" << "----------" << std::endl;
		try	
		{
			formPtr = larbin.makeForm("unknown action", "Aliens");
			if (formPtr)
			{
				vincent.signForm(*formPtr);
				vincent.executeForm(*formPtr);
			}
		}
		catch (std::exception & e)
		{
			std::cout << vincent.getName() << " couldn't execute the form intern report : " << e.what() << std::endl;
		}
		delete formPtr;
		formPtr = NULL;
	}

	return (0);
}
