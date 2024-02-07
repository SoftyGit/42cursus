#include "Base.hpp"

Base::~Base() {}

Base	*generate(void) {
	std::srand(static_cast<unsigned int>(clock()));
	int val = std::rand();
	if (val % 3 == 0)
		return new A();
	else if (val % 3 == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p)) // if failed, null pointer
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B*>(p)) // if failed, null pointer
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C*>(p)) // if failed, null pointer
		std::cout << "p: C" << std::endl;
}

void	identify(Base &p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "p: A" << std::endl;
	} catch(...) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "p: B" << std::endl;
	} catch(...) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "p: C" << std::endl;
	} catch(...) {}
}