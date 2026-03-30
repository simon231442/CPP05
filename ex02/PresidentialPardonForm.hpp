#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

class PresidentialPardonForm : public AForm {
	private :
		std::string				Target_;
		void					action(void) const;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(PresidentialPardonForm const& src);

};

#endif


