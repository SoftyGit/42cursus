#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <cstring>

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& srcs);
		ScalarConverter& operator=(const ScalarConverter& srcs);
		static void	convert(const char & literal);
};

#endif