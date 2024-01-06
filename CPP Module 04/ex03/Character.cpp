#include "Character.hpp"

Character::Character() : _name("none"), _inven() {
	std::cout << "Character is created" << std::endl;
}
Character::Character(std::string name) : _name(name), _inven() {
	std::cout << "Character is created" << std::endl;
}
Character::~Character() {
	for (int i = 0; i < 4; i++) 
		if (this->_inven[i])
			delete this->_inven[i];
	std::cout << "Character is deleted" << std::endl;
}

Character::Character(const Character& srcs) : ICharacter(srcs), _inven() {
	*this = srcs;
	std::cout << "Character is copied" << std::endl;
}
Character&	Character::operator=(const Character& srcs) {
	this->_name = srcs._name;
	for (int i = 0; i < 4; i++)
		if (srcs._inven[i])
			this->_inven[i] = srcs._inven[i];
	std::cout << "Character assignment operator is called" << std::endl;
	return (*this);
}

const std::string&	Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if(this->_inven[i] == NULL && m != NULL) {
			// Is Material in an Inventory?
			int	j = 0;
			while (1) {
				// No
				if (j == 4){
					this->_inven[i] = m;
					break ;
				}
				// Yes
				if (this->_inven[j] == m) {
					this->_inven[i] = m->clone();
					break ;
				}
				j++;
			}
			std::cout << "Equip " << i << "-" << m->getType() << ": Equip" << std::endl;
			return ;
		}
	}
	std::cout << this->_name << ": Full (OR) Invalid" << std::endl;
	// Before Deleted, Is Material in an Inventory?
	for (int k = 0; k < 4; k++) {
		// Yes (NO DELETE!)
		if (this->_inven[k] == m){
			return ;
		}
	}
	// No Use Anymore!
	delete m;
}
void	Character::unequip(int idx) {
	if (idx < 0 || idx > 4)
		std::cout << "Unequip " << idx << ": Invalid" << std::endl;
	else if (this->_inven[idx] != NULL) {
		this->_inven[idx] = NULL;
		std::cout << "Unequip " << idx << ": Unequip" << std::endl;
	}
	else
		std::cout << idx << ": Empty" << std::endl; 
}
void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 4)
		std::cout << "Use " << idx << ": Invalid" << std::endl;
	else if (this->_inven[idx] != NULL)
		this->_inven[idx]->use(target);
	else
		std::cout << "Use " << idx << ": Empty" << std::endl; 
}
