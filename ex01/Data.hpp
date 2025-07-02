#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data
{
	private:
		std::string	s;
		int i;
		float f;
		double d;

	public:
		Data(void);
		~Data(void);
		Data(const Data &src);
		Data &operator=(const Data &rhs);
		
		const std::string &getString(void) const;
		void setString(const std::string &str);
		int getInt(void) const;
		void setInt(int value);
		float getFloat(void) const;
		void setFloat(float value);
		double getDouble(void) const;
		void setDouble(double value);
};

#endif
