#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weap = NULL;
}
HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon& weap) {
	this->_weap = weap;
}

void	HumanB::setWeapon(Weapon& weap) {
	this->_weap = &weap;
}

void	HumanB::attack(void) {
	if (this->_weap && this->_weap.getType() == "")
		std::cout << this->_name << " attacks with their " << this->_weap << std::endl;
	else
		std::cout << "No Weapon OR No Weapon Type" << std::endl;
}