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

e_type getType(const std::string &str)
{
	if (str.empty())
		return TYPE_INVALID;

	if (str.length() == 1 && std::isprint(str[0]) && str[0] != ' ' && !std::isdigit(str[0]))
		return TYPE_CHAR;
 	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return TYPE_CHAR;
	if (str.length() == 4 && str[0] == '\'' && str[3] == '\'' && str[1] == '\\')
	{
		switch (str[2])
		{
			case 'n': case 't': case 'v': case 'b':
			case 'r': case 'f': case 'a': case '\\': case '\'': case '\"':
				return TYPE_CHAR;
			default:
				return TYPE_INVALID;
		}
	}

	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan" || str == "+nan" || str == "-nan")
		return TYPE_FLOAT;

	if (str.find('f') != std::string::npos && str.find('.') == std::string::npos)
	{
		if (DEBUG)
			std::cout << "f without '.' is invalid" << std::endl;
		return TYPE_INVALID;
	}
	if (str.find('f') != std::string::npos && str[str.length() - 1] != 'f')
	{
		if (DEBUG)
			std::cout << "f must be at the end" << std::endl;
		return TYPE_INVALID;
	}
	if (str.find('.') != str.rfind('.') || str.find('f') != str.rfind('f'))
	{
		if (DEBUG)
			std::cout << "Multiple '.' or 'f' found" << std::endl;
		return TYPE_INVALID;
	}

	bool hasPoint = false;
	bool hasF = false;
	bool hasANumber = false;
	for (size_t i = 0; i < str.length(); ++i)
	{
		char c = str[i];
	
		if (c == '.')
		{
			hasPoint = true;
			continue;
		}
		if (c == 'f')
		{
			hasF = true;
			continue;
		}
		if (std::isdigit(c) && hasANumber == false)
		{
			hasANumber = true;
			continue;
		}
		if (i == 0 && (c == '-' || c == '+'))
			continue;
		if (!std::isdigit(c))
			return TYPE_INVALID;
	}
	if (!hasANumber)
		return TYPE_INVALID;
	if (hasPoint && hasF)
		return TYPE_FLOAT;
	if (hasPoint)
		return TYPE_DOUBLE;
	return TYPE_INT;
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
