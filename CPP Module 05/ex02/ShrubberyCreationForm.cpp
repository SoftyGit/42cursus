#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& srcs)
	: AForm(srcs), _target(srcs._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& srcs) {
	static_cast<void>(srcs);
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (this->get_isSigned() == false)
		throw AForm::InvalidSignException();
	else if (executor.get_Grade() > this->get_execGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file((this->_target + "_shrubbery").c_str());
	
	file << "                                             .\n";
	file << "								.         ;\n";
	file << "	.              .              ;%     ;;\n";
	file << "		,           ,                :;%  %;\n";
	file << "		:         ;                   :;%;'     .,\n";
	file << ",.        %;     %;            ;        %;'    ,;\n";
	file << ";       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	file << "%;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
	file << "	;%;      %;        ;%;        % ;%;  ,%;'\n";
	file << "	`%;.     ;%;     %;'         `;%%;.%;'\n";
	file << "	`:;%.    ;%%. %@;        %; ;@%;%'\n";
	file << "		`:%;.  :;bd%;          %;@%;'\n";
	file << "		`@%:.  :;%.         ;@@%;'\n";
	file << "			`@%.  `;@%.      ;@@%;\n";
	file << "			`@%%. `@%%    ;@@%;\n";
	file << "				;@%. :@%%  %@@%;\n";
	file << "				%@bd%%%bd%%:;\n";
	file << "					#@%%%%%:;;\n";
	file << "					%@@%%%::;\n";
	file << "					%@@@%(o);  . '\n";
	file << "					%@@@o%;:(.,'\n";
	file << "				`.. %@@@o%::;\n";
	file << "					`)@@@o%::;\n";
	file << "					%@@(o)::;\n";
	file << "					.%@@@@%::;\n";
	file << "					;%@@@@%::;.\n";
	file << "				;%@@@@%%:;;;.\n";
	file << "			...;%@@@@@%%:;;;;,..   \n";
    file.close();
}