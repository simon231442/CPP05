#include "Bureaucrat.hpp"
#include <iomanip>

int	main(void)
{
	Bureaucrat	Apayot = Bureaucrat("Apayot", 75);

	std::cout << "----------" << std::internal << std::setw(51) << "Test 1 : incrementation et decrementation dans les limites" << "----------" << std::endl;

	std::cout << std::left << std::setw(30) << "avec grade d'initialisation" << ": " << Apayot;
	try 
	{
		Apayot.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "cette ligne ne s'affichera pas";
	}
	std::cout << std::left << std::setw(30) << "Apres incremenatation" << ": " << Apayot;

	try 
	{
		Apayot.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "cette ligne ne s'affichera pas";
	}
	std::cout << std::left << std::setw(30) << "Apres decremenatation" << ": " << Apayot;

	std::cout << std::endl;
	std::cout << "----------" << std::setw(43) << std::right << "Test 2 : incrementation hors limite" << std::setw(8) << "" << "----------" << std::endl;
	Apayot.setGrade(1);
	std::cout << std::left << std::setw(30) << "Avec grade mis a 1" << ": " << Apayot;
	try 
	{
		Apayot.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "error is : " << e.what() << std::endl;
	}
	std::cout << std::left << std::setw(30) << "Apres incremenatation" << ": " << Apayot << std::endl;

	std::cout << "----------" << std::setw(43) << std::right << "Test 3 : decrementation hors limite" << std::setw(8) << "" << "----------" << std::endl;
	Apayot.setGrade(150);
	std::cout << std::left << std::setw(30) << "Avec grade mis a 150" << ": " << Apayot;
	try 
	{
		Apayot.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "error is : " << e.what() << std::endl;
	}
	std::cout << std::left << std::setw(30) << "Apres decremenatation" << ": " << Apayot << std::endl;

	return 0;
}


