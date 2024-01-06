#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog is created" << std::endl;
	this->_brain = new Brain();
	this->_brain->ideas[0] = "DOGI COIN~ LET'S GO~!";
}
Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog is deleted" << std::endl;
}
Dog::Dog(const Dog& srcs) : AAnimal(srcs){
	*this = srcs;
	std::cout << "Dog is copied" << std::endl;
}
Dog& Dog::operator=(const Dog& srcs) {
	if (this != &srcs) {
		this->type = srcs.type;
		this->_brain = new Brain(*srcs._brain);
	}
	std::cout << "Dog assignment operator is called" << std::endl;
	return (*this);
}
void	Dog::makeSound() const {
	std::cout << "MONG! MONG!" << std::endl;
}
std::string	Dog::getIdea() const {
	return (this->_brain->ideas[0]);
}
