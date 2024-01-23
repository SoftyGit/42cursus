#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form {
	private:
		Form();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;
	public:
		Form(const std::string name, const int grade);
		~Form();
		Form(const Form& srcs);
		Form& operator=(const Form& srcs);

		std::string	get_Name() const;
		bool		get_isSigned() const;
		int			get_signGrade() const;
		int			get_execGrade() const;
		void		beSigned(Bureaucrat &srcs);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& srcs);

#endif
