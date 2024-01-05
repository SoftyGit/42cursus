#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "----------------------" << std::endl;

	const Animal* animals[6] =
		{new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};
	for(int i = 0; i < 6; i++) {
		delete animals[i];
	}

	return 0;
}