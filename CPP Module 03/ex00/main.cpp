#include "ClapTrap.hpp"

int	main() {
	ClapTrap CT("yongjale");

	CT.attack("42SEOUL");
	CT.takeDamage(9);
	CT.attack("42SEOUL");
	CT.takeDamage(10);
	CT.attack("42SEOUL");
	CT.beRepaired(10);
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.attack("42SEOUL");
	CT.beRepaired(10);
	ClapTrap CTCT(CT);
	CTCT.attack("42SEOUL");
	CTCT.beRepaired(10);
}
