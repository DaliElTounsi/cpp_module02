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

private :
		int m_raw;
		static const int m_bit;

};

std::ostream& operator<<(std::ostream& flux, Fixed const& src);



#endif