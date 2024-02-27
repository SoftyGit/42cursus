#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <cmath>
# include <list>

// class PVector {
// 	private:
// 		std::vector<size_t>	_vector;
// 		PVector(const PVector& srcs);
// 		PVector& operator=(const PVector& srcs);
// 	public:
// 		PVector();
// 		~PVector();

// };

class PList {
	private:
		std::list<size_t>	_list;
		size_t				_len;
		PList();
		PList(const PList& srcs);
		PList& operator=(const PList& srcs);
	public:
		PList(int argc, char **argv);
		~PList();

		std::list<size_t>	getSortList();
		size_t				BinaryInsertion(std::list<size_t> L, size_t begin, size_t end, size_t value);
		std::list<size_t>	MergeInsertion(std::list<size_t> d, size_t n);
};

#endif