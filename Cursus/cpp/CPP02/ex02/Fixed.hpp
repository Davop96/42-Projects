/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:12:35 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/08/12 12:11:16 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed& copy);

		~Fixed();
		
			bool operator<(Fixed fixed)const;
			bool operator>(Fixed fixed)const;
			bool operator>=(Fixed fixed)const;
			bool operator<=(Fixed fixed)const;
			bool operator==(Fixed fixed)const;
			bool operator!=(Fixed fixed)const;

			Fixed operator+(Fixed fixed)const;
			Fixed operator-(Fixed fixed)const;
			Fixed operator*(Fixed fixed)const;
			Fixed operator/(Fixed fixed)const;
			Fixed operator++(void);
			Fixed operator++(int);
			Fixed operator--(void);
			Fixed operator--(int);

		float toFloat(void)const;
		int toInt(void)const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);

		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
