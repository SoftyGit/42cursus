#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
	private:
		AForm();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;
	public:
		AForm(const std::string name, const int grade, const int exgrade);
		virtual ~AForm();
		AForm(const AForm& srcs);
		AForm& operator=(const AForm& srcs);

		std::string	get_Name() const;
		bool		get_isSigned() const;
		int			get_signGrade() const;
		int			get_execGrade() const;
		void		beSigned(Bureaucrat &srcs);
		
		virtual void	execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};
	class InvalidSignException : public std::exception {
		public:
			virtual const char* what(void) const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& srcs);

#endif
