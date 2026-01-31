#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	
public :
	Fixed();
	Fixed(Fixed const &src);
	Fixed(int value);
	Fixed(float value);
	Fixed& operator=(const Fixed &src);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	Fixed& operator+=(Fixed const& src);
	Fixed& operator-=(Fixed const& src);
	Fixed& operator*=(Fixed const& src);
	Fixed& operator/=(Fixed const& src);

private :
		int m_raw;
		static const int m_bit;

};

Fixed operator+(Fixed const& src, Fixed const& a);
Fixed operator-(Fixed const& src, Fixed const& a);
Fixed operator*(Fixed const& a, Fixed const& b);
Fixed operator/(Fixed const& a, Fixed const& b);


std::ostream& operator<<(std::ostream& flux, Fixed const& src);
bool operator==(Fixed const& a, Fixed const& b);
bool operator!=(Fixed const& a, Fixed const& b);
bool operator<(Fixed const& a, Fixed const& b);
bool operator>(Fixed const& a, Fixed const& b);
bool operator>=(Fixed const& a, Fixed const& b);
bool operator<=(Fixed const& a, Fixed const& b);


#endif