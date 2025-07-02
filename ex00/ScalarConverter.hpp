#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &rhs);

	public:
		static void convert(std::string number);
};

#endif
