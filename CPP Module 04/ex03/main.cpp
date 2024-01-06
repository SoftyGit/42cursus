#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int	main() {

	std::cout << "--TEST1----------------------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << "--DELETE1--------------------------------" << std::endl;

	delete bob;
	delete me;
	delete src;

	std::cout << "--TEST2----------------------------------" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	std::cout << std::endl;

	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	// EXCEED!
	src2->learnMateria(new Ice());
	std::cout << std::endl;

	ICharacter* me2 = new Character("me2");
	std::cout << std::endl;

	AMateria* ice2;
	ice2 = src2->createMateria("ice");
	me2->equip(ice2);
	AMateria* tmp2;
	std::cout << std::endl;
	tmp2 = src2->createMateria("cure");
	me2->equip(tmp2);
	std::cout << std::endl;
	// INVALID!
	tmp2 = src2->createMateria("blackhole");
	me2->equip(tmp2);
	std::cout << std::endl;

	ICharacter* bob2 = new Character("bob2");
	std::cout << std::endl;


	me2->unequip(0);
	// NO WEAPON!
	me2->use(0, *bob2);
	me2->use(1, *bob2);

	std::cout << std::endl;
	
	std::cout << "--DELETE2--------------------------------" << std::endl;

	delete bob2;
	delete me2;
	delete src2;
	// MUST DELETE ICE2 (unquipped weapon must be deleted)
	delete ice2;

	return 0;
}