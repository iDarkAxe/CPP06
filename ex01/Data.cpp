/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:44:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/02 17:58:46 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Data::Data(void)
{
	this->s = "";
	this->i = 0;
	this->f = 0.0f;
	this->d = 0.0;
}
Data::~Data(void)
{
	
}
Data::Data(const Data &src)
{
	this->s = src.s;
	this->i = src.i;
	this->f = src.f;
	this->d = src.d;
}
Data &Data::operator=(const Data &rhs)
{
	this->s = rhs.s;
	this->i = rhs.i;
	this->f = rhs.f;
	this->d = rhs.d;
	return *this;
}

const std::string &Data::getString(void) const
{
	return this->s;
}
void Data::setString(const std::string &str)
{
	this->s = str;
}
int Data::getInt(void) const
{
	return this->i;
}
void Data::setInt(int value)
{
	this->i = value;
}
float Data::getFloat(void) const
{
	return this->f;
}
void Data::setFloat(float value)
{
	this->f = value;
}
double Data::getDouble(void) const
{
	return this->d;
}
void Data::setDouble(double value)
{
	this->d = value;
}
