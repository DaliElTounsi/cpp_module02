#include <cmath>
#include <iostream>

#include "Fixed.hpp"

	const int Fixed::m_bit = 8;

	Fixed::Fixed()
		: m_raw(0)
	{
	}

	Fixed::Fixed(Fixed const &src)
		: m_raw(src.m_raw)
	{
	}

	Fixed::Fixed(int value)
		:  m_raw(value << m_bit)
	{
	}

	Fixed::Fixed(float value)
		: m_raw(roundf(value * (1  << m_bit)))
	{
	}

	Fixed& Fixed::operator=(const Fixed &src)
	{
			if (this == &src)
				return *this;
			m_raw = src.m_raw;
			return *this;
	}

	Fixed::~Fixed()
	{
	}

	int		Fixed::getRawBits() const
	{
		return m_raw;
	}

	void	Fixed::setRawBits(int const raw)
	{
		m_raw = raw;
	}

	std::ostream& operator<<( std::ostream &flux, Fixed const &src )
	{
		flux << src.toFloat();
    	return flux;
	}

	float	Fixed::toFloat() const
	{
		return (static_cast<float>(m_raw) / static_cast<float>(1 << m_bit)); 
	}

	int	Fixed::toInt() const
	{
		return (m_raw >> m_bit);
	}

	Fixed& Fixed::operator+=(Fixed const& src)
	{
		m_raw += src.m_raw;
		return *this;
	}

	Fixed operator+(Fixed const& src, Fixed const& a)
	{
		Fixed result(src);

		result += a;
		return result;
	}

	Fixed& Fixed::operator-=(Fixed const& src)
	{
		m_raw -= src.m_raw;
		return *this;
	}

	Fixed operator-(Fixed const& src, Fixed const& a)
	{
		Fixed result(src);

		result -= a;
		return result;
	}

	Fixed& Fixed::operator*=(Fixed const& src)
	{
		long long prod = static_cast<long long>(m_raw) * static_cast<long long>(src.m_raw);
		m_raw = static_cast<int>(prod >> m_bit);

		return *this;
	}

	Fixed operator*(Fixed const& a, Fixed const& b)
	{
		Fixed result(a);

		result *= b;
		return result;
	}

	Fixed& Fixed::operator/=(Fixed const& src)
	{
		if (src.m_raw == 0)
			return *this;
		long long num = (static_cast<long long>(m_raw) << m_bit);
		m_raw = static_cast<int>(num / src.m_raw);
		return *this;
	}
	
	Fixed operator/(Fixed const& a, Fixed const& b)
	{
		Fixed result(a);
		result /= b;
		return result;
	}

	bool operator==(Fixed const& a, Fixed const& b)
	{
		return (a.getRawBits() == b.getRawBits());
	}


	bool operator!=(Fixed const& a, Fixed const& b)
	{
		return not (a.getRawBits() == b.getRawBits());
	}

	bool operator<(Fixed const& a, Fixed const& b)
	{
		return (a.getRawBits() < b.getRawBits());
	}

	bool operator>(Fixed const& a, Fixed const& b)
	{
		return (a.getRawBits() > b.getRawBits()); 
	}

	bool operator>=(Fixed const& a, Fixed const& b)
	{
		return (a.getRawBits() >= b.getRawBits());
	}

	bool operator<=(Fixed const& a, Fixed const& b)
	{
		return (a.getRawBits() <= b.getRawBits());
	}