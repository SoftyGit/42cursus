#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50; 
	this->_attackDamage = 20;
	std::cout << this->_name << "(scav) is created" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << this->_name << "(scav) is deleted" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
		std::cout << "No Hit/Energy Points " << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attackDamage
		<< " points of damage!"
		<< " (remained " << this->_hitPoints << "/" << this->_energyPoints << ")" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl; 
}
