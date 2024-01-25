#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 0: no error" << std::endl;
	try {
		Bureaucrat bur("yongjale", 10);
		ShrubberyCreationForm shr("HOLY");
		RobotomyRequestForm rob("MOLY");
		PresidentialPardonForm pre("HOLYMOLY");
		std::cout << bur << std::endl;
		std::cout << shr << std::endl;
		std::cout << rob << std::endl;
		std::cout << pre << std::endl;
	}
	catch (...) {
		std::cout << "It seems to be NON_ERROR" << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 1: no sign" << std::endl;
	try {
		Bureaucrat bur("yongjale", 10);
		ShrubberyCreationForm shr("HOLY");

		shr.execute(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 2: valid sign in ShrubberyCration" << std::endl;
	try {
		Bureaucrat bur("yongjale", 1);
		ShrubberyCreationForm shr("HOLY");

		bur.signForm(shr);
		shr.execute(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 3: valid sign in RobotomyRequest" << std::endl;
	try {
		Bureaucrat bur("yongjale", 1);
		RobotomyRequestForm rob("MOLY");

		bur.signForm(rob);
		rob.execute(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 4: valid sign but low grade in PresidentialPardon" << std::endl;
	try {
		Bureaucrat bur("yongjale", 6);
		PresidentialPardonForm pre("MOLY");

		bur.signForm(pre);
		pre.execute(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 5: valid sign & valid grade in PresidentialPardon" << std::endl;
	try {
		Bureaucrat bur("yongjale", 5);
		PresidentialPardonForm pre("MOLY");

		bur.signForm(pre);
		pre.execute(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 6: no error in excuteForm" << std::endl;
	try {
		Bureaucrat bur("yongjale", 5);
		PresidentialPardonForm pre("MOLY");

		bur.signForm(pre);
		bur.executeForm(pre);
	}
	catch (...) {
		std::cout << "It seems to be NON_ERROR" << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 7: invalid sign in excuteForm" << std::endl;
	try {
		Bureaucrat bur("yongjale", 5);
		PresidentialPardonForm pre("MOLY");

		bur.executeForm(pre);
	}
	catch (...) {
		std::cout << "It seems to be NON_ERROR" << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 8: valid sign & invalid grade in excuteForm" << std::endl;
	try {
		Bureaucrat bur("yongjale", 6);
		PresidentialPardonForm pre("MOLY");

		bur.signForm(pre);
		bur.executeForm(pre);
	}
	catch (...) {
		std::cout << "It seems to be NON_ERROR" << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	return 0;
}