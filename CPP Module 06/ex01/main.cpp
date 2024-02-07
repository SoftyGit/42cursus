#include "Serializer.hpp"

int main() {
	Data data;
	data.key = "yongjale"; data.value = 42;

	uintptr_t	a;
	Data		*b;

	b = &data;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "address: " << b << std::endl;
	std::cout << b->key << b->value << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	a = Serializer::serialize(b);
	std::cout << "address: " << "0x" << std::hex << a << std::dec << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	Data	*c = Serializer::deserialize(a);
	std::cout << "address: " << c << std::endl;
	std::cout << c->key << c->value << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}
