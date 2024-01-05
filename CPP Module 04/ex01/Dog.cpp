#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog is created" << std::endl;
	this->_brain = new Brain();
}
Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog is deleted" << std::endl;
}
void	Dog::makeSound() const {
	std::cout << "MONG! MONG!" << std::endl;
}

Dog::Dog(const Dog& srcs) : Animal(srcs){
	*this = srcs;
}
Dog& Dog::operator=(const Dog& srcs) {
	if (this != &srcs) {
		this->type = srcs.type;
		this->_brain = new Brain(*srcs._brain);
	}
	return (*this);
}