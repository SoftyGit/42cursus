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
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->_frationalBits);
}
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(
		roundf(value * (1 << this->_frationalBits))
	);
}
Fixed&	Fixed::operator=(const Fixed &srcs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &srcs)
		this->setRawBits(srcs.getRawBits());
	return *this;
}
int		Fixed::getRawBits(void) const {
	return this->_fixedPointNumberValue;
}
void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNumberValue = raw;
}
float	Fixed::toFloat(void) const {
	return static_cast<float>(this->getRawBits()) / (1 << this->_frationalBits);
}
int		Fixed::toInt(void) const {
	return this->_fixedPointNumberValue >> this->_frationalBits;
}
std::ostream& operator<<(std::ostream& out, Fixed const &value) {
	out << value.toFloat();
	return out;
}
