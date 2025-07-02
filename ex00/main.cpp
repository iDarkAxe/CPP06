/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/02 11:46:21 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ft_types.hpp"
#include <iostream>

// const float infini_plus = 1.0f / 0.0f; // +∞
// const float infini_moins = -1.0f / 0.0f; // -∞
// const float notanumber = 0.0f / 0.0f; // NaN
int exhaustive_test();

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		// std::cout << "Usage: " << argv[0] << " <number to display>" << std::endl;
		exhaustive_test();
		return 1;
	}
	std::string trimmed = ft_trim(argv[1]);
	if (trimmed.empty())
		return TYPE_INVALID;
	std::cout << "Orig: '" << argv[1] << "'" << std::endl;
	std::cout << "Trim: '" << trimmed << "'" << std::endl;

	e_type type = getType(trimmed);
	printType(type);

	return 0;
}
	
/*
int : 		0,		-42,	42
float : 	0.0f,	-4.2f,	4.2f
double : 	0.0, 	-4.2,	4.2
char : 		'a',	'\0',	'1',	' ',	'9'
char : 		a,		\0,		1,		' ',	9
*/

int exhaustive_test()
{
	const std::string test_cases[] = {
		"42", "-42", "0", "3.14f", "-3.14f", "3.14", "-3.14",
		"'a'", "'\t'", "'1'", "' '", "'9'", "inf", "+inf", "-inf",
		"nan", "+nan", "-nan"
	};
	e_type expected_type[] = {
		TYPE_INT, TYPE_INT, TYPE_INT, TYPE_FLOAT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_DOUBLE,
		TYPE_CHAR, TYPE_CHAR, TYPE_CHAR, TYPE_CHAR, TYPE_CHAR, TYPE_FLOAT, TYPE_FLOAT, TYPE_FLOAT,
		TYPE_FLOAT, TYPE_FLOAT, TYPE_FLOAT
	};
	e_type type;
	
	for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i)
	{
		std::cout << "Testing: '" << test_cases[i] << "'" << std::endl;
		type = getType(test_cases[i]);
		if (expected_type[i] != type)
		{
			std::cout << "Expected type: " << std::endl;
			printType(expected_type[i]);
			std::cout << "Got: " << std::endl;
			printType(type);
		}
		else
		{
			std::cout << "Type matches: " << std::endl;
			printType(type);
		}
		std::cout << "__________" << std::endl;
	}

	return 0;
}
