#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iomanip>
#include <ctime>
#include <cstdlib>

int	main(void)
{
	std::srand(std::time(0));
	{
	Bureaucrat				kalif("le_kalif", 1);
	ShrubberyCreationForm	treeForm("green_parti");

	std::cout << "----------" << std::setw(43) << std::right << "Test 1 : signature et exec SUCCESS" << std::setw(8) << "" << "----------" << std::endl;
	std::cout << kalif << treeForm;
	kalif.executeForm(treeForm);
	kalif.signForm(treeForm);
	kalif.executeForm(treeForm);
	
	std::cout << std::endl;
	std::cout << "----------" << std::setw(43) << std::right << "Test 2 : exec FAILED" << std::setw(8) << "" << "----------" << std::endl;
	kalif.setGrade(146);
	std::cout << kalif << treeForm;
	kalif.signForm(treeForm);
	kalif.executeForm(treeForm);
	}

	{
		Bureaucrat			terminator("Terminator", 30);
		RobotomyRequestForm	robotForm("ElisaBorn");

		std::cout << std::endl;
		std::cout << "----------" << std::setw(43) << std::right << "Test 3 : Robotomy SUCCESS" << std::setw(8) << "" << "----------" << std::endl;
		std::cout << terminator << robotForm;
		terminator.signForm(robotForm);
		terminator.executeForm(robotForm);
		terminator.executeForm(robotForm);
		terminator.executeForm(robotForm);
		terminator.executeForm(robotForm);

		std::cout << std::endl;
		std::cout << "----------" << std::setw(43) << std::right << "Test 4 : Robotomy FAILED (grade)" << std::setw(8) << "" << "----------" << std::endl;
		Bureaucrat lowly("Lowly", 150);
		std::cout << lowly << robotForm;
		lowly.executeForm(robotForm);
	}
	return 0;
}
