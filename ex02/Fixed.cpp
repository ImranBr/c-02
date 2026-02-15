#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _Bits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = f * (1 << _Bits);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &other)
{
	o << other.toFloat();
	return (o);
}

float Fixed::toFloat() const
{
	return (float)_rawBits / (1 << _Bits);
}

int Fixed::toInt() const
{
	return (_rawBits >> _Bits);
}

// COMPARAISON OPERATORS
bool Fixed::operator<(const Fixed &other)
{
	if (_rawBits < other._rawBits)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed &other)
{
    if (_rawBits > other._rawBits)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other)
{
    if (_rawBits <= other._rawBits)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other)
{
    if (_rawBits >= other._rawBits)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other)
{    
    if (_rawBits == other._rawBits)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other)
{
    if (_rawBits != other._rawBits)
		return (true);
	return (false);
}

//ARITHMETIC OPERATORS
Fixed Fixed::operator+(const Fixed &other)
{
    Fixed c;
    c._rawBits =_rawBits + other._rawBits;
    return (c);
}

Fixed Fixed::operator-(const Fixed &other)
{   
    Fixed c;
    c._rawBits =_rawBits - other._rawBits;
    return (c);
}

Fixed Fixed::operator*(const Fixed &other)
{   
    Fixed c;
    c._rawBits = (_rawBits * other._rawBits) >> _Bits;
    // >> _Bits = 2^8 = * 256
    return (c);
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed c;
    c._rawBits = (_rawBits / other._rawBits) << _Bits;
    // << _Bits = 2^8 = / 256
    return (c);
}

// INCREMENT/DECREMENT
Fixed &Fixed::operator++()
{
    ++_rawBits;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed plus(*this);
    _rawBits++;
    return (plus);
}

Fixed &Fixed::operator--()
{
    --_rawBits;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed minus(*this);
    _rawBits--;
    return (minus);
}

// MIN-MAX
Fixed const & Fixed::min(Fixed const &left, Fixed const &right)
{
    if (left.getRawBits() < right.getRawBits())
        return (left);
    return (right);
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
    if (left.getRawBits() < right.getRawBits())
        return (left);
    return (right);
}

Fixed const & Fixed::max(Fixed const &left, Fixed const &right)
{
    if (left.getRawBits() > right.getRawBits())
        return (left);
    return (right);
}

Fixed & Fixed::max(Fixed &left, Fixed &right)
{
    if (left.getRawBits() > right.getRawBits())
        return (left);
    return (right);
}