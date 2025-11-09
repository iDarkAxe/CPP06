/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/11/09 21:51:15 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ft_types.hpp"
#include <iostream>
#include "ft_printFrom.hpp"

#ifndef PRINT_TESTED
#define PRINT_TESTED 1
#endif

int exhaustive_type_test();
int exhaustive_convert_test();

/*
Acceptable input:
int : 		0,		-42,	42,		9
float : 	0.0f,	-4.2f,	4.2f
double : 	0.0, 	-4.2,	4.2
char : 		'a',	'\0',	' ',	'1',	'9'
char : 		a,		\0,		' '

char : only a single character between single quotes or a not a digit
int: only numbers
double: int + . point
float: double + f at the end
*/

// Mandatory
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <number to display>" << std::endl;
		return 1;
	}
	std::string trimmed = ft_trim(argv[1]);
	ScalarConverter::convert(trimmed);
	return 0;
}

// Exhaustive tests
// int main(void)
// {
// 	exhaustive_type_test();
// 	exhaustive_convert_test();
// 	return (0);
// }

int exhaustive_convert_test()
{
	const std::string test_cases[] = {
		"42", "-42", "0", "3.14f", "-3.14f", "3.14", "-3.14",
		"'a'", "'\t'", "'1'", "' '", "'9'", "inf", "+inf", "-inf",
		"nan", "+nan", "-nan", ".", ".f", "0.f", ".0f"
	};
	const size_t nbr_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < nbr_tests; ++i)
	{
		if (PRINT_TESTED)
			std::cout << "Testing: '" << test_cases[i] << "'" << std::endl;
		ScalarConverter::convert(test_cases[i]);
		std::cout << "__________" << std::endl;
	}
	return 0;
}

int exhaustive_type_test()
{
	const std::string test_cases[] = {
		"42", "-42", "0", "3.14f", "-3.14f", "3.14", "-3.14",
		"'a'", "'\t'", "'1'", "' '", "'9'", "inff", "+inff", "-inff",
		"nanf", "inf", "+inf", "-inf",
		"nan", ".", ".f", "0.f", ".0f"
	};
	e_type expected_type[] = {
		TYPE_INT, TYPE_INT, TYPE_INT, TYPE_FLOAT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_DOUBLE,
		TYPE_CHAR, TYPE_CHAR, TYPE_CHAR, TYPE_CHAR, TYPE_CHAR, TYPE_FLOAT, TYPE_FLOAT, TYPE_FLOAT,
		TYPE_FLOAT, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
		TYPE_DOUBLE, TYPE_CHAR, TYPE_INVALID, TYPE_FLOAT, TYPE_FLOAT
	};
	e_type type;
	const size_t nbr_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	
	for (size_t i = 0; i < nbr_tests; ++i)
	{
		if (PRINT_TESTED)
			std::cout << "Testing: '" << test_cases[i] << "'" << std::endl;
		type = getType(test_cases[i]);
		if (expected_type[i] != type)
		{
			std::cout << "Error: " << test_cases[i] <<", Expected type: " << std::endl;
			printType(expected_type[i]);
			std::cout << "Got: " << std::endl;
			printType(type);
		}
		else
		{
			std::cout << "OK ! " << test_cases[i] << " :" << std::endl;
			printType(type);
		}
		std::cout << "__________" << std::endl;
	}
	return 0;
}
