#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	private:
		Bureaucrat();
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& srcs);
		Bureaucrat& operator=(const Bureaucrat& srcs);
		
		std::string	get_Name() const;
		int			get_Grade() const;
		void		inc_Grade();
		void		dec_Grade();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw(); 
				// c++11 noexcept
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
				// c++11 noexcept
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& srcs);

#endif