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
#include "ft_types.hpp"
#include "ft_printFrom.hpp"
#include <iostream>

void ScalarConverter::convert(std::string str) const
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
			// std::cout << "Invalid type." << std::endl;
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
