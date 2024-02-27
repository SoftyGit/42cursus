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
	int a;
	int b;

	b = _stack.top();
	Pop();
	a = _stack.top();
	Pop();
	if (op == PLUS)
		Push(a + b);
	else if (op == SUB) 
		Push(a - b);
	else if (op == MUL)
		Push(a * b);
	else if (op == DIV) {
		if (b == 0)
			throw std::runtime_error("Error: Divided By Zero");
		Push (a / b);
	}
}
void Calculate::Finish() {
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::runtime_error("Error: Insufficient Operator");
}
