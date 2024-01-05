#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog is created" << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog is deleted" << std::endl;
}
void	Dog::makeSound() const {
	std::cout << "MONG! MONG!" << std::endl;
}