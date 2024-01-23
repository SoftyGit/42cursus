#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	///////////////////////////////////////////////
	std::cout << "TEST 1: no error" << std::endl;
	try {
		Bureaucrat	bur1("yongjale", 10);
		std::cout << bur1 << std::endl;
		Form		for1("42seoul", 5);
		std::cout << for1 << std::endl;
		for1.beSigned(bur1);
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 2: sign not enough in FORM" << std::endl;
	try {
		Bureaucrat	bur2("yongjale", 10);
		std::cout << bur2 << std::endl;
		Form		for2("42seoul", 15);
		std::cout << for2 << std::endl;
		for2.beSigned(bur2);
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 3: sign not enough in BUREAUCRAT" << std::endl;
	try {
		Bureaucrat	bur3("yongjale", 10);
		std::cout << bur3 << std::endl;
		Form		for3("42seoul", 15);
		std::cout << for3 << std::endl;
		bur3.signForm(for3);
	}
	catch (...) {
		std::cout << "ANOTHER ERROR" << std::endl;
	}
	return 0;
}
