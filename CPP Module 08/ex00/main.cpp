#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	try {
		std::cout << "--Test1--vector----------------------------------" << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		std::cout << "Index: " << *easyfind(vec, 3) << std::endl;
		
		std::cout << "--Test2--list------------------------------------" << std::endl;
		std::list<int> lst;
		lst.push_back(6);
		lst.push_back(7);
		lst.push_back(8);
		lst.push_back(9);
		lst.push_back(10);
		std::cout << "Index: " << *easyfind(lst, 8) << std::endl;
		
		std::cout << "--Test3--vector--except--------------------------" << std::endl;
		std::cout << "Index: " << *easyfind(vec, 10) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}