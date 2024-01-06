#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain	*_brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& srcs);
		Dog& operator=(const Dog& srcs);

		void		makeSound() const;
		std::string	getIdea() const;
};

#endif