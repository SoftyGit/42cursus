#include "RPN.hpp"

Calculate::Calculate() {}
Calculate::~Calculate() {}
Calculate::Calculate(const Calculate& srcs) {
	*this = srcs;
}
Calculate& Calculate::operator=(const Calculate& srcs) {
	static_cast<void>(srcs);
	return *this;
}

void Calculate::Push(int num) {
	_stack.push(num);
}
void Calculate::Pop() {
	if (_stack.size() == 0)
		std::runtime_error("Error");
	_stack.pop();
}
void Calculate::Operate(int op) {
	long long x = 0;
	long long a;
	long long b;

	if (_stack.size() <= 1)
		throw std::runtime_error("Error");
	b = _stack.top();
	Pop();
	a = _stack.top();
	Pop();
	if (op == PLUS)
		x = a + b;
	else if (op == SUB) 
		x = a - b;
	else if (op == MUL)
		x = a * b;
	else if (op == DIV) {
		if (b == 0)
			throw std::runtime_error("Error: Divided By Zero");
		x = a / b;
	}
	if (x > 2147483647 || x < -2147483648)
		throw std::runtime_error("Error: Overflow/Underflow");
	Push(x);
}
void Calculate::Finish() {
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::runtime_error("Error: Insufficient Operator");
}
