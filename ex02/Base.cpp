/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:44:26 by ppontet           #+#    #+#             */
/*   Updated: 2025/07/03 11:26:50 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base::~Base(void)
{
	
}

Base * Base::generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();
	else
		return NULL;
}

void Base::identify(Base* p)
{
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << std::endl;
		else
			throw Base::NotFoundBaseTypeException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void Base::identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception& e) 
	{
		if (DEBUG)
			std::cout << "DynCast of A failed: " << e.what() << std::endl;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception& e) 
	{
		if (DEBUG)
			std::cout << "DynCast of B failed: " << e.what() << std::endl;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception& e) 
	{
		if (DEBUG)
			std::cout << "DynCast of C failed: " << e.what() << std::endl;
	}
	throw Base::NotCorrectBaseTypeException();
}

const char * Base::NotFoundBaseTypeException::what() const throw()
{
	return "Could not find Base type";
}

const char * Base::NotCorrectBaseTypeException::what() const throw()
{
	return "Not a correct Base type";
}

const char * Base::NotGeneratedException::what() const throw()
{
	return "Not generated type";
}
