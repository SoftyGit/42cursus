#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int	grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& srcs) : _name(srcs._name) {
	*this = srcs;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& srcs) {
	if (this != &srcs)
		this->_grade = srcs._grade;
	return *this;
}

std::string	Bureaucrat::get_Name() const {
	return this->_name;
}
int			Bureaucrat::get_Grade() const {
	return this->_grade;
}
void		Bureaucrat::inc_Grade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}
void		Bureaucrat::dec_Grade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade += 1;
}
const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "GRADE TOO HIGH!";
}
const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "GRADE TOO LOW!";
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& srcs) {
	os << srcs.get_Name() << ", bureaucrat grade "
		<< srcs.get_Grade() << ".";
	return os;
}
