#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
}
PhoneBook::~PhoneBook(){
}

void	PhoneBook::add(void) {
	static int	i = 0;
	this->_contact[i].init();
}



void	PhoneBook::search(void) {

}