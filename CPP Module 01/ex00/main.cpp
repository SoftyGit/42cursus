#include "Zombie.hpp"

int main(void) {
	std::string name = "yongjale";

	// 1 stack by a local variable
	Zombie	zom1("zom1");
	// 2 heap by dynamic allocation
	Zombie	*zom2 = newZombie("zom2");
	// 3 stack by a local variable in external function
	randomChump(name);
	// 1
	zom1.announce();
	// 2
	zom2->announce();
	delete zom2;
	return (0);
}