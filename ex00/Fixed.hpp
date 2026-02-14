#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
  private:
	int _rawBits;
	static const int _bits = 8;

  public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const &copy);
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif