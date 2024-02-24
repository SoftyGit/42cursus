#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	private:

	public:
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack& srcs) {
			*this = srcs;
		}
		MutantStack& operator=(const MutantStack& srcs) {
			if (this != &srcs)
				*this = srcs;
			return *this;
		}

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

		iterator				begin() { return this->c.begin(); }
		iterator				end() { return this->c.end(); }
		reverse_iterator		rbegin() { return this->c.rbegin(); }
		reverse_iterator		rend() { return this->c.rend(); }
		const_iterator			cbegin() { return this->c.cbegin(); }
		const_iterator			cend() { return this->c.cend(); }
		const_reverse_iterator	crbegin() { return this->c.crbegin(); }
		const_reverse_iterator	crend() { return this->c.crend(); }

};

#endif