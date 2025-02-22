/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:02:56 by zramahaz          #+#    #+#             */
/*   Updated: 2025/02/22 15:07:40 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed) : nb(otherFixed.nb)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed&   Fixed::operator=(const Fixed& otherFixed)
{
    if (this != &otherFixed)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->nb = otherFixed.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (nb);
}

void    Fixed::setRawBits(int const raw)
{
    nb = raw;
}