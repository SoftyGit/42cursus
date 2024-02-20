#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	// Least Possibility
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	
	// Out of Bound!
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	
	// Out of Bound!
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "Origin Value (index: 0): " << numbers[0] << std::endl;
    delete [] mirror;//

	// Additional Test
	Array<int> empty;
	std::cout << "Empty Size: " << empty.size() << std::endl;

	const Array<int> const_numbers(numbers);
	std::cout << "Random Const Value (index: 0): " << const_numbers[0] << std::endl;
    
	empty = const_numbers;
	std::cout << "Copied Value (index: 0): " << empty[0] << std::endl;
	return 0;
}
