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

		bool	operator>(const Fixed &srcs) const;
		bool	operator<(const Fixed &srcs) const;
		bool	operator>=(const Fixed &srcs) const;
		bool	operator<=(const Fixed &srcs) const;
		bool	operator==(const Fixed &srcs) const;
		bool	operator!=(const Fixed &srcs) const;

		Fixed	operator+(const Fixed &srcs) const;
		Fixed	operator-(const Fixed &srcs) const;
		Fixed	operator*(const Fixed &srcs) const;
		Fixed	operator/(const Fixed &srcs) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static	Fixed& min(Fixed &a, Fixed &b);
		static	const Fixed& min(const Fixed &a, const Fixed &b);
		static	Fixed& max(Fixed &a, Fixed &b);
		static	const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& out, Fixed const &value);

#endif