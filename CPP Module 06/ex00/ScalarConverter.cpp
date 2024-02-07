#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& srcs) {
	*this = srcs;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& srcs) {
	static_cast<void>(srcs);
	return *this;
}

void	ScalarConverter::convert(const char& literal) {
	std::size_t		pos = 0;
	std::string		val_string(&literal);

	if (val_string == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (val_string == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (val_string == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (val_string == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (val_string == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (val_string == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}

	if (val_string.length() == 1 && std::isprint(val_string[0]) && !std::isdigit(val_string[0])) {
		std::cout << "char: " << static_cast<char>(val_string[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(val_string[0]) << std::endl;
		std::cout.precision(1);
		std::cout << std::fixed;
		std::cout << "float: " << static_cast<float>(val_string[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(val_string[0]) << std::endl;
		return ;
	}

	try {
		int	val_integer = std::stoi(val_string, &pos, 10);
		if ((val_integer >= 0 && val_integer < 256) && std::isprint(val_integer))
			std::cout << "char: " << static_cast<char>(val_integer) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << val_integer << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}

	std::cout.precision(1);
	std::cout << std::fixed;

	try {
		float		val_float = std::stof(val_string, &pos);

		std::cout << "float: " << val_float << "f" << std::endl;
	}
	catch (const std::out_of_range& e) {
		long int idx = strchr(val_string.c_str(), '-') - val_string.c_str();
		if (strchr(val_string.c_str(), '-') != NULL && idx <= static_cast<long int>(pos))
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "float: nanf" << std::endl;
	}

	try {
		double	val_double = std::stod(val_string, NULL);

		std::cout << "double: " << val_double << std::endl;
	}
	catch (const std::out_of_range& e) {
		long int idx = strchr(val_string.c_str(), '-') - val_string.c_str();
		if (strchr(val_string.c_str(), '-') != NULL && idx <= static_cast<long int>(pos))
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "double: nan" << std::endl;
	}

}
