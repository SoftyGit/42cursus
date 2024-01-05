#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat is created" << std::endl;
}
Cat::~Cat() {
	std::cout << "Cat is deleted" << std::endl;
}
void	Cat::makeSound() const {
	std::cout << "CHIPI CHIPI CHAPA CHAPA DUBI DUBI DABA DABA MAGICO MI DUBI DUBI BUM! BUM! BUM! BUM!" << std::endl;
}