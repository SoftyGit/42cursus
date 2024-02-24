# include "Span.hpp"

Span::Span() {}
Span::~Span() {}
Span::Span(unsigned int N) : _length(N) {
}

Span::Span(const Span& srcs) {
	*this = srcs;
}
Span& Span::operator=(const Span& srcs) {
	if (this != &srcs) {
		this->_length = srcs._length;
		this->_vec = srcs._vec;
	}
	return *this;
}

void Span::addNumber(int a) {
	if (_vec.size() >= _length)
		throw std::out_of_range("Full!");
	_vec.push_back(a);
}
void Span::addManyNumber(int a, size_t size) {
	if (_vec.size() + size > _length)
		throw std::out_of_range("Full!");
	for (size_t i = 0; i < size; i++)
		_vec.push_back(a);
}
unsigned int Span::longestSpan() {
	if (_vec.size() <= 1)
		throw std::out_of_range("Insufficient Numbers!");
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}
unsigned int Span::shortestSpan() {
	if (_vec.size() <= 1)
		throw std::out_of_range("Insufficient Numbers!");

	unsigned int min = this->longestSpan();

	std::vector<int> sortVec = _vec;
	std::sort(sortVec.begin(), sortVec.end());

	for (std::vector<int>::iterator i = sortVec.begin(); i != sortVec.end() - 1; i++)
		if (std::abs(*(i + 1) - *i) < min)
			min = std::abs(*(i + 1) - *i);
	return min;
}
