#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& srcs) {
	*this = srcs;
}
Intern&	Intern::operator=(const Intern& srcs) {
	static_cast<void>(srcs);
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	std::string nameForm[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm*	forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	// find valid name
	int	i;
	for (i = 0; i < 3; i++)
		if (name == nameForm[i])
			break ;
	// delete except for return value
	for (int j = 0; j < 3; j++)
		if (i != j)
			delete forms[j];
	// throw after delete
	if (i == 3)
		throw InvalidNameException();
	// return exact value
	std::cout << "Intern creates " << forms[i]->get_Name() << std::endl;
	return forms[i];
}

const char*	Intern::InvalidNameException::what(void) const throw() {
	return "NO NAME FOUND";
}
