#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
	private :
		std::string const	Name_;
		bool				Signed_;
		int const			SignGrade_;
		int const			ExecGrade_;
	public :
		Form();
		Form(std::string const name, int const signed_grade, int const exec_grade);
		Form(Form const &src);
		~Form();

		Form&				operator=(Form const &src);

		std::string const&	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const& bureaucrat);

		class GradeTooHighException : public std::exception {//pourquoi public??
			public :
				virtual char const	*what() const throw();//pourquoi virtual??
			};
		class GradeTooLowException : public std::exception {
			public :
				virtual char const	*what() const throw();
			};
		};

std::ostream&	operator<<(std::ostream &out, Form const &form);//comment faire pour distinguer les 2 surcharges??

#endif
