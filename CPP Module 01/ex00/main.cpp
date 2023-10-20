#include "Zombie.hpp"

int main(void) {
	std::string name = "yongjale";

	Zombie	zom1("zom1");
	Zombie	*zom2 = newZombie("zom2");
	randomChump(name);
	zom1.announce();
	zom2->announce();
	delete zom2;
	return (0);
}