#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}
Bitcoin::~Bitcoin() {}
Bitcoin::Bitcoin(const Bitcoin& srcs) {
	*this = srcs;
}
Bitcoin& Bitcoin::operator=(const Bitcoin& srcs) {
	static_cast<void>(srcs);
	return *this;
}

bool isValidDate(int year, int month, int day) {
	// argument check
	if (year <= 1969 || year >= 2038)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	// month-day check
	if (month == 2) {
		if (year % 4 == 0) {
		// leap year including 2000 (range: 1970 - 2037)
			if (day < 1 || day > 29)
				return false;
		}
		else {
			if (day < 1 || day > 28)
				return false;
		}
	}
	else if (month % 2 == 0) {
		if (day < 1 || day > 30)
			return false;
	}
	else if (month % 2 != 0) {
		if (day < 1 || day > 31)
			return false;
	}
	return true;
}

Bitcoin::Bitcoin(std::string input) : _input(input) {
	// check data.csv
	std::ifstream ifs;
	ifs.open("data.csv");
	if (ifs.is_open()) {
		std::string line;
		getline(ifs, line);
		while (getline(ifs, line)) {
			int	date = std::atoi(line.substr(0, 4).c_str()) * 10000;
			date += std::atoi(line.substr(5, 2).c_str()) * 100;
			date += std::atoi(line.substr(8, 2).c_str());
			char *end;
			double value = std::strtod(line.substr(11, line.length() - 11).c_str(), &end);
			_equity.insert(std::pair<int, double>(date, value));
		}
	}
	else {
		throw std::runtime_error("Error: could not open csv file.");
	}
	// check input.txt
	std::ifstream ifs_input;
	ifs_input.open(_input.c_str());
	if (ifs_input.is_open()) {
		std::string line;
		getline(ifs_input, line);
		if (line != "date | value")
			throw std::runtime_error("Error: could not open file.");
		while (getline(ifs_input, line)) {
			// length check
			if (line.length() < 14) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue; }
			if (line[4] != '-' || line[7] != '-' || line.substr(10, 3) != std::string(" | ")) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue; }
			if (isValidDate(std::atoi(line.substr(0, 4).c_str()),
							std::atoi(line.substr(5, 2).c_str()),
							std::atoi(line.substr(8, 2).c_str())) == false) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue; }
			// negative check
			if (line[13] == '-') {
				std::cout << "Error: not a positive number." << std::endl;
				continue; }
			// digit check
			int flag = 0;
			for (size_t i = 13; i < line.length(); i++) {
				if (line[i] == '.') {
					if (flag < 0 || i == 13) {
						flag = -1;
						break;
					}
					flag = -1;
				}
				else if (!std::isdigit(line[i])) {
					flag = 1;
					break;
				}
				else if (flag == -1)
					flag = -2;
			}
			if (flag == 1 || flag == -1) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue; }
			// 0 - 1000 check
			float count = std::atof(line.substr(13, line.length() - 13).c_str());
			if (count == 0) {
				std::cout << "Error: a zero number" << std::endl;
				continue; }
			if (count < 0 || count >= 1000) {
				std::cout << "Error: too large a number." << std::endl;
				continue; }
			// set date
			int	date = std::atoi(line.substr(0, 4).c_str()) * 10000;
			date += std::atoi(line.substr(5, 2).c_str()) * 100;
			date += std::atoi(line.substr(8, 2).c_str());
			// find exact equity
			if (_equity.find(date) != _equity.end()) {
				std::map<int, double>::iterator it = _equity.find(date);
				std::cout << line.substr(0, 10) << " => " << count << " = " << count * it->second << std::endl;
				continue; }
			// find adjacent equity
			std::map<int, double>::iterator min_it = _equity.end();
			int min_date = 20380000;
			for (std::map<int, double>::iterator it = _equity.begin(); it != _equity.end(); it++) {
				if (date - (it->first) < min_date && date - (it->first) > 0) {
					min_it = it;
					min_date = date - (it->first);
				}
			}
			if (min_it != _equity.end()) {
				std::cout << line.substr(0, 10) << " => " << count << " = " << count * min_it->second << std::endl;
				continue; }
			std::cout << "Error: no DB" << std::endl;
		}
	}
	else {
		throw std::runtime_error("Error: could not open file.");
	}
}