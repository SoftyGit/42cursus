#include "Serializer.hpp"

Serializer::~Serializer() {}
Serializer::Serializer(const Serializer& srcs) {
	*this = srcs;
}
Serializer& Serializer::operator=(const Serializer& srcs) {
	static_cast<void>(srcs);
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
