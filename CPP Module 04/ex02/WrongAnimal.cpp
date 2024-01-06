#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Total") {
	std::cout << "WrongAnimal:" << this->type << " is created" << std::endl; 
}
WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal:" << this->type << " is created" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal:" << this->type << " is deleted" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& srcs) {
	*this = srcs;
	std::cout << "WrongAnimal:" << this->type << " is copied" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal&srcs) {
	if (this != &srcs)
		this->type = srcs.type;
	std::cout << "WrongAnimal assignment operator is called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal Sound!!" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return (this->type);
}