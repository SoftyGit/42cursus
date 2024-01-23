#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>
# include <algorithm> // wrong

class Harl {
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif