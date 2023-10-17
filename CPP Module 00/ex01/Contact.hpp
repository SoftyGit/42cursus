#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		std::string _input(std::string str) const;

	public:
		Contact();
		~Contact();
		void	init(void);
};

#endif