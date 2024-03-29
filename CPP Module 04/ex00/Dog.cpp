#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog is created" << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog is deleted" << std::endl;
}
Dog::Dog(const Dog& srcs) : Animal(srcs) {
	*this = srcs;
	std::cout << "Dog is copied" << std::endl;
}
Dog& Dog::operator=(const Dog&srcs) {
	if (this != &srcs)
		this->type = srcs.type;
	std::cout << "Dog assignment operator is called" << std::endl;
	return (*this);
}
void	Dog::makeSound() const {
	std::cout << "MONG! MONG!" << std::endl;
}