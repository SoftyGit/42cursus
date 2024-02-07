#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data {
	std::string key;
	int	value;
};

class Serializer {
	private:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& srcs);
		Serializer& operator=(const Serializer& srcs);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif