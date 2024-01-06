#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
		std::string ideas[100];

		Brain();
		~Brain();
		Brain(const Brain& srcs);
		Brain& operator=(const Brain& srcs);
};

#endif