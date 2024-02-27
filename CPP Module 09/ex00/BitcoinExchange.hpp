#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <map>

class Bitcoin {
	private:
		std::map<int, double>	_equity;
		std::string				_input;

		Bitcoin();
		Bitcoin(const Bitcoin& srcs);
		Bitcoin& operator=(const Bitcoin& srcs);
	public:
		Bitcoin(std::string input);
		~Bitcoin();

};

#endif