#include "ft_types.hpp"
#include <iostream>

std::string ft_trim(const std::string &str)
{
	std::string trimmed_str;

	if (str.length() == 0 || str.length() == 1)
		return str;
	trimmed_str = str.substr(0, str.find_last_not_of(" \t\n\r\f\v") + 1);
	if (trimmed_str.empty())
		return trimmed_str;
	trimmed_str = trimmed_str.substr(trimmed_str.find_first_not_of(" \t\n\r\f\v"), trimmed_str.length());
	return trimmed_str;
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

bool isChar(const std::string& str) {
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool isInt(const std::string& str) {
	if (str.empty()) return false;

	size_t i;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	if (i >= str.length()) return false;
	
	for (; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) return false;
	}
	return true;
}

bool isSpecialFloat(const std::string& str) {
	return (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf");
}

bool isSpecialDouble(const std::string& str) {
	return (str == "inf" || str == "+inf" || str == "-inf" || str == "nan");
}

bool isFloatingPoint(const std::string& str, bool& hasF) {
	if (str.empty())
		return false;
	
	if (isSpecialDouble(str)) {
		hasF = false;
		return true;
	}
	if (isSpecialFloat(str)) {
		hasF = true;
		return true;
	}

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

e_type getType(const std::string& str)
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
