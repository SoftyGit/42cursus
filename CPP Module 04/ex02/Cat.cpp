#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat is created" << std::endl;
	this->_brain = new Brain();
	this->_brain->ideas[0] = "CHIPI CHIPI??";
}
Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat is deleted" << std::endl;
}
Cat::Cat(const Cat& srcs) : AAnimal(srcs){
	*this = srcs;
	std::cout << "Cat is copied" << std::endl;
}
Cat& Cat::operator=(const Cat& srcs) {
	if (this != &srcs) {
		this->type = srcs.type;
		this->_brain = new Brain(*srcs._brain);
	}
	std::cout << "Cat assignment operator is called" << std::endl;
	return (*this);
}
void	Cat::makeSound() const {
	std::cout << "CHIPI CHIPI CHAPA CHAPA DUBI DUBI DABA DABA MAGICO MI DUBI DUBI BUM! BUM! BUM! BUM!" << std::endl;
}
std::string	Cat::getIdea() const {
	return (this->_brain->ideas[0]);
}