#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>

class Span {
	private:
		unsigned int		_length;
		std::vector<int>	_vec;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span& srcs);
		Span& operator=(const Span& srcs);

		void				addNumber(int a);
		void 				addManyNumber(int a, size_t size);
		unsigned int		longestSpan();
		unsigned int		shortestSpan();
};

#endif