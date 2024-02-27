#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <stack>

# define PLUS 1
# define SUB 2
# define MUL 3
# define DIV 4

class Calculate {
	private:
		Calculate(const Calculate& srcs);
		Calculate& operator=(const Calculate& srcs);
		std::stack<int> _stack;
	public:
		Calculate();
		~Calculate();

		void	Push(int num);
		void	Pop();
		void	Operate(int op);
		void	Finish();
};
#endif