#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
	private:
		Brain	*_brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat& srcs);
		Cat& operator=(const Cat& srcs);
		
		void		makeSound() const;
		std::string	getIdea() const;
};

#endif