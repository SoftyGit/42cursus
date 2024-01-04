#include "ScavTrap.hpp"

int	main() {
	ScavTrap ST("yongjale");

	ST.attack("42SEOUL");
	ST.takeDamage(9);
	ST.attack("42SEOUL");
	ST.takeDamage(100);
	ST.attack("42SEOUL");
	ST.beRepaired(100);
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.attack("42SEOUL");
	ST.beRepaired(10);
	ScavTrap STST(ST);
	STST.attack("42SEOUL");
	STST.beRepaired(10);
	ST.guardGate();
}
