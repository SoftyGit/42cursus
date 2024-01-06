#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(const std::string& type);
		virtual ~AMateria();

		AMateria(const AMateria& srcs);
		AMateria&	operator=(const AMateria& srcs);

		const std::string& getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
};

#endif