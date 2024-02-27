#include "RPN.hpp"

int main(int argc, char** argv) {
	try {
		if (argc != 2)
			throw std::runtime_error("Error: No Argument");
		std::string exp(argv[1]);
		Calculate cal;
		for (std::string::iterator it = exp.begin(); it != exp.end(); it++) {
			if (*it == ' ')
				continue;
			else if (std::isdigit(*it)){
				cal.Push(*it - '0');
			}
			else if (*it == '+')
				cal.Operate(PLUS);
			else if (*it == '-')
				cal.Operate(SUB);
			else if (*it == '*')
				cal.Operate(MUL);
			else if (*it == '/')
				cal.Operate(DIV);
			else
				throw std::runtime_error("Error: Invalid Operator");
		}
		cal.Finish();
	}
	catch(const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		exit(1);
	}
}