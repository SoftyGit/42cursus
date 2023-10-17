#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void) {
	PhoneBook pb;
	std::string	cmd;
	while (1) {
		std::cout << "INPUT: ";
		std::cin >> cmd;
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.init();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "discarded" << std::endl;
	}
	return (0);
}