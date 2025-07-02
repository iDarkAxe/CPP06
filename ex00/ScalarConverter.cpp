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
#include <iostream>
#include <cstdlib>
#include <cerrno>

/**
 * @brief Safely convert a string to an integer using errno and strtol
 * 
 * @param str string to convert
 * @param out number to output
 * @return int 1 if success, 0 if error
 */
int ft_strtol(const char *str, long *out)
{
    char *endptr;
    long val;

    errno = 0;
    val = std::strtol(str, &endptr, 10);
    if (errno == ERANGE || val > 2147483647 || val < -2147483648)
	{
		// std::cout << "Number is way above int limits (-2147483648 to 2147483647)" << std::endl;
		return (1);
	}
    if (endptr == str || *endptr != '\0')
	{
		// std::cout << "Please enter a valid number" << std::endl;
		return (2);
	}
    *out = val;
    return (1);
}

void ScalarConverter::convert(std::string str) const
{
	int ret;
	long out;

	if (str.empty())
	{
		std::cout << "Please enter a valid number." << std::endl;
		return;
	}
	ret = ft_strtol(str.c_str(), &out);
	std::cout << "char: " << static_cast<char>(out) << std::endl;
	if (ret == 1)
	
	std::cout << "int: " << static_cast<int>(out) << std::endl;
	std::cout << "float: " << static_cast<float>(out) << std::endl;
	std::cout << "double: " << static_cast<double>(out) << std::endl;
}
