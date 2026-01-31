#include <iostream>

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
		(void)m_bit;
		std::cout 
			<< "getRawBits member function called" 
			<< std::endl;
		return m_raw;
	}

	void	Fixed::setRawBits(int const raw)
	{
		m_raw = raw;
	}

