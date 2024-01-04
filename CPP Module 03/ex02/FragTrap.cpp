#include "FragTrap.hpp"

FragTrap::FragTrap() {
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100; 
	this->_attackDamage = 30;
	std::cout << this->_name << "(frag) is created" << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << this->_name << "(frag) is deleted" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " makes a positive high fives request!" << std::endl; 
}
