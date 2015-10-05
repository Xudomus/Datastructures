#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

class Exception
{
public:
	Exception() : m_msg("Error, Exception Thrown!") { ; }
	Exception(char *msg) : m_msg(msg) { ; }
	Exception(const Exception &copy) : m_msg(copy.m_msg) { ; }
	~Exception() { delete m_msg; }
	Exception &operator=(const Exception &rhs) 
	{
		if (this != &rhs) 
		{
			delete[] m_msg;
			m_msg = rhs.m_msg;
		}
	}
	const char* getMessage() { return m_msg; }
	void setMessage(char *msg) { m_msg = msg; }
	friend std::ostream &operator<<(std::ostream &stream, const Exception &except)
	{
		stream << "Exception thrown with the message: " << except.m_msg << std::endl;
		return stream;
	}
private:
	char *m_msg;
};
#endif

