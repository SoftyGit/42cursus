#include "Sed.hpp"

Sed::Sed(std::string name):  _infile(name) {
 	this->_outfile = this->_infile + ".replace";
}
Sed::~Sed(void) {
}

void	 Sed::replace(std::string s1, std::string s2) {
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		data;
	size_t	index;

	ifs.open(this->_infile.c_str());
	if (ifs.fail()) {
		std::cerr << "open error" << std::endl;
		exit(1);
	}
	ofs.open(this->_outfile.c_str());
	if (ofs.fail()) {
		std::cerr << "open error" << std::endl;
		exit(1);
	}
	while (1) {
		std::getline(ifs, data);
		index = data.find(s1, 0);
		while (index != std::string::npos) {
			data.erase(index, s1.length());
			data.insert(index, s2);
			index = data.find(s1, index);
			std::cout << index << std::endl;
		}
		if (ifs.eof())
			break ;
	}
	ofs << data;
	ofs.close();
}