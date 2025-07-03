#ifndef BASE_HPP
# define BASE_HPP

#include <exception>

#ifndef DEBUG
# define DEBUG 0
#endif

class Base
{
	public:
		virtual ~Base(void);

		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);

	class NotFoundBaseTypeException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class NotCorrectBaseTypeException : public std::exception
	{
		public:
			const char *what() const throw();
	};
		
	class NotGeneratedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
