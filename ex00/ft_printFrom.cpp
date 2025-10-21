#include "ft_printFrom.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

void print_char(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

#if TEMPLATE_AUTORIZED == 1
template <typename Type>
void print_int(Type nbr)
{
	if (std::isnan(nbr))
		std::cout << "int: impossible" << std::endl;
	else if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
}
#else
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
#endif

void printFromChar(std::string str)
{
	char out;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		out = str[1];
	else
		out = str[0];
	std::cout << "char: '" << out << "'" << std::endl;
	std::cout << "int: '" << static_cast<int>(out) << "'" << std::endl;
	std::cout << "float: " << static_cast<float>(out) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(out) << std::endl;
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
	std::cout << "float: " << static_cast<float>(out) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(out) << std::endl;
}

void printFromFloat(std::string str)
{
	float out;
	out = static_cast<float>(std::atof(str.c_str()));
	print_char(static_cast<char>(out));
	print_int(out);
	size_t dotPos = str.find('.');
	if ((str.length() >= dotPos + 2 &&  str[dotPos + 1] == '0' && str[dotPos + 2] == 'f') || str[dotPos + 1] == 'f')
		std::cout << "float: " << out << ".0f" << std::endl;
	else
		std::cout << "float: " << out << "f" << std::endl;
	if ((str.length() >= dotPos + 2 &&  str[dotPos + 1] == '0' && str[dotPos + 2] == '\0') || dotPos == str.length() - 2)
		std::cout << "double: " << static_cast<double>(out) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(out) << std::endl;
}

#include <sstream>
bool str_to_double(const std::string& str, double& result)
{
	std::istringstream iss(str);
	iss >> result;
	return !iss.fail() && iss.eof();
}

void printFromDouble(std::string str)
{
	double out;
	
	if (!str_to_double(str, out))
	{
		std::cout << "Invalid double conversion." << std::endl;
		return;
	}
	print_char(static_cast<char>(out));
	print_int(out);
	size_t dotPos = str.find('.');
	if ((str.length() == dotPos + 1 ||  str[dotPos + 1] == '0'))
		std::cout << "float: " << out << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(out) << "f" << std::endl;
	if ((str.length() >= dotPos + 2 &&  str[dotPos + 1] == '0' && str[dotPos + 2] == '\0') || str[dotPos + 1] == '\0')
		std::cout << "double: " << out << ".0" << std::endl;
	else
		std::cout << "double: " << out << std::endl;
}

void printFromInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: nan" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
