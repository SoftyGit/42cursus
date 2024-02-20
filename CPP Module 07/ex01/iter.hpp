#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* addr, size_t length, void (*func)(T&)) {
	for (size_t i = 0; i < length; i++)
		func(addr[i]);
}
template <typename T>
void print(T& str) {
	std::cout << str << std::endl;
}
#endif

