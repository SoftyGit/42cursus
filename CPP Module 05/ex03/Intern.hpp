#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern& srcs);
		Intern&	operator=(const Intern& srcs);

		AForm*	makeForm(std::string name, std::string target);
		
		class InvalidNameException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};
};

#endif