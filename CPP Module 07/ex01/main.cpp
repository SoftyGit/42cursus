#include "iter.hpp"

int main() {
	std::cout << "--TEST1----------------------------" << std::endl;
	int a[8];
	for (int i = 0; i < 8; i++)
		a[i] = i;
	::iter(a, 8, print);

	std::cout << "--TEST2----------------------------" << std::endl;
	double d[8];
	for (int i = 0; i < 8; i++)
		d[i] = 0.1 + i;
	::iter(d, 8, print);

	std::cout << "--TEST3----------------------------" << std::endl;
	char b[8];
	for (int i = 0; i < 8; i++)
		b[i] = static_cast<char>(97 + i);
	::iter(b, 8, print);

	std::cout << "--TEST4----------------------------" << std::endl;
	bool c[8];
	for (int i = 0; i < 8; i++){
		if (i % 2)
			c[i] = true;
		else
			c[i] = false;
	}
	::iter(c, 8, print);

	return 0;
}