#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	std::cout << "--TEST1----------------------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "--DELETE---------------------------------" << std::endl;
	delete j;
	delete i;

	std::cout << "--TEST2----------------------------------" << std::endl;

	const Animal* animals[6] =
		{new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};
	std::cout << "--DELETE---------------------------------" << std::endl;
	for(int i = 0; i < 6; i++) {
		delete animals[i];
	}
	std::cout << "--TEST3----------------------------------" << std::endl;
	Dog *n = new Dog();
	Cat *m = new Cat();

	std::cout << "m Ideas: " << m->getIdea() << std::endl;
	std::cout << "n Ideas: " << n->getIdea() << std::endl;
	
	std::cout << "--COPY-----------------------------------" << std::endl;
	Cat *z = new Cat(*m);

	std::cout << "z Ideas: " << z->getIdea() << std::endl;
	std::cout << "--DELETE---------------------------------" << std::endl;
	delete m;
	delete n;
	delete z;

	return 0;
}