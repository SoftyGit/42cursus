#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter is created" << std::endl;
}
ICharacter::ICharacter(const ICharacter& srcs) {
	*this = srcs;
	std::cout << "ICharacter is copied" << std::endl;
}
ICharacter&	ICharacter::operator=(const ICharacter& srcs) {
	(void) srcs;
	std::cout << "ICharacter assignment operator is called" << std::endl;
	return (*this);
}
