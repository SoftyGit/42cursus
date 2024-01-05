#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

void	check(void) {
	system("leaks ex00");
}

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	atexit(check);

	std::cout << "j: " << j->getType() << " " << std::endl;
	std::cout << "i: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "-----------------" << std::endl;

	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << "k: " << k->getType() << " " << std::endl;
	k->makeSound();
	w_meta->makeSound();

	delete w_meta;
	delete k;
	exit(0);
}