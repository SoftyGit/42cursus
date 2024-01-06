#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	std::cout << "--TEST-----------------------------------" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	i->makeSound();
	j->makeSound();
	std::cout << "--DELETE---------------------------------" << std::endl;
	delete j;
	delete i;

	// std::cout << "--ERROR----------------------------------" << std::endl;
	// const Animal* m = new Animal();

	// m->makeSound();
	// std::cout << "--DELETE---------------------------------" << std::endl;
	// delete m;

	return 0;
}