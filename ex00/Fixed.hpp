#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed& operator=(const Fixed &src);
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);

private:
		int m_raw;
		static const int m_bit;

};

#endif