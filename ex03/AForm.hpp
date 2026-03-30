#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	protected :
		std::string const	Name_;
		std::string			Target_;
		bool				Signed_;
		int const			SignGrade_;
		int const			ExecGrade_;
		virtual void		action(void) const = 0;
	public :
		AForm();
		AForm(std::string const name, std::string const target);
		AForm(std::string const name, int const signed_grade, int const exec_grade);
		AForm(AForm const &src);
		virtual ~AForm();

		AForm&				operator=(AForm const &src);

		std::string const&	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const& bureaucrat);
		void				execute(Bureaucrat const & executor) const;

		class NotSignedException : public std::exception {
			public :
				virtual char const	*what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public :
				virtual char const	*what() const throw();
			};

		class GradeTooLowException : public std::exception {
			public :
				virtual char const	*what() const throw();
			};
		};

std::ostream&	operator<<(std::ostream &out, AForm const &form);

#endif
