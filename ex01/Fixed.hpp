#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <stdint.h>
#include <math.h>

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
	    
        int getRawBits(void) const;
	    void setRawBits(int const raw);
        
        float toFloat(void) const;
        int toInt(void) const;
        

};

std::ostream & operator<<(std::ostream &o, Fixed const &other);

#endif
