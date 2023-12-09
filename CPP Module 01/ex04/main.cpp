#include "Sed.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "parameters error" << std::endl;
		return (1);
	}
	Sed NewSed(argv[1]);
	NewSed.replace(argv[2], argv[2]);
	return (0);
}