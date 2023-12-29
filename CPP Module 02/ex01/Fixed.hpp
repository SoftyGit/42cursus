#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixedPointNumberValue;
		static const int	_frationalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &srcs);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed &srcs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const &value);

#endif