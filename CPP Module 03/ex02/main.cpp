#include "FragTrap.hpp"

int	main() {
	FragTrap FT("yongjale");

	FT.attack("42SEOUL");
	FT.takeDamage(9);
	FT.attack("42SEOUL");
	FT.takeDamage(100);
	FT.attack("42SEOUL");
	FT.beRepaired(100);
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.attack("42SEOUL");
	FT.beRepaired(10);
	FragTrap FTFT(FT);
	FTFT.takeDamage(101);
	FTFT.attack("42SEOUL");
	FTFT.beRepaired(10);
	FT.highFivesGuys();
}
