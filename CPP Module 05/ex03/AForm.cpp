#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int grade, const int exgrade) : _name(name), _signGrade(grade), _execGrade(exgrade) {
	this->_isSigned = false;
	if (grade < 1)
		throw AForm::GradeTooLowException();
	else if (grade > 150)
		throw AForm::GradeTooHighException();
}
AForm::~AForm() {}
AForm::AForm(const AForm& srcs) :
	_name(srcs._name), _signGrade(srcs._signGrade), _execGrade(srcs._execGrade){
	*this = srcs;
}
AForm& AForm::operator=(const AForm& srcs) {
	if (this != &srcs)
		this->_isSigned = srcs.get_isSigned();
	return *this;
}
std::string	AForm::get_Name() const {
	return this->_name;
}
bool		AForm::get_isSigned() const {
	return this->_isSigned;
}
int			AForm::get_signGrade() const {
	return this->_signGrade;
}
int			AForm::get_execGrade() const {
	return this->_execGrade;
}		
const char	*AForm::GradeTooHighException::what(void) const throw() {
	return "GRADE TOO HIGH!";
}
const char	*AForm::GradeTooLowException::what(void) const throw() {
	return "GRADE TOO LOW";
}
const char	*AForm::InvalidSignException::what(void) const throw() {
	return "NO VALID SIGN";
}

void		AForm::beSigned(Bureaucrat &srcs) {
	if (this->_signGrade < srcs.get_Grade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& srcs) {
	os << "Name: " << srcs.get_Name() << std::endl;
	os << std::boolalpha << "isSigned: " << srcs.get_isSigned() << std::endl;
	os << "signGrade: " << srcs.get_signGrade() << std::endl;
	os << "execGrade: " << srcs.get_execGrade();

	return os;
}
