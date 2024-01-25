#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string _target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& srcs);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& srcs);

		void	execute(const Bureaucrat& executor) const;
};

#endif