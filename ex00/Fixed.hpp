/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:03:41 by zramahaz          #+#    #+#             */
/*   Updated: 2025/02/22 14:41:03 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_CANON_H
# define FIRST_CANON_H

# include <iostream>

class   Fixed
{
    private:
        int nb;
        static const int    bof = 8;

    public:
        Fixed();
        Fixed(const Fixed& otherFixed);
        Fixed&  operator=(const Fixed& otherFixed);  
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif