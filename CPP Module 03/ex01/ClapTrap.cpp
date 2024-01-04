#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
}
ClapTrap::ClapTrap(std::string name) : 
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << this->_name << "(clap) is created" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& srcs) {
	*this = srcs;
	std::cout << this->_name << "(clap) is copied" << std::endl;
}
ClapTrap&	ClapTrap::operator=(const ClapTrap& srcs) {
	this->_name = srcs._name;
	this->_hitPoints = srcs._hitPoints;
	this->_energyPoints = srcs._energyPoints;
	this->_attackDamage = srcs._attackDamage;
	return (*this);
}
ClapTrap::~ClapTrap() {
	std::cout << this->_name << "(clap) is deleted" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0) {
		std::cout << "No Hit/Energy Points " << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attackDamage
		<< " points of damage!"
		<< " (remained " << this->_hitPoints << "/" << this->_energyPoints << ")" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " is damaged with "
			<< amount << " points of damage!"
			<< " (remained " << this->_hitPoints << "/" << this->_energyPoints << ")" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0) {
		std::cout << "No Energy Points" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired with "
		<< amount << " points"
		<< " (remained " << this->_hitPoints << "/" << this->_energyPoints << ")" << std::endl;
}
