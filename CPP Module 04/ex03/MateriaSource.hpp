#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_inven[4];
	public:
		MateriaSource();
		~MateriaSource();

		MateriaSource(const MateriaSource& srcs);
		MateriaSource&	operator=(const MateriaSource& srcs);

		void		learnMateria(AMateria *);
		AMateria*	createMateria(const std::string& type);
};

#endif