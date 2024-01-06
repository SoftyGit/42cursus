#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria is created" << std::endl;
}
AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "AMateria is created" << std::endl;
}
AMateria::~AMateria() {
	std::cout << "AMateria is deleted" << std::endl;
}

AMateria::AMateria(const AMateria& srcs) {
	*this = srcs;
	std::cout << "AMateria is copied" << std::endl;
}
AMateria&	AMateria::operator=(const AMateria& srcs) {
	this->_type = srcs._type;
	std::cout << "AMateria assignment operator is called" << std::endl;
	return (*this);
}

const std::string& AMateria::getType() const {
	return (this->_type);
}

void 	AMateria::use(ICharacter& target) {
	(void)target;
}
