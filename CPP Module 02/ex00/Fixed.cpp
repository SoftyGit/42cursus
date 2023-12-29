#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &srcs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = srcs;
}
Fixed&	Fixed::operator=(const Fixed &srcs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &srcs)
		this->setRawBits(srcs.getRawBits());
	return *this;
}
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumberValue;
}
void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNumberValue = raw;
}