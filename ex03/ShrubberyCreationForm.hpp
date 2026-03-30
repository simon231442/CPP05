#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
# include <exception>

class ShrubberyCreationForm : public AForm {
	private :
		void					action(void) const;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& src);

};

#define BIEUTILFULLTREE \
"       _-_       \n" \
"    /~~   ~~\\    \n" \
" /~~         ~~\\ \n" \
"{               }\n" \
" \\  _-     -_  / \n" \
"   ~  \\\\ //  ~   \n" \
"_- -   | | _- _  \n" \
"  _ -  | |   -_  \n" \
"      // \\\\      \n"

#endif


