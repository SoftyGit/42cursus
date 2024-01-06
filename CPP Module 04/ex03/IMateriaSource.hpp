#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

class IMateriaSource {
	public:
		IMateriaSource();
		virtual ~IMateriaSource() {}

		IMateriaSource(const IMateriaSource& srcs);
		IMateriaSource&	operator=(const IMateriaSource& srcs);

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(const std::string & type) = 0;
};

#endif