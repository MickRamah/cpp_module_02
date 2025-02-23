/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:17:34 by zramahaz          #+#    #+#             */
/*   Updated: 2025/02/23 11:50:57 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() :  nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer) : nb(integer << bof)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatting) : nb(static_cast<int>(roundf(floatting * (1 << bof))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed) : nb(otherFixed.nb)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& otherFixed)
{
    if (this != &otherFixed)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->nb = otherFixed.nb;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float   Fixed::toFloat(void) const
{
    return ((float)nb / (1 << bof));
}

int   Fixed::toInt(void) const
{
    return (nb / (1 << bof));
}

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}