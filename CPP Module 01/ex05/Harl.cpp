#include "Harl.hpp"

void    Harl::debug() {
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void    Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void    Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}
void    Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
Harl::Harl() {
}
Harl::~Harl() {
}
void	Harl::complain(std::string level) {
	std::string index[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*func[])(void) =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	size_t num = std::distance(index, std::find(&index[0], &index[4], level));	
	if (num <= 3)
		(this->*func[num])();
	else
		std::cout << "Harl complains any other things" << std::endl;
}
