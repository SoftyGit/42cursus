#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure is created" << std::endl;
}
Cure::~Cure() {
	std::cout << "Cure is deleted" << std::endl;
}

Cure::Cure(const Cure& srcs) : AMateria(srcs) {
	*this = srcs;
	std::cout << "Cure is copied" << std::endl;
}
Cure& Cure::operator=(const Cure& srcs) {
	if (this != &srcs) {
		this->_type = srcs._type;
	}
	std::cout << "Cure assignment operator is called" << std::endl;
	return (*this);
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}
void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}
