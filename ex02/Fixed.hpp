/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:21:02 by zramahaz          #+#    #+#             */
/*   Updated: 2025/02/23 16:28:28 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class   Fixed
{
    private:
        int nb;
        static const int bof = 8;

    public:
        Fixed();
        Fixed(int const integer);
        Fixed(float const floatting);
        Fixed(const Fixed& otherFixed);
        Fixed& operator=(const Fixed& otherFixed);
        ~Fixed();

        Fixed               operator+(const Fixed& otherFixed) const;
        Fixed               operator-(const Fixed& otherFixed) const;
        Fixed               operator*(const Fixed& otherFixed) const;
        Fixed               operator/(const Fixed& otherFixed) const;

        bool                operator>(const Fixed& otherFixed) const;
        bool                operator<(const Fixed& otherFixed) const;
        bool                operator>=(const Fixed& otherFixed) const;
        bool                operator<=(const Fixed& otherFixed) const;
        bool                operator==(const Fixed& otherFixed) const;
        bool                operator!=(const Fixed& otherFixed) const;

        Fixed&              operator++();
        Fixed               operator++(int);
        Fixed&              operator--();
        Fixed               operator--(int);
        
        int                 toInt(void) const;
        float               toFoat(void) const;

        static const Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       min(Fixed& a, Fixed& b);

        friend std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
