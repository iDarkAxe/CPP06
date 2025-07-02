/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/02 18:09:58 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

void printData(const Data &data);

void printData(const Data &data)
{
	std::cout << "Data s: " << data.getString() << std::endl;
	std::cout << "Data i: " << data.getInt() << std::endl;
	std::cout << "Data f: " << data.getFloat() << std::endl;
	std::cout << "Data d: " << data.getDouble() << std::endl;
}

// Mandatory
int main(void)
{
	std::string str;
	uintptr_t raw;

	Data *input = new Data;
	if (!input) {
		std::cout << "Memory allocation failed for input." << std::endl;
		return 1;
	}
	input->setString("Hello, World!");
	input->setInt(887);
	input->setFloat(1212.2121f);
	input->setDouble(57181.12858);
	std::cout << "Input val:\n\t" << input << std::endl;
	printData(*input);
	std::cout << std::endl;
	
	raw = Serializer::serialize(input);
	if (!raw) {
		std::cout << "Serialization failed: input is null." << std::endl;
		delete input;
		return 1;
	}
	std::cout << "Raw val:\n\t" << raw << std::endl;
	std::cout << std::endl;

	Data *output;
	output = Serializer::deserialize(raw);
	if (!output) {
		std::cout << "Deserialization failed: output is null." << std::endl;
		delete input;
		return 1;
	}
	
	std::cout << "Ouput val:\n\t" << output << std::endl;
	printData(*output);

	delete input;
	return 0;
}

// More tests
// int main(void)
// {
// 	std::string str;
// 	uintptr_t raw;

// 	Data *input = new Data;
// 	if (!input) {
// 		std::cout << "Memory allocation failed for input." << std::endl;
// 		return 1;
// 	}
// 	input->setString("Hello, World!");
// 	input->setInt(42);
// 	input->setFloat(2.71828f);
// 	input->setDouble(3.14159);
// 	std::cout << "Input val:\n\t" << input << std::endl;
// 	std::cout << "Input addr:\n\t" << &input << std::endl;
// 	printData(*input);
// 	std::cout << std::endl;
	
// 	try {
// 		raw = Serializer::serialize(input);
// 		if (!raw) {
// 			std::cout << "Serialization failed: input is null." << std::endl;
// 			delete input;
// 			return 1;
// 		}
// 	} catch (const std::exception &e) {
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 		delete input;
// 		return 1;
// 	}
// 	std::cout << "Raw val:\n\t" << raw << std::endl;
// 	std::cout << "Raw addr:\n\t" << &raw << std::endl;
// 	std::cout << std::endl;

// 	Data *output;
// 	try {
// 		output = Serializer::deserialize(raw);
// 		if (!output) {
// 			std::cout << "Deserialization failed: output is null." << std::endl;
// 			delete input;
// 			return 1;
// 		}
// 	} catch (const std::exception &e) {
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 		delete input;
// 		return 1;
// 	}
// 	std::cout << "Ouput val:\n\t" << output << std::endl;
// 	std::cout << "Ouput addr:\n\t" << &output << std::endl;
// 	printData(*output);

// 	delete input;
// 	return 0;
// }
