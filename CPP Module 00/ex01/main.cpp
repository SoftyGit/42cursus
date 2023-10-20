#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int	main(void) {
	PhoneBook pb;
	std::string	cmd;
	while (1) {
		std::cout << "INPUT: ";
		std::cin >> cmd;
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "discarded" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}