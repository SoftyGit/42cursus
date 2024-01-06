#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		~Cat();
		Cat(const Cat& srcs);
		Cat& operator=(const Cat&srcs);

		void	makeSound() const;
};

#endif