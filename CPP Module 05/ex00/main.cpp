#include "Bureaucrat.hpp"

int main() {
	///////////////////////////////////////////////
	std::cout << "TEST 1: no error" << std::endl;
	try {
		Bureaucrat bur1("yongjale", 1);
		std::cout << bur1 << std::endl;
	}
	catch (...) {
		std::cout << "An Exception is called" << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 2: grade 0" << std::endl;
	try {
		Bureaucrat bur2("yongjale", 0);
		std::cout << bur2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 3: grade 1->0" << std::endl;
	try {
		Bureaucrat bur3("yongjale", 1);
		std::cout << bur3 << std::endl;
		bur3.inc_Grade();
		std::cout << bur3 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 4: grade 151" << std::endl;
	try {
		Bureaucrat bur4("yongjale", 151);
		std::cout << bur4 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 5: grade 150->151" << std::endl;
	try {
		Bureaucrat bur5("yongjale", 150);
		std::cout << bur5 << std::endl;
		bur5.dec_Grade();
		std::cout << bur5 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 6: grade -3" << std::endl;
	try {
		Bureaucrat bur6("yongjale", -3);
		std::cout << bur6 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	std::cout << "TEST 7: copied grade 1->0" << std::endl;
	try {
		Bureaucrat bur7_org("yongjale", 1);
		Bureaucrat bur7(bur7_org);
		std::cout << bur7 << std::endl;
		bur7.inc_Grade();
		std::cout << bur7 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	///////////////////////////////////////////////
	return 0;
}