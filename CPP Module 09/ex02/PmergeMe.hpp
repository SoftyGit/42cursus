#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdlib>
# include <cmath>
# include <list>

class PList {
	private:
		std::list<size_t>	_list;
		std::list<size_t>	_jacob;
		size_t				_len;
		PList();
		PList(const PList& srcs);
		PList& operator=(const PList& srcs);
	public:
		PList(int argc, char** argv);
		~PList();

		std::list<size_t>	getSortList();
		size_t				getList(std::list<size_t>& L, size_t idx);
		size_t				findList(std::list<size_t>& L, size_t value);
		void				modifyList(std::list<size_t>& L, size_t idx, size_t value);
		void				insertList(std::list<size_t>& L, size_t idx, size_t value);
		size_t				BinaryInsertion(std::list<size_t>& L, size_t begin, size_t end, size_t value);
		std::list<size_t>	MergeInsertion(std::list<size_t>& d, size_t n);
};

class PVector {
	private:
		std::vector<size_t>	_vector;
		std::vector<size_t>	_jacob;
		size_t				_len;
		PVector();
		PVector(const PVector& srcs);
		PVector& operator=(const PVector& srcs);
	public:
		PVector(int argc, char** argv);
		~PVector();

		std::vector<size_t>	getSortVector();
		size_t				findVector(std::vector<size_t>& L, size_t value);
		void				modifyVector(std::vector<size_t>& L, size_t idx, size_t value);
		void				insertVector(std::vector<size_t>& L, size_t idx, size_t value);
		size_t				BinaryInsertion(std::vector<size_t>& L, size_t begin, size_t end, size_t value);
		std::vector<size_t>	MergeInsertion(std::vector<size_t>& d, size_t n);
};

#endif