/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:09:39 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/08/12 12:10:19 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
}

Fixed::Fixed(const Fixed& copy)
{
    *this = copy;
}

Fixed::Fixed(const int value)
{
    this->_fp_value = value << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::~Fixed()
{
}

bool	Fixed::operator<(Fixed fixed)const
{
    return (this->_fp_value < fixed.getRawBits());
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed Fixed::operator+(Fixed fixed)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return(result);
}

Fixed Fixed::operator-(Fixed fixed)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return(result);
}

Fixed Fixed::operator*(Fixed fixed)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * fixed.getRawBits());
	result.setRawBits(result.getRawBits() >> this->_fract_bits);
	return(result);
}

Fixed Fixed::operator/(Fixed fixed)const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << this->_fract_bits)/ fixed.getRawBits());
	result.setRawBits(result.getRawBits());
	return(result);
}

Fixed Fixed::operator++(void)
{
	this->_fp_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(void)
{
	this->_fp_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

int Fixed::getRawBits(void)const
{
    return this->_fp_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}
