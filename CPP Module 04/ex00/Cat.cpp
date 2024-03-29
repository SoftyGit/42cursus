#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat is created" << std::endl;
}
Cat::~Cat() {
	std::cout << "Cat is deleted" << std::endl;
}
Cat::Cat(const Cat& srcs) : Animal(srcs) {
	*this = srcs;
	std::cout << "Cat is copied" << std::endl;
}
Cat& Cat::operator=(const Cat&srcs) {
	if (this != &srcs)
		this->type = srcs.type;
	std::cout << "Cat assignment operator is called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "CHIPI CHIPI CHAPA CHAPA DUBI DUBI DABA DABA MAGICO MI DUBI DUBI BUM! BUM! BUM! BUM!" << std::endl;
}