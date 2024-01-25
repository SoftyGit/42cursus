#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& srcs)
	: AForm(srcs), _target(srcs._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& srcs) {
	static_cast<void>(srcs);
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->get_isSigned() == false)
		throw AForm::InvalidSignException();
	else if (executor.get_Grade() > this->get_execGrade())
		throw AForm::GradeTooLowException();
	std::srand(static_cast<unsigned int>(time(NULL)));
	std::cout << "JIIIIIIIIIIIING~~~~~~~JJJAAAAANG~~~BBOOOONNG" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
