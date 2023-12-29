#include "Fixed.hpp"

Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}
Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &srcs) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = srcs;
}
Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->_frationalBits);
}
Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits(
		roundf(value * (1 << this->_frationalBits))
	);
}
Fixed&	Fixed::operator=(const Fixed &srcs) {
	//std::cout << "Copy assignment operator called" << std::endl;
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

// Comparison Operators //
bool	Fixed::operator>(const Fixed &srcs) const {
	return (this->getRawBits() > srcs.getRawBits());
}
bool	Fixed::operator<(const Fixed &srcs) const {
	return (this->getRawBits() < srcs.getRawBits());
}
bool	Fixed::operator>=(const Fixed &srcs) const {
	return (this->getRawBits() >= srcs.getRawBits());
}
bool	Fixed::operator<=(const Fixed &srcs) const {
	return (this->getRawBits() <= srcs.getRawBits());
}
bool	Fixed::operator==(const Fixed &srcs) const {
	return (this->getRawBits() == srcs.getRawBits());
}
bool	Fixed::operator!=(const Fixed &srcs) const {
	return (this->getRawBits() != srcs.getRawBits());
}
// Arithmetic Operators //
Fixed	Fixed::operator+(const Fixed &srcs) const {
	return Fixed(this->toFloat() + srcs.toFloat());
}
Fixed	Fixed::operator-(const Fixed &srcs) const {
	return Fixed(this->toFloat() - srcs.toFloat());
}
Fixed	Fixed::operator*(const Fixed &srcs) const {
	return Fixed(this->toFloat() * srcs.toFloat());
}
Fixed	Fixed::operator/(const Fixed &srcs) const {
	return Fixed(this->toFloat() / srcs.toFloat());
}
// IncreMent/Decrement //
Fixed&	Fixed::operator++(void) {
	++this->_fixedPointNumberValue;
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_fixedPointNumberValue++;
	return tmp;
}
Fixed&	Fixed::operator--(void) {
	--this->_fixedPointNumberValue;
	return (*this);
}
Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_fixedPointNumberValue--;
	return tmp;
}
// Min/Max //
Fixed&			Fixed::min(Fixed &a, Fixed &b) {
	if (a > b)
		return b;
	return a;
}
const Fixed&	Fixed::min(const Fixed &a, const Fixed &b) {
	if (a > b)
		return b;
	return a;
}
Fixed&			Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}
const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}