#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _rawBits;
        static int const _Bits = 8;
        
    public:
        Fixed();
        Fixed(int const n);
        Fixed (float const f);
    	Fixed(Fixed const &copy);
        ~Fixed();

        Fixed &operator=(const Fixed &other);
        
        // COMPARAISON OPERATORS
        bool operator<(const Fixed &other);
        bool operator>(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);

        // ARITHMETIC OPERATORS
        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);

        // INCREMENT/DECREMENT
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        // MIN-MAX
        static Fixed const &min(Fixed const &left, Fixed const &right);
        static Fixed &min(Fixed &left, Fixed &right);
        static Fixed const & max(Fixed const &left, Fixed const &right);
        static Fixed &max(Fixed &left, Fixed &right);

        int getRawBits(void) const;
	    void setRawBits(int const raw);
        
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const &other);

#endif