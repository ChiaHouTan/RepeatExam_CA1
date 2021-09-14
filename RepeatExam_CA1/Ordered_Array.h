#pragma once
#include <iostream>

using namespace std;

template<class T>
class Ordered_Array
{
private:
	T* arr;
	int capacity;
	int topNum;


public:
     //Constructors
	Ordered_Array();
	Ordered_Array(int);
	~Ordered_Array();

	void push(const T& newElement);
	int length();
	T getElement(int index);
	bool remove(int index);
	int search(const T& target);
	void clear();


};	 