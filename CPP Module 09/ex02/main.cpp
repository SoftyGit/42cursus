#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	try {
		if (argc < 2)
			throw std::runtime_error("Error: Insufficient Argument");
	
		PList List(argv, static_cast<size_t>(argc) - 1);
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
}