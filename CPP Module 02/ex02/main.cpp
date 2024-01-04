#include "Fixed.hpp"
//#include <iomanip>

int	main(void) {
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;

	// std::cout << std::fixed << std::setprecision(20);
	// std::cout << 5.05f << std::endl;
	return 0;
}