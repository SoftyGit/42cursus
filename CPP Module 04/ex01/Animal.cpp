#include "Animal.hpp"

Animal::Animal() : type("Total") {
	std::cout << "Animal:" << this->type << " is created" << std::endl; 
}
Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal:" << this->type << " is created" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal:" << this->type << " is deleted" << std::endl;
}
Animal::Animal(const Animal& srcs) {
	*this = srcs;
	std::cout << "Animal:" << this->type << " is copied" << std::endl;
}
Animal& Animal::operator=(const Animal&srcs) {
	if (this != &srcs)
		this->type = srcs.type;
	std::cout << "Animal assignment operator is called" << std::endl;
	return (*this);
}

void Animal::makeSound() const{
	std::cout << "Animal Sound!!" << std::endl;
}

std::string	Animal::getType() const{
	return (this->type);
}