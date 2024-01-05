#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat is created" << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat is deleted" << std::endl;
}
void	WrongCat::makeSound() const {
	std::cout << "CHIPI CHIPI CHAPA CHAPA DUBI DUBI DABA DABA MAGICO MI DUBI DUBI BUM! BUM! BUM! BUM!" << std::endl;
}