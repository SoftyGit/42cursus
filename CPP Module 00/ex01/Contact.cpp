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