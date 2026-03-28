#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

int	main(void)
{
	Bureaucrat	Apayot = Bureaucrat("Apayot", 75);
	Form		J42shitform = Form("J42shitform", 80, 1);

	std::cout << "----------" << std::setw(43) << std::right << "Test 1 : signature avec grade suffisant" << std::setw(8) << "" << "----------" << std::endl;
	std::cout << Apayot;
	std::cout << J42shitform;
	Apayot.signForm(J42shitform);
	std::cout << J42shitform;
	
	std::cout << std::endl;
	std::cout << "----------" << std::setw(43) << std::right << "Test 1 : signature avec grade insuffisant" << std::setw(8) << "" << "----------" << std::endl;
	Apayot.setGrade(81);
	std::cout << Apayot;
	std::cout << J42shitform;
	Apayot.signForm(J42shitform);
	std::cout << J42shitform;

	return 0;
}
