#include "ft_printFrom.hpp"
#include "ft_types.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

void print_char(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void print_int(double nbr)
{
	if (std::isnan(nbr))
		std::cout << "int: impossible" << std::endl;
	else if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
}
void print_int(float nbr)
{
	if (std::isnan(nbr))
		std::cout << "int: impossible" << std::endl;
	else if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
}

void printFromChar(std::string str)
{
	char out;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		out = str[1];
	else
		out = str[0];
	std::cout << "char: '" << out << "'" << std::endl;
	std::cout << "int: '" << static_cast<int>(out) << "'" << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(out) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(out) << std::endl;
}

void printFromInt(std::string str)
{
	int out;
	std::stringstream iss(str);
	iss >> out;
	if (out < 0 || out > 255)
		print_char(static_cast<char>(1));
	else
		print_char(static_cast<char>(out));
	std::cout << "int: " << out << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(out) << "f" << std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(out) << std::endl;
}

void printFromFloat(std::string str)
{
	float out;
	if (isSpecialFloat(str))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return;
	}
	out = std::atof(str.c_str());
	print_char(static_cast<char>(out));
	print_int(out);
	std::cout << "float: " << std::fixed << out << "f" << std::endl;
	std::cout << "double: " << std::fixed << out << std::endl;
}

void printFromDouble(std::string str)
{
	double out;

	if (isSpecialDouble(str))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return;
	}
	std::istringstream iss(str);
	iss >> out;
	if (iss.fail() || !iss.eof())
	{
		std::cout << "Invalid double conversion." << std::endl;
		return;
	}
	print_char(static_cast<char>(out));
	print_int(out);
	std::cout << "float: " << std::fixed << out << "f" << std::endl;
	std::cout << "double: " << std::fixed << out << std::endl;
}

void printFromInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
