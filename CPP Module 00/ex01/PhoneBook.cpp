#include "PhoneBook.hpp"

int PhoneBook::_index = 0;

PhoneBook::PhoneBook(){
}
PhoneBook::~PhoneBook(){
}

void	PhoneBook::add(void) {
	this->_contact[_index % 8].init();
	_index++;	
}

void	PhoneBook::search(void) {
	int	index;

	std::cout << "<<PhoneBook>>" << std::endl;
	for (int i = 0; i < _index && i < 8; i++)
	{
		std::cout << std::setw(10) << i << std::flush;
		this->_contact[i].print();
	}
	std::cout << "INDEX: " << std::flush;
	std::cin >> index;
	if (index < _index && index >= 0 && index < 8 && std::cin.good())
		this->_contact[index].print();
	else
	{
		if (std::cin.eof())
			exit(0);
		std::cin.clear();
		// ignore all last input in current line, and move next line
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "discarded" << std::endl;
	}
}
