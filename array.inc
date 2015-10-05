#ifndef ARRAY_I
#define ARRAY_I

#include <stdlib.h>
#include "array.h"
#include "exception.h"

template<class ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array() : m_array(new  ELEMENT_TYPE[0]()),
m_length(0), m_start_index(0)
{
	if (!m_array)
	{
		throw Exception("Memory Allocation Failed!");
	}

	if (m_length < 0)
	{
		throw Exception("Array length cannot be less than 0!");
	}
}

template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(int length, int start_index = 0) : m_array(new  ELEMENT_TYPE[length]()),
m_length(length), m_start_index(start_index)
{
	if (!m_array)
	{
		throw Exception("Memory Allocation Failed!");
	}

	if (m_length < 0)
	{
		throw Exception("Array length cannot be less than 0!");
	}
}

template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(const Array &copy){ ; }

template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::~Array()
{
	delete [] m_array;
	if (m_array)
	{
		throw Exception("Memory Deallocation Failed!");
	}
}

template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE> &Array<ELEMENT_TYPE>::operator=(const Array &rhs)
{
	if (this != &rhs){
		delete[] m_array;
		m_array = new ELEMENT_TYPE[rhs.m_length];
		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
	}
	return  *this;
}

template<class  ELEMENT_TYPE>
ELEMENT_TYPE &Array<ELEMENT_TYPE>::operator[](int index)  const
{
	if (index  <  m_start_index ||
		realIndex(index)  >  m_length)
	{
		throw Exception("Attempted Access Out of Bounds!");
	}
	return  m_array[realIndex(index)];
}

#endif