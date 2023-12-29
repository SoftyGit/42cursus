#include "Sed.hpp"

Sed::Sed(std::string name): _infile(name) {
 	this->_outfile = this->_infile + ".replace";
}
Sed::~Sed(void) {
}

void	 Sed::replace(std::string s1, std::string s2) {
	std::string		data;
	size_t	index;

	std::ifstream	ifs(this->_infile.c_str());
	if (ifs.fail()) {
		std::cerr << "open infile error" << std::endl;
		exit(1);
	}
	std::ofstream	ofs(this->_outfile.c_str());
	if (ofs.fail()) {
		std::cerr << "open outfile error" << std::endl;
		exit(1);
	}
	while (1) {
		std::getline(ifs, data, (char)0);
		index = data.find(s1, 0);
		while (index != std::string::npos) {
			data.erase(index, s1.length());
			data.insert(index, s2);
			index = data.find(s1, index + s1.length());
		}
		if (ifs.eof())
			break ;
	}
	ofs << data;
	ofs.close();
}