#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		
		Ice(const Ice& srcs);
		Ice& operator=(const Ice& srcs);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif