#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat is created" << std::endl;
	this->_brain = new Brain();
}
Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat is deleted" << std::endl;
}
void	Cat::makeSound() const {
	std::cout << "CHIPI CHIPI CHAPA CHAPA DUBI DUBI DABA DABA MAGICO MI DUBI DUBI BUM! BUM! BUM! BUM!" << std::endl;
}

Cat::Cat(const Cat& srcs) : Animal(srcs){
	*this = srcs;
}
Cat& Cat::operator=(const Cat& srcs) {
	if (this != &srcs) {
		this->type = srcs.type;
		this->_brain = new Brain(*srcs._brain);
	}
	return (*this);
}