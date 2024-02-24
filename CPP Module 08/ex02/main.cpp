#include "MutantStack.hpp"

int main()
{
	std::cout << "--Test1--subject-----------------------------" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5); // 5
	mstack.push(17); // 17 5
	std::cout << mstack.top() << std::endl;
	mstack.pop(); // 5
	std::cout << mstack.size() << std::endl;
	mstack.push(3); // 3 5 
	mstack.push(5); // 5 3 5
	mstack.push(737); // 737 5 3 5
	mstack.push(0); // 0 737 5 3 5
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it; 
	--it;
	std::cout << "iterator" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// Test 2 - 5
	MutantStack<int> newStack;
	newStack.push(4);
	newStack.push(3);
	newStack.push(2);
	newStack.push(1);

	std::cout << "--Test2--reverse-----------------------------" << std::endl;
	MutantStack<int>::reverse_iterator reverse_it = newStack.rbegin();
	MutantStack<int>::reverse_iterator reverse_ite = newStack.rend();
	while (reverse_it != reverse_ite)
		std::cout << *reverse_it++ << std::endl;
	// ok
	*--reverse_it = 44;
	*--reverse_it = 33;
	*--reverse_it = 22;
	*--reverse_it = 11;

	std::cout << "--Test3--const-------------------------------" << std::endl;
	MutantStack<int>::const_iterator const_it = newStack.cbegin();
	MutantStack<int>::const_iterator const_ite = newStack.cend();
	while (const_it != const_ite)
		std::cout << *const_it++ << std::endl;
	// error
	//*const_it = 10000;

	std::cout << "--Test4--const--reverse----------------------" << std::endl;
	MutantStack<int>::const_reverse_iterator const_rev_it = newStack.crbegin();
	MutantStack<int>::const_reverse_iterator const_rev_ite = newStack.crend();
	while (const_rev_it != const_rev_ite)
		std::cout << *const_rev_it++ << std::endl;
	// error
	//*const_rev_it = 10000;

	return 0;
}
