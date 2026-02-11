#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _i;
	static const int _bits = 8;

  public:
	Fixed();
	Fixed(Fixed const &copy);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif