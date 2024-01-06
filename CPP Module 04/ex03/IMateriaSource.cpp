#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
	std::cout << "IMateriaSource is created" << std::endl;
}
IMateriaSource::IMateriaSource(const IMateriaSource& srcs) {
	*this = srcs;
	std::cout << "IMateriaSource is copied" << std::endl;
}
IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& srcs) {
	(void) srcs;
	std::cout << "IMateriaSource assignment operator is called" << std::endl;
	return (*this);
}
