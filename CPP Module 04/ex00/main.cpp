#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "--NORMAL-----------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j: " << j->getType() << " " << std::endl;
	std::cout << "i: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "--COPY-----------------------------------" << std::endl;
	const Animal* m = new Animal(*i);
	m->makeSound();
	std::cout << "--DELETE---------------------------------" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete m;

	std::cout << "--WRONG----------------------------------" << std::endl;

	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << "k: " << k->getType() << " " << std::endl;
	k->makeSound();
	w_meta->makeSound();

	std::cout << "--WRONG=DELETE---------------------------" << std::endl;
	delete w_meta;
	delete k;

	return 0;
}