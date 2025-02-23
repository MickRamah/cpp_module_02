/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:30:46 by zramahaz          #+#    #+#             */
/*   Updated: 2025/02/23 16:30:20 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTEUR CANON */
Fixed::Fixed() : nb(0)
{
}

Fixed::Fixed(int const integer) : nb(integer << bof)
{
}

Fixed::Fixed(float const floatting) : nb(static_cast<int>(roundf(floatting * (1 << bof))))
{
}

Fixed::Fixed(const Fixed& otherFixed) : nb(otherFixed.nb)
{
}

Fixed& Fixed::operator=(const Fixed& otherFixed)
{
    if (this != &otherFixed)
        this->nb = otherFixed.nb;
    return (*this);
}

Fixed::~Fixed()
{
}

/* SURCHARGE DES OPERATEURS DE COMPARAISON */
bool    Fixed::operator>(const Fixed& otherFixed) const
{
    return (this->nb > otherFixed.nb);
}

bool    Fixed::operator<(const Fixed& otherFixed) const
{
    return (this->toFoat() < otherFixed.toFoat());
}

bool    Fixed::operator>=(const Fixed& otherFixed) const
{
    return (this->toFoat() >= otherFixed.toFoat());
}

bool    Fixed::operator<=(const Fixed& otherFixed) const
{
    return (this->toFoat() <= otherFixed.toFoat());
}

bool    Fixed::operator==(const Fixed& otherFixed) const
{
    return (this->toFoat() == otherFixed.toFoat());
}

bool    Fixed::operator!=(const Fixed& otherFixed) const
{
    return (this->toFoat() != otherFixed.toFoat());
}

/* SURCHARGE DES OPERATEURS ARITHMETIQUE */
Fixed  Fixed::operator+(const Fixed& otherFixed) const
{
    return (Fixed(this->toFoat() + otherFixed.toFoat()));
}

Fixed   Fixed::operator-(const Fixed& otherFixed) const
{
    return (Fixed(this->toFoat() - otherFixed.toFoat()));
}

Fixed   Fixed::operator*(const Fixed& otherFixed) const
{
    return (Fixed(this->toFoat() * otherFixed.toFoat()));
}

Fixed   Fixed::operator/(const Fixed& otherFixed) const
{
    return (Fixed(this->toFoat() / otherFixed.toFoat()));
}

/* SURCHARGE DES OPERATEURS D' INCRE/DECRE , PRE ET POS */
Fixed&  Fixed::operator++()
{
    ++(this->nb);
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   Tmp = *this;

    ++(this->nb);
    return (Tmp);
}

Fixed& Fixed::operator--()
{
    --(this->nb);
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed   Tmp = *this;

    --(this->nb);
    return (Tmp);
}

/* FONCTION MEMBRES */
int Fixed::toInt(void) const
{
    return ((nb / (1 << bof)));
}

float   Fixed::toFoat(void) const
{
    return (((float)nb / (1 << bof)));
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

/* FONCTION FRIEND */
std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFoat();
    return (os);
}
