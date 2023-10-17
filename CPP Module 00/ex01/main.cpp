#include <iostream>
int	main(void)
{
	std::string	cmd;
	while (1)
	{
		std::cout << "INPUT: ";
		std::cin >> cmd;
		if (cmd == "ADD")
		else if (cmd == "SEARCH")
		else if (cmd == "EXIT")
		else
			std::cout << "discarded" << std::endl;
	}
}