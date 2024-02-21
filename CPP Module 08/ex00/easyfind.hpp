#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int find) {
	typename T::iterator index = std::find(container.begin(), container.end(), find);
	if (index == container.end())
		throw std::runtime_error("Not Found");
	return index;
}

#endif