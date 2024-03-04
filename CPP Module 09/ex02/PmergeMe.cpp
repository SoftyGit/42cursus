#include "PmergeMe.hpp"

size_t	getJacob(size_t	x) {
	if (x == 1)
		return 1;
	return static_cast<size_t>(log2(3 * x - 1.1));
}

// List ---------------------------------------------------------/
PList::PList() {}
PList::~PList() {}
PList::PList(const PList& srcs) {
	*this = srcs;
}
PList& PList::operator=(const PList& srcs) {
	static_cast<void>(srcs);
	return *this;
}

PList::PList(int argc, char** argv) : _len(argc - 1) {
	for (size_t i = 1; i <= _len; i++)
		_list.push_back(std::atoi(argv[i]));
	size_t	cnt = getJacob(_len / 2 + _len % 2) + 1;
	for (size_t i = 1; i <= cnt; i++)
		_jacob.push_back((pow(2, i + 1) - (i % 2 ? 1 : -1)) / 3);
}

std::list<size_t> PList::getSortList() {
	return MergeInsertion(_list, _len);
}

void PList::modifyList(std::list<size_t>& L, size_t idx, size_t value) {
	std::list<size_t>::iterator it;
	it = L.begin();
	std::advance(it, idx - 1);
	if (it != L.end()) {
		it = L.erase(it);
		L.insert(it, value);
	}
}

void PList::insertList(std::list<size_t>& L, size_t idx, size_t value) {
	std::list<size_t>::iterator it;
	it = L.begin();
	std::advance(it, idx - 1);
	if (it != L.end())
		L.insert(it, value);
	else
		L.push_back(value);
}

size_t PList::getList(std::list<size_t>& L, size_t idx) {
	std::list<size_t>::iterator it;
	it = L.begin();
	std::advance(it, idx - 1);
	return *it;	
}

size_t	PList::findList(std::list<size_t>& L, size_t value) {
	std::list<size_t>::iterator it;
	size_t	i = 1;
	for (it = L.begin(); it != L.end(); it++) {
		if (*it == value)
			return i;
		i++;
	}
	return 0;
}

size_t PList::BinaryInsertion(std::list<size_t>& L, size_t begin, size_t end, size_t value) {
	size_t n = (begin + end) / 2;
	size_t mid = getList(L, n);

	if (begin == end)
		return value > mid ? begin : begin + 1;
	if (value == mid)
		return n;
	else if (value > mid)
		return BinaryInsertion(L, begin, n, value);
	else
		return BinaryInsertion(L, n + 1, end, value);
}

std::list<size_t> PList::MergeInsertion(std::list<size_t>& d, size_t n) {
	if (n == 1)
		return d;
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
		if (idx != 0)
			modifyList(b, i, getList(old_b, idx));
	}

	// Step 3: Insertion
	size_t jacob_max_idx = getJacob(n - n / 2);
	size_t jacob;
	if (jacob_max_idx != 1)
		jacob = getList(_jacob, jacob_max_idx - 1);
	else
		jacob = 2;
	for (size_t i = 1; i <= n - (n / 2); i++) {
		size_t jacob_level = getJacob(i);
		size_t jacob_idx;
		if (i != 1) {
			if (i <= jacob)
				jacob_idx = getList(_jacob, jacob_level) - (i - 1 - getList(_jacob, jacob_level - 1));
			else
				jacob_idx = getList(_jacob, jacob_level) - (i - 1 - getList(_jacob, jacob_level - 1)) - (getList(_jacob, jacob_level) - (n - n / 2));
		}
		else
			jacob_idx = getList(_jacob, jacob_level) + (i - 1);
		jacob_idx = (n - (n / 2)) - jacob_idx + 1;
		size_t value = getList(b, jacob_idx);
		size_t idx = BinaryInsertion(a, 1, (n / 2) + i - 1, value);
		insertList(a, idx, value);
	}
	return a;
}

// Vector ---------------------------------------------------------/
PVector::PVector() {}
PVector::~PVector() {}
PVector::PVector(const PVector& srcs) {
	*this = srcs;
}
PVector& PVector::operator=(const PVector& srcs) {
	static_cast<void>(srcs);
	return *this;
}

PVector::PVector(int argc, char** argv) : _len(argc - 1) {
	for (size_t i = 1; i <= _len; i++)
		_vector.push_back(std::atoi(argv[i]));
	size_t	cnt = getJacob(_len / 2 + _len % 2) + 1;
	for (size_t i = 1; i <= cnt; i++)
		_jacob.push_back((pow(2, i + 1) - (i % 2 ? 1 : -1)) / 3);
}

std::vector<size_t> PVector::getSortVector() {
	return MergeInsertion(_vector, _len);
}

size_t	PVector::findVector(std::vector<size_t>& L, size_t value) {
	std::vector<size_t>::iterator it = std::find(L.begin(), L.end(), value);
	if (it != L.end())
		return std::distance(L.begin(), it);
	return 0;
}

void PVector::modifyVector(std::vector<size_t>& L, size_t idx, size_t value) {
	std::vector<size_t>::iterator it;
	it = L.begin();
	std::advance(it, idx - 1);
	if (it != L.end()) {
		*it = value;
	}
}

void PVector::insertVector(std::vector<size_t>& L, size_t idx, size_t value) {
	std::vector<size_t>::iterator it;
	it = L.begin();
	std::advance(it, idx - 1);
	if (it != L.end())
		L.insert(it, value);
	else
		L.push_back(value);
}

size_t PVector::BinaryInsertion(std::vector<size_t>& L, size_t begin, size_t end, size_t value) {
	size_t n = (begin + end) / 2;
	size_t mid = L[n - 1];

	if (begin == end)
		return value > mid ? begin : begin + 1;
	if (value == mid)
		return n;
	else if (value > mid)
		return BinaryInsertion(L, begin, n, value);
	else
		return BinaryInsertion(L, n + 1, end, value);
}

std::vector<size_t> PVector::MergeInsertion(std::vector<size_t>& d, size_t n) {
	if (n == 1)
		return d;
	// Step 1: Pairwise comparison
	std::vector<size_t> a;
	std::vector<size_t> b;
	for(size_t i = 1; i <= n / 2; i++) {
		a.push_back(std::max(d[i - 1], d[i + n / 2 - 1]));
		b.push_back(std::min(d[i - 1], d[i + n / 2 - 1]));
	}
	if (n % 2 == 1)
		b.push_back(d[n - 1]);

	// Step 2: Recursion and Renaming
	std::vector<size_t> old_a(a);
	std::vector<size_t> old_b(b);
	a = MergeInsertion(a, n / 2);
	for (size_t i = 1; i <= n / 2; i++) {
		size_t idx = findVector(a, old_a[i - 1]);
		if (idx != 0)
			modifyVector(b, i, old_b[idx - 1]);
	}

	// Step 3: Insertion
	size_t jacob_max_idx = getJacob(n - n / 2);
	size_t jacob;
	if (jacob_max_idx != 1)
		jacob = _jacob[getJacob(n - n / 2) - 2];
	else
		jacob = 2;
	for (size_t i = 1; i <= n - (n / 2); i++) {
		size_t jacob_level = getJacob(i);
		size_t jacob_idx;
		if (i != 1) {
			if (i <= jacob)
				jacob_idx = _jacob[jacob_level - 1] - (i - 1 - _jacob[jacob_level - 1 - 1]);
			else
				jacob_idx = _jacob[jacob_level - 1] - (i - 1 - _jacob[jacob_level - 1 - 1]) - (_jacob[jacob_level - 1] - (n - n / 2));
		}
		else
			jacob_idx = _jacob[jacob_level - 1] + (i - 1);
		jacob_idx = (n - (n / 2)) - jacob_idx + 1;
		size_t value = b[jacob_idx - 1];
		size_t idx = BinaryInsertion(a, 1, (n / 2) + i - 1, value);
		insertVector(a, idx, value);
	}
	return a;
}
