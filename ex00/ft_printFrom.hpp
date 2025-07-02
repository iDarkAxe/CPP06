#ifndef FT_PRINTFROM_HPP
# define FT_PRINTFROM_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <sstream>

#ifndef TEMPLATE_AUTORIZED
# define TEMPLATE_AUTORIZED 0
#endif

void print_char(char c);

#if TEMPLATE_AUTORIZED == 1
template <typename Type>
void print_int(Type nbr);
#else
void print_int(double nbr);
void print_int(float nbr);
#endif

void printFromChar(std::string str);

void printFromInt(std::string str);

void printFromFloat(std::string str);

bool str_to_double(const std::string &str, double &result);
void printFromDouble(std::string str);

void printFromInvalid(void);

#endif
