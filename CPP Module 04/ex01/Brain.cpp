#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain is created" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "";
	}
}
Brain::~Brain() {
	std::cout << "Brain is deleted" << std::endl;
}
Brain::Brain(const Brain& srcs) {
	*this = srcs;
	std::cout << "Brain is copied" << std::endl;
}
Brain& Brain::operator=(const Brain& srcs) {
	if (this != &srcs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = srcs.ideas[i];
		}
	}
	std::cout << "Brain assignment operator is called" << std::endl;
	return (*this);
}