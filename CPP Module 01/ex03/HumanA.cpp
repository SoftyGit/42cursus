#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weap) : _name(name), _weap(weap) {

}
HumanA::~HumanA(void) {
}

void	HumanA::attack(void) {
	if (this->_weap.getType() == "")
		std::cout << "No Weapon Type" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weap.getType() << std::endl;
}
