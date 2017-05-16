#ifndef NULLEXPRESSIONEXCEPTION_H
#define NULLEXPRESSIONEXCEPTION_H

#include <exception>
#include <string>
#include <stdio.h>

namespace core
{
	class NullException: public std::exception
	{
	public:
		NullException(std::string _msg) : message(_msg) {};
		virtual ~NullException() {};

		virtual std::ostream& PrintOn(std::ostream&) const;

	private:
		std::string message;
	};

	std::ostream& NullException::PrintOn(std::ostream& os) const
	{
		return os << "NullException : " << message;
	}
}

#endif