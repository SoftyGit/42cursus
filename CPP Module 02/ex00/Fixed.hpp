#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_fixedPointNumberValue;
		static const int	_frationalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &srcs);
		Fixed& operator=(const Fixed &srcs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif