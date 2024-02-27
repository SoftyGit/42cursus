#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cmath>
# include <vector>
# include <list>

class PVector {
	private:
		std::vector<size_t>	_vector;
		PVector(const PVector& srcs);
		PVector& operator=(const PVector& srcs);
	public:
		PVector();
		~PVector();

};

class PList {
	private:
		std::list<size_t>	D;
		std::list<size_t>	A;
		std::list<size_t>	B;
		PList();
		PList(const PList& srcs);
		PList& operator=(const PList& srcs);
	public:
		PList(char** argv, size_t n);
		~PList();
};

#endif