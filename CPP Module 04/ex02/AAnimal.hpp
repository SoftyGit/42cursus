#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal &srcs);
		AAnimal& operator=(const AAnimal& srcs);
		virtual void		makeSound() const = 0;
		virtual std::string	getType() const;
};

#endif