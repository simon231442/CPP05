#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat {
	private :
		std::string const	Name_;
		int					Grade_;
	public :
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat&			operator=(Bureaucrat const &src);

		std::string const&	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form);
		
		class GradeTooHighException : public std::exception {
			public :
				virtual char const	*what() const throw();
				};
		class GradeTooLowException : public std::exception {
			public :
				virtual char const	*what() const throw();
				};

		void				setGrade(int Grade);
		};

std::ostream&		operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
