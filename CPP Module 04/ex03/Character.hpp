#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria*	_inven[4];
	public:
		Character();
		Character(std::string name);
		~Character();
		
		Character(const Character& srcs);
		Character&	operator=(const Character& srcs);

		const std::string& getName() const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif