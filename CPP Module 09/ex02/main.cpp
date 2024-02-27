#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	try {
		if (argc < 2)
			throw std::runtime_error("Error: Insufficient Argument");
	
		PList p_list(argc, argv);
		std::list<size_t> sortList = p_list.getSortList();
		for (std::list<size_t>::iterator it = sortList.end(); it != sortList.begin(); it--)
			std::cout << *it << " ";
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
}