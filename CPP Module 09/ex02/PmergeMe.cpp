#include "PmergeMe.hpp"

PList::PList() {}
PList::~PList() {}
PList::PList(const PList& srcs) {
	*this = srcs;
}
PList& PList::operator=(const PList& srcs) {
	static_cast<void>(srcs);
	return *this;
}

PList::PList(int argc, char **argv) : _len(argc - 1) {
	for (size_t i = 1; i < _len; i++)
		_list.push_back(std::atoi(argv[i]));
}

std::list<size_t>	PList::getSortList() {
	return MergeInsertion(_list, _len);
}

void	modifyList(std::list<size_t> L, size_t idx, size_t value) {
	std::list<size_t>::iterator it;
	for (it = L.begin(); it != L.end(); it++) {
		if (--idx == 0) {
			L.erase(it);
			L.insert(it, value);
		}
	}
}

void	insertList(std::list<size_t> L, size_t idx, size_t value) {
	std::list<size_t>::iterator it;
	for (it = L.begin(); it != L.end(); it++) {
		if (--idx == 0) {
			L.insert(it, value);
		}
	}
}

size_t	getList(std::list<size_t> L, size_t idx) {
	std::list<size_t>::iterator it;
	for (it = L.begin(); it != L.end(); it++) {
		if (--idx == 0)
			return *it;
	}
	return 0;
}

size_t	findList(std::list<size_t> L, size_t value) {
	std::list<size_t>::iterator it;
	size_t	i = 1;
	for (it = L.begin(); it != L.end(); it++) {
		if (*it == value)
			return i;
		i++;
	}
	return -1;
}

size_t	PList::BinaryInsertion(std::list<size_t> L, size_t begin, size_t end, size_t value) {
	size_t n = (begin + end) / 2;
	size_t mid = getList(L, n);

	if (begin == end)
		return value > mid ? begin : begin + 1;
	if (value == mid)
		return n;
	else if (value < mid)
		return BinaryInsertion(L, n + 1, end, value);
	else
		return BinaryInsertion(L, begin, n - 1, value);
}

std::list<size_t> PList::MergeInsertion(std::list<size_t> d, size_t n) {
	// Step 1: Pairwise comparison
	std::list<size_t> a;
	std::list<size_t> b;
	for (size_t i = 1; i <= n / 2; i++) {
		a.push_back(std::max(getList(d, i), getList(d, i + n / 2)));
		b.push_back(std::min(getList(d, i), getList(d, i + n / 2)));
	}
	if (n % 2 == 1)
		b.push_back(getList(d, n));
	
	// Step 2: Recursion and Renaming
	std::list<size_t> old_a(a);
	std::list<size_t> old_b(b);
	a = MergeInsertion(a, n / 2);
	for (size_t i = 1; i <= n / 2; i++) {
		size_t idx = findList(a, getList(old_a, i));
		modifyList(b, i, getList(old_b, idx));
	}

	// Step 3: Insertion
	if (n <= 2)
		return d;
	for (size_t i = 1; i <= n - (n / 2); i++) {
		size_t value = getList(b, i);
		size_t idx = BinaryInsertion(a, 1, n / 2, value);
		insertList(a, idx, value);
	}
	return a;
}