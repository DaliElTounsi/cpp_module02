#include <iostream>
#include <cmath>

#include "Fixed.hpp"

	const int Fixed::m_bit = 8;

	Fixed::Fixed()
		: m_raw(0)
	{
		std::cout 
			<< "Default constructor called"
			<< std::endl; 
	}

	Fixed::Fixed(Fixed const &src)
		: m_raw(src.m_raw)
	{
		std::cout 
			<< "Copy constructor called"
			<< std::endl;
	}

	Fixed::Fixed(int value)
		:  m_raw(value << m_bit)
	{
		std::cout << "Int constructor called" << std::endl;
	}

	Fixed::Fixed(float value)
		: m_raw(roundf(value * (1  << m_bit)))
	{
		std::cout << "Float constructor called" << std::endl;

	}

	Fixed& Fixed::operator=(const Fixed &src)
	{
		std::cout
			<< "Copy assignment operator called"
			<< std::endl;
			if (this == &src)
				return *this;
			m_raw = src.m_raw;
			return *this;
	}

	Fixed::~Fixed()
	{
		std::cout 
			<< "Destructor called"
			<< std::endl;
	}

	int		Fixed::getRawBits() const
	{
		std::cout 
			<< "getRawBits member function called" 
			<< std::endl;
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
