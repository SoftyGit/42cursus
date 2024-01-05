#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &srcs);
		WrongAnimal& operator=(const WrongAnimal& srcs);
		void		makeSound() const;
		std::string	getType() const;
};

#endif