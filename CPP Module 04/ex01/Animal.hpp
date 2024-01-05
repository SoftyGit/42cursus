#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &srcs);
		Animal& operator=(const Animal& srcs);
		virtual void		makeSound() const;
		virtual std::string	getType() const;
};

#endif