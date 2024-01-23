#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& srcs)
	: AForm(srcs), _target(srcs._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& srcs) {
	static_cast<void>(srcs);
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (this->get_isSigned() == false)
		throw AForm::InvalidSignException();
	else if (executor.get_Grade() > this->get_execGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
