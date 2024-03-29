#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	try {
		if (argc != 2)
			throw std::runtime_error("Error: could not open file.");
		Bitcoin BC(argv[1]);
	}
	catch(const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		exit(1);
	}
}