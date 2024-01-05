#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*_brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& srcs);
		Dog& operator=(const Dog& srcs);

		void	makeSound() const;
};

#endif