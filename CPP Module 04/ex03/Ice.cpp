#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice is created" << std::endl;
}
Ice::~Ice() {
	std::cout << "Ice is deleted" << std::endl;
}

Ice::Ice(const Ice& srcs) : AMateria(srcs) {
	*this = srcs;
	std::cout << "Ice is copied" << std::endl;
}
Ice& Ice::operator=(const Ice& srcs) {
	if (this != &srcs) {
		this->_type = srcs._type;
	}
	std::cout << "Ice assignment operator is called" << std::endl;
	return (*this);
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}
void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}
