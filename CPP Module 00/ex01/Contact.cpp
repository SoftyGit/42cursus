#include "Contact.hpp"

Contact::Contact() {
}
Contact::~Contact() {
}

std::string Contact::_input(std::string str) const {
	std::string buf = "";
	while (1) {
		std::cout << str << std::flush;
		std::getline(std::cin, buf);
		if (std::cin.good() && !buf.empty())
			break ;
		else {
			if (std::cin.eof())
				exit(0);
			std::cin.clear();
			std::cout << "Invalid Input" << std::endl;
		}
	}
	return (buf);
}

void	Contact::init(void) {
	std::cin.ignore();
	this->_firstName = this->_input("First Name: ");
	this->_lastName = this->_input("Last Name: ");
	this->_nickname = this->_input("Nickname: ");
	this->_phoneNumber = this->_input("PhoneNumber: ");
	this->_darkestSecret = this->_input("DarkestSecret: ");
}

void	Contact::print(void) {
	if (this->_firstName.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->_firstName.substr(0, 9) + "." << std::flush;
	std::cout << "|" << std::setw(10) << this->_lastName.substr(0, 9) + "." << std::flush;
	std::cout << "|" << std::setw(10) << this->_nickname.substr(0, 9) + "." << std::endl;
}