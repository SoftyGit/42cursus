#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat is created" << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat is deleted" << std::endl;
}
WrongCat::WrongCat(const WrongCat& srcs) : WrongAnimal(srcs) {
	*this = srcs;
	std::cout << "WrongCat is copied" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat&srcs) {
	if (this != &srcs)
		this->type = srcs.type;
	std::cout << "WrongCat assignment operator is called" << std::endl;
	return (*this);
}
void	WrongCat::makeSound() const {
	std::cout << "CHIPI CHIPI CHAPA CHAPA DUBI DUBI DABA DABA MAGICO MI DUBI DUBI BUM! BUM! BUM! BUM!" << std::endl;
}