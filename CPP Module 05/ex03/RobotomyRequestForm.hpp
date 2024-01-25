#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib> // rand function
# include <ctime> // rand function

class RobotomyRequestForm : public AForm {
	private:
		const std::string	_target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string _target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& srcs);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& srcs);

		void	execute(const Bureaucrat& executor) const;
};

#endif