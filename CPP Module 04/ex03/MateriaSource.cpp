#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _inven() {
	std::cout << "MateriaSource is created" << std::endl;
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->_inven[i])
			delete this->_inven[i];
	std::cout << "MateriaSource is deleted" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& srcs) : IMateriaSource(srcs) {
	*this = srcs;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& srcs) {
	for (int i = 0; i < 4; i++)
		if (srcs._inven[i])
			this->_inven[i] = srcs._inven[i];
	std::cout << "MateriaSource is copied" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_inven[i] == NULL && materia != NULL) {
			this->_inven[i] = materia;
			std::cout << "Learn " << i << "-" << materia->getType() << ": Learn" << std::endl;
			return ;
		}
	}
	std::cout <<  "MateriaSource: Full (OR) Invalid" << std::endl;
	// Before Deleted, Is Material in an Inventory?
	for (int k = 0; k < 4; k++) {
		// Yes (NO DELETE!)
		if (this->_inven[k] == materia){
			return ;
		}
	}
	// No Use Anymore!
	delete materia;
}
AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (this->_inven[i] != NULL)
			if (this->_inven[i]->getType() == type) {
				return (this->_inven[i]->clone());
			}
	}
	std::cout << "Create " << type << ": Invalid" << std::endl;
	return (0);
}