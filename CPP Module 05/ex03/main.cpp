#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 0: no error" << std::endl;
	try {
		Bureaucrat	bur("yongjale", 5);
		Intern	rri;
		AForm	*rrf1, *rrf2, *rrf3;

		rrf1 = rri.makeForm("robotomy request", "Bender");
		rrf1->beSigned(bur);
		rrf1->execute(bur);
		rrf2 = rri.makeForm("shrubbery creation", "Nice");
		rrf2->beSigned(bur);
		rrf2->execute(bur);
		rrf3 = rri.makeForm("presidential pardon", "Good");
		rrf3->beSigned(bur);
		rrf3->execute(bur);
		delete rrf1;
		delete rrf2;
		delete rrf3;
	}
	catch (...) {
		std::cout << "It seems to be NON_ERROR" << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "TEST 1: invalid name" << std::endl;
	try {
		Bureaucrat	bur("yongjale", 5);
		Intern	rri;
		AForm	*rrf;

		rrf = rri.makeForm("robot", "Bender");
		rrf->beSigned(bur);
		rrf->execute(bur);
		delete rrf;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;

	return 0;
}
