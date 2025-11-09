/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalaScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:34 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/01 14:08:57 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ft_printFrom.hpp"
#include <iostream>

# ifndef DEBUG
#  define DEBUG 1
# endif

enum e_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

void printType(const e_type type);
static e_type getType(const std::string &str);

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

void ScalarConverter::convert(std::string str)
{
	if (str.empty())
	{
		std::cout << "Please enter a valid number." << std::endl;
		return;
	}
	e_type type = getType(str);
	if (DEBUG)
		printType(type);
	switch(type)
	{
		case TYPE_INVALID:
			printFromInvalid();
			break;
		case TYPE_CHAR:
			printFromChar(str);
			break;
		case TYPE_INT:
			printFromInt(str);
			break;
		case TYPE_FLOAT:
			printFromFloat(str);
			break;
		case TYPE_DOUBLE:
			printFromDouble(str);
			break;
		default:
			std::cout << "Unknown type." << std::endl;
			return;
	}
}

void printType(const e_type type)
{
	switch(type)
	{
		case TYPE_CHAR:
			std::cout << "Type: char" << std::endl;
			break;
		case TYPE_INT:
			std::cout << "Type: int" << std::endl;
			break;
		case TYPE_FLOAT:
			std::cout << "Type: float" << std::endl;
			break;
		case TYPE_DOUBLE:
			std::cout << "Type: double" << std::endl;
			break;
		case TYPE_INVALID:
			std::cout << "Type: invalid" << std::endl;
			break;
		default:
			std::cout << "Unknown type" << std::endl;
			break;
	}
}

static bool isChar(const std::string& str) {
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return true;
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    return false;
}

static bool isInt(const std::string& str) {
    if (str.empty()) return false;
    
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-') i = 1;
    if (i >= str.length()) return false;
    
    for (; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

static bool isSpecialFloat(const std::string& str) {
    return (str == "inff" || str == "+inff" || str == "-inff" || 
            str == "nanf");
}

static bool isSpecialDouble(const std::string& str) {
    return (str == "inf" || str == "+inf" || str == "-inf" || 
            str == "nan");
}

static bool isFloatingPoint(const std::string& str, bool& hasF) {
    if (str.empty()) 
        return false;
    
    hasF = false;
    size_t len = str.length();
    
    // Check for 'f' at the end
    if (str[len - 1] == 'f') {
        hasF = true;
        len--;
        if (len == 0) return false;
    }
    
    // Check special values
    if (hasF && isSpecialFloat(str))
		return true;
    if (!hasF && isSpecialDouble(str))
		return true;
    
	std::string checkStr = str.substr(0, len);
	size_t i;
    if (checkStr[0] == '+' || checkStr[0] == '-') 
        i = 1;
    else 
		i = 0;
    bool hasDigit = false;
    bool hasDot = false;
    
    for (; i < len; ++i) {
        if (checkStr[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (std::isdigit(checkStr[i])) {
            hasDigit = true;
        } else {
            return false;
        }
    }
    
    return hasDigit && hasDot;
}

static e_type getType(const std::string& str)
{
    if (isChar(str)) return TYPE_CHAR;
    if (isInt(str)) return TYPE_INT;
    
    bool hasF = false;
    if (isFloatingPoint(str, hasF))
	{
		if (hasF)
			return TYPE_FLOAT;
		return TYPE_DOUBLE;
    }
    
    return TYPE_INVALID;
}
