/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:53:40 by moduwole          #+#    #+#             */
/*   Updated: 2023/07/12 01:53:40 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(const int integer) {

	this->_fixedPoint = integer << Fixed::_fracBits; // DINE
}

Fixed::Fixed(const float floatPoint) {

	this->_fixedPoint = round(floatPoint * (1 << Fixed::_fracBits)); // DONE
}

Fixed::Fixed(Fixed const &other) {

	*this = other;  // DONE
}

Fixed::~Fixed() {}

Fixed	&Fixed::operator=(Fixed const &other) {

	if (this == &other)
		return *this;
	this->_fixedPoint = other.getRawBits(); // DONE
	return *this;
}

int	Fixed::getRawBits( void ) const {

	return this->_fixedPoint;  // DONE
}

void	Fixed::setRawBits(int const raw) {

	this->_fixedPoint = raw; // DONE
}

float	Fixed::toFloat( void ) const {

	return (float)this->_fixedPoint / (float) (1 << Fixed::_fracBits); // DONE
}

int	Fixed::toInt ( void ) const {

	return this->_fixedPoint >> Fixed::_fracBits; // DONE
}

bool	Fixed::operator>(Fixed const &other) const {

	return this->_fixedPoint > other.getRawBits();
}

bool	Fixed::operator<(Fixed const &other) const {

	return this->_fixedPoint < other.getRawBits();
}

bool	Fixed::operator<=(Fixed const &other) const {

	return this->_fixedPoint <= other.getRawBits();
}

bool	Fixed::operator>=(Fixed const &other) const {

	return this->_fixedPoint >= other.getRawBits();
}

bool	Fixed::operator==(Fixed const &other) const {

	return this->_fixedPoint == other.getRawBits();
}

bool	Fixed::operator!=(Fixed const &other) const {

	return this->_fixedPoint != other.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &other) const{
	return this->toFloat() + other.toFloat();
}

Fixed	Fixed::operator-(Fixed const &other) const{
	return this->toFloat() - other.toFloat();
}

Fixed	Fixed::operator*(Fixed const &other) const{
	return this->toFloat() * other.toFloat();
}

Fixed	Fixed::operator/(Fixed const &other) const{
	return this->toFloat() / other.toFloat();
}

Fixed	&Fixed::operator++(void)
{
	++this->_fixedPoint;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	--this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	this->_fixedPoint++;
	Fixed tmp(*this);
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	this->_fixedPoint--;
	Fixed tmp(*this);
	return tmp;
}

Fixed	&Fixed::min(Fixed &point_1, Fixed &point_2)
{
	if (point_1 < point_2)
		return point_1;
	return point_2;
}

const Fixed	&Fixed::min(const Fixed &point_1, const Fixed &point_2)
{
	if (point_1 < point_2)
		return point_1;
	return point_2;
}

Fixed	&Fixed::max(Fixed &point_1, Fixed &point_2)
{
	if (point_1 > point_2)
		return point_1;
	return point_2;
}

const Fixed	&Fixed::max(const Fixed &point_1, const Fixed &point_2)
{
	if (point_1 > point_2)
		return point_1;
	return point_2;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {

	return o << fixed.toFloat();
}
