/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:18:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/03 11:17:05 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>

#define ITERATIONS 10

// Only generate seed once at the start of the program.
// std::srand(std::time(NULL));

// Mandatory
int main(void)
{
	std::srand(std::time(NULL));
	Base *base;
	try 
	{
		base = Base::generate();
		if (base == NULL)
			throw Base::NotGeneratedException();
	} 
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	std::cout << "Generated Base instance of type: " << std::endl;
	Base::identify(base);
	delete base;
	std::cout << std::endl;
	
	try 
	{
		base = Base::generate();
		if (base == NULL)
			throw Base::NotGeneratedException();
	} 
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	
	Base &base2 = *base;
	std::cout << "Generated Base instance of type ptr: " << std::endl;
	Base::identify(base);
	std::cout << "Generated Base instance of type ref: " << std::endl;
	Base::identify(base2);
	delete base;
	return 0;
}

// More tests
// int main(void)
// {
// 	std::srand(std::time(NULL));
// 	{
// 		Base *base;
// 		for (int i = 0; i < ITERATIONS; ++i)
// 		{
// 			base = Base::generate();
// 			Base::identify(base);
// 			delete base;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		Base *base;
// 		for (int i = 0; i < ITERATIONS; ++i)
// 		{
// 			try
// 			{
// 				base = Base::generate();
// 				if (base == NULL)
// 					throw Base::NotGeneratedException();
// 			} 
// 			catch (const std::exception& e) 
// 			{
// 				std::cout << e.what() << std::endl;
// 				return (1);
// 			}
// 			Base &base2 = *base;
// 			Base::identify(base2);
// 			delete base;
// 		}
// 	}
// 	return 0;
// }
