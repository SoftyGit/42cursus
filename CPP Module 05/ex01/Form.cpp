#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int grade) : _name(name), _signGrade(grade), _execGrade(0) {
	this->_isSigned = false;
	if (grade < 1)
		throw Form::GradeTooLowException();
	else if (grade > 150)
		throw Form::GradeTooHighException();
}
Form::~Form() {}
Form::Form(const Form& srcs) :
	_name(srcs._name), _signGrade(srcs._signGrade), _execGrade(srcs._execGrade){
	*this = srcs;
}
Form& Form::operator=(const Form& srcs) {
	if (this != &srcs)
		this->_isSigned = srcs.get_isSigned();
	return *this;
}
std::string	Form::get_Name() const {
	return this->_name;
}
bool		Form::get_isSigned() const {
	return this->_isSigned;
}
int			Form::get_signGrade() const {
	return this->_signGrade;
}
int			Form::get_execGrade() const {
	return this->_execGrade;
}		
const char	*Form::GradeTooHighException::what(void) const throw() {
	return "GRADE TOO HIGH!";
}
const char	*Form::GradeTooLowException::what(void) const throw() {
	return "GRADE TOO LOW";
}

void		Form::beSigned(Bureaucrat &srcs) {
	if (this->_signGrade < srcs.get_Grade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& srcs) {
	os << "Name: " << srcs.get_Name() << std::endl;
	os << std::boolalpha << "isSigned: " << srcs.get_isSigned() << std::endl;
	os << "signGrade: " << srcs.get_signGrade() << std::endl;
	os << "execGrade: " << srcs.get_execGrade();

	return os;
}
