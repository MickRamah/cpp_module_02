/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:39 by zramahaz          #+#    #+#             */
/*   Updated: 2025/02/23 16:31:31 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int     nb;
        static const int    bof = 8;

    public:
        Fixed();
        Fixed(int const integer);
        Fixed(float const floatting);
        Fixed(const Fixed& otherFixed);
        Fixed&  operator=(const Fixed& otherFixed);
        ~Fixed();

        float   toFloat(void) const;
        int   toInt(void) const;
        friend std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);
};

#endif