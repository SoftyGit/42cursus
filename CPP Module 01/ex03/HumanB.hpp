#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weap;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weap);
		void	attack(void);
};

#endif