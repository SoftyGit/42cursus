#include "PmergeMe.hpp"
#include <sys/time.h> // gettimeofday

static long getTime(const struct timeval& s1, const struct timeval& s2) {
	long micro_sec = 0;

	micro_sec += (s2.tv_sec - s1.tv_sec) * 1000 * 1000;
	micro_sec += s2.tv_usec - s1.tv_usec;
	return micro_sec;
}

static bool hasDuplicates(std::vector<size_t> vec) {
    std::sort(vec.begin(), vec.end());
    for (size_t i = 1; i < vec.size(); ++i)
        if (vec[i] == vec[i - 1])
			return true;
    return false; // 중복 없음
}

int main(int argc, char** argv) {
	try {
		if (argc < 2)
			throw std::runtime_error("Error: Insufficient Argument");
		
		// Parsing
		std::vector <size_t> v_argv;
		for (int i = 1; i < argc; i++) {
			std::string str(argv[i]);

			for (std::string::iterator it = str.begin(); it != str.end(); it++)
				if (!std::isdigit(*it))
					throw std::runtime_error("Error: Non Positive Integer");
			if (str[0] == '0' && str.length() != 1)
				throw std::runtime_error("Forbidden Syntax: Start From Zero");
			if (str.length() > 10)
				throw std::runtime_error("Error: Overflow Integer");
			else if (str.length() == 10 && str > "2147483647")
				throw std::runtime_error("Error: Overflow Integer");
			v_argv.push_back(std::atoi(argv[i]));
		}
		if (hasDuplicates(v_argv))
			throw std::runtime_error("Error: Duplicates");

		struct timeval	l_1, l_2;
		struct timeval	v_1, v_2;

		// List ---------------------------------------------------------/
		gettimeofday(&l_1, NULL);
		PList p_list(argc, argv);
		std::list<size_t> sortList = p_list.getSortList();
		gettimeofday(&l_2, NULL);
		// Vector --------------------------------------------------------/
		gettimeofday(&v_1, NULL);
		PVector p_vector(argc, argv);
		std::vector<size_t> sortVector = p_vector.getSortVector();
		gettimeofday(&v_2, NULL);


		// Before Print -------------------------------------------------/
		std::cout << "Before:  ";
		for (int i = 1; i <= argc - 1; i++) {
			std::cout << std::atoi(argv[i]) << " ";
		}
		std::cout << std::endl;
		// After Print -------------------------------------------------/
		std::cout << "After:   ";
			// Use Sorted List
			for (std::list<size_t>::reverse_iterator rit_l = sortList.rbegin(); rit_l != sortList.rend(); rit_l++)
				std::cout << *rit_l << " ";
			// Use Sorted Vector
			// for (std::list<size_t>::reverse_iterator rit_v = sortList.rbegin(); rit_v != sortList.rend(); rit_v++)
			// 	std::cout << *rit_v << " ";
		std::cout << std::endl;

		// Time ---------------------------------------------------------/
		std::cout << "Time to process a range of " << argc - 1 << 
			" elements with std::list<size_t>   :  " << getTime(l_1, l_2) 
			<< " us" << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << 
			" elements with std::vector<size_t> :  " << getTime(v_1, v_2) 
			<< " us" << std::endl; 
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
}
