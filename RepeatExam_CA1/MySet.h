#pragma 
#include "Ordered_Array.h"
template<class T>
class MySet
{
	T MySet::operator &(const T& other)
	{
		return this->value & other.value;
	}

	T MySet::operator |(const T& other)
	{
		return this->value | other.value;
	}
};

