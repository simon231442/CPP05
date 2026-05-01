#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <exception>

class AForm;

class Intern {
	private :
	AForm*			makeShrubberyCreationForm(std::string const & target) const;
	AForm*			makeRobotomyRequestForm(std::string const & target) const;
	AForm*			makePresidentialPardonForm(std::string const & target) const;
	public :
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern&		operator=(Intern const & src);
		AForm*		makeForm(std::string const & formName, std::string const & target) const;

		class UnknownFormException : public std::exception {
			public :
				virtual const char*	what() const throw();
		};
};

#endif
