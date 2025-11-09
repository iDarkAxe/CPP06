#ifndef FT_TYPES_HPP
# define FT_TYPES_HPP

# include <string>

# ifndef DEBUG
#  define DEBUG 0
# endif

enum e_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

std::string ft_trim(const std::string &str);
e_type getType(const std::string &str);
bool isSpecialFloat(const std::string &str);
bool isSpecialDouble(const std::string &str);
void printType(const e_type type);

#endif
