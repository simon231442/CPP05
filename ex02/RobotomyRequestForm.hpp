#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

class RobotomyRequestForm : public AForm {
	private :
		std::string				Target_;
		void					action(void) const;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(RobotomyRequestForm const& src);

};

#endif


