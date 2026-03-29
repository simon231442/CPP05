#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
	protected :
		std::string const	Name_;
		bool				Signed_;
		int const			SignGrade_;
		int const			ExecGrade_;
	public :
		AForm();
		AForm(std::string const name, int const signed_grade, int const exec_grade);
		AForm(AForm const &src);
		~AForm();

		AForm&				operator=(AForm const &src);

		std::string const&	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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
