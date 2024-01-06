#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Total") {
	std::cout << "AAnimal:" << this->type << " is created" << std::endl; 
}
AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "AAnimal:" << this->type << " is created" << std::endl;
}
AAnimal::~AAnimal() {
	std::cout << "AAnimal:" << this->type << " is deleted" << std::endl;
}
AAnimal::AAnimal(const AAnimal& srcs) {
	*this = srcs;
	std::cout << "AAnimal:" << this->type << " is copied" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal&srcs) {
	if (this != &srcs)
		this->type = srcs.type;
	std::cout << "AAnimal assignment operator is called" << std::endl;
	return (*this);
}

std::string	AAnimal::getType() const{
	return (this->type);
}