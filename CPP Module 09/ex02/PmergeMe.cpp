#include "PmergeMe.hpp"

PList::PList() {}
PList::~PList() {}
PList::PList(const Plist& srcs) {
	*this = srcs;
}
PList& PList::operator=(const PList& srcs) {
	static_cast<void>(srcs);
	return *this;
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

size_t	getList(std::list<size_t> L, size_t idx) {
	std::list<size_t>::iterator it;
	for (it = L.begin(); it != L.end(); it++) {
		if (--idx == 0)
			return *it;
	}
}

size_t	findList(std::list<size_t> L, size_t value) {
	std::list<size_t>::iterator it;
	size_t	i = 1;
	for (it = L.begin(); it != L.end(); it++) {
		if (*it == value)
			return i;
		i++;
	}
}

size_t	t(size_t k) {
	return (std::pow(2, k + 1) + (k % 2 ? -1 : 1)) / 3
}

PList::PList(char** argv, size_t n) {
	for (size_t i = 1; i <= n / 2; i++) {
		if (std::isdigit(argv[i]))
			D.push_back(argv[i] - '0');
		else
			std::runtime_error("Error: Non Digit");
	}
	// Step 1: Pairwise comparison
	for (size_t i = 1; i <= n / 2; i++) {
		A.push_back(std::max(getList(D, i), getList(D, i + n / 2)));
		B.push_back(std::min(getList(D, i), getList(A, i + n / 2)));
	}
	if (n % 2 == 1)
		B.push_back(getList(D, n));
	
}

std::list<size_t> PList::BinaryInsertion(std::list<size_t> L, size_t n) {
	if (n == 0)
		return getList(L, 1);
	size_t k = std::log10(n) / 1;
	size_t c;

	// if (a < getList(L, c + 1))

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
		b.push_back(getList(D, n));
	
	// Step 2: Recursion and Renaming
	std::list<size_t> old_a(a);
	std::list<size_t> old_b(b);
	a = MergeInsertion(a, n / 2);
	for (size_t i = 1; i <= n / 2; i++) {
		size_t idx = findList(a, getList(old_a, i));
		modifyList(b, i, getList(old_b, idx));
	}

	// Step 3: Insertion
	size_t k = 2;
	while (t(k - 1) < n / 2 + n % 2) {
		m = std::min(t(k), n / 2 + n % 2);
		u = t(k - 1) + m;
		for (i = u; i != t(k - 1); i--) {
			while (d = BinaryInsertion() != getList(a, i - 1));
				u = u - 1;
		}
		k = k + 1;
	}
	return d;
}