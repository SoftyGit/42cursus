#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
class Sed {
	private:
		std::string _infile;
		std::string _outfile;
	public:
		Sed(std::string name);
		 ~Sed();
		void replace(std::string s1, std::string s2);
};

#endif