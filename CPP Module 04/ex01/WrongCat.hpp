#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& srcs);
		WrongCat& operator=(const WrongCat&srcs);
		void	makeSound() const;
};

#endif