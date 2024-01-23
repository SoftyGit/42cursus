#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	///////////////////////////////////////////////
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 1: no error" << std::endl;
	try {
		Bureaucrat	bur1("yongjale", 10);
		std::cout << bur1 << std::endl;
		Form		for1("42seoul", 15);
		std::cout << for1 << std::endl;
		std::cout << "--------------" << std::endl;
		for1.beSigned(bur1);
		std::cout << "--------------" << std::endl;
		std::cout << for1 << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 2: sign not enough in FORM" << std::endl;
	try {
		Bureaucrat	bur2("yongjale", 15);
		std::cout << bur2 << std::endl;
		Form		for2("42seoul", 10);
		std::cout << for2 << std::endl;
		std::cout << "--------------" << std::endl;
		for2.beSigned(bur2);
		std::cout << "--------------" << std::endl;
		std::cout << for2 << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 3: sign not enough in BUREAUCRAT" << std::endl;
	try {
		Bureaucrat	bur3("yongjale", 15);
		std::cout << bur3 << std::endl;
		Form		for3("42seoul", 10);
		std::cout << for3 << std::endl;
		std::cout << "--------------" << std::endl;
		bur3.signForm(for3);
		std::cout << "--------------" << std::endl;
		std::cout << for3 << std::endl;
	}
	catch (...) {
		std::cout << "ANOTHER ERROR" << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 4: sign enough in BUREAUCRAT" << std::endl;
	try {
		Bureaucrat	bur3("yongjale", 10);
		std::cout << bur3 << std::endl;
		Form		for3("42seoul", 10);
		std::cout << for3 << std::endl;
		std::cout << "--------------" << std::endl;
		bur3.signForm(for3);
		std::cout << "--------------" << std::endl;
		std::cout << for3 << std::endl;
	}
	catch (...) {
		std::cout << "ANOTHER ERROR" << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	return 0;
}
