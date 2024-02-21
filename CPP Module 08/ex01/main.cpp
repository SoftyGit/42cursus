#include "Span.hpp"
#include <iostream>

int main()
{
	std::cout << "--Test1--subject-----------------------------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "--Test2--same---------------------------------" << std::endl;
	Span test2 = Span(5);
	test2.addNumber(1);
	test2.addNumber(1);
	test2.addNumber(1);
	test2.addNumber(1);
	test2.addNumber(1);
	std::cout << test2.shortestSpan() << std::endl;
	std::cout << test2.longestSpan() << std::endl;

	std::cout << "--Test3--negative-----------------------------" << std::endl;
	Span test3 = Span(5);
	test3.addNumber(1);
	test3.addNumber(-1);
	test3.addNumber(2);
	test3.addNumber(-2);
	test3.addNumber(3);
	std::cout << test3.shortestSpan() << std::endl;
	std::cout << test3.longestSpan() << std::endl;

	std::cout << "--Test4--error-------------------------------" << std::endl;
	try {
	Span test4 = Span(5);
	test4.addNumber(1);
	test4.addNumber(-1);
	test4.addNumber(2);
	test4.addNumber(-2);
	test4.addNumber(3);
	test4.addNumber(3); // <-- error
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "--Test5--error-------------------------------" << std::endl;
	try {
	Span test5 = Span(5);
	test5.addNumber(1);
	std::cout << test5.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "--Test6--add-many-numbers--------------------" << std::endl;
	try {
	Span test6 = Span(5);
	test6.addManyNumber(1, 5);
	std::cout << test6.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "--Test7--add-many-numbers--full--------------" << std::endl;
	try {
	Span test7 = Span(5);
	test7.addManyNumber(1, 5);
	test7.addNumber(2);
	std::cout << test7.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--Test8--add-many-numbers--big---------------" << std::endl;
	try {
	Span test8 = Span(100000);
	test8.addManyNumber(1, 50000);
	test8.addManyNumber(2, 10000);
	test8.addNumber(20);
	std::cout << test8.longestSpan() << std::endl;
	std::cout << test8.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}