#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	private:
		static int	_index;
		Contact		_contact[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	add(void);
		void	search(void);
};

#endif