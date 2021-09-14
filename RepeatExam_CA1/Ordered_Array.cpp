#include "Ordered_Array.h"
#include <iostream>


using namespace std;


//Constructors 
template <class T>
Ordered_Array<T>::Ordered_Array() {
	arr = new T;
	capacity = 0;
	topNum = 0;

}

template <class T>
Ordered_Array<T>::Ordered_Array(int grow_size) {
	arr = new T[grow_size];
    capacity = grow_size;
    topNum = 0;

}

template <class T>
Ordered_Array<T>::~Ordered_Array() {
    topNum = 0;
    capacity = 0;
	delete[] arr;
};
	

template <class T>

void Ordered_Array<T>::push(const T& newElement)
{
	if (topNum != capacity)
	{
		arr[topNum] = newElement;
		topNum++;
	}
	else {
		int newsize = capacity * 2;
		T* newarr= new T[newsize];
		
		for (int i = 0; i < topNum; ++i)   //to increase size when not enough capacity but did not work
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;

		arr[topNum] = newElement;
		topNum++;
	}

}

template <class T>
int Ordered_Array<T>::length() {
	return topNum;
}

template <class T>
T Ordered_Array<T>::getElement(int index)
{
	return arr[index];
}

template <class T>
bool Ordered_Array<T>::remove(int index) {

	for (int i = 0; i < topNum; i++)
	{
		if (i == index)
		{

			for (int i = index; i < topNum; i++)
			{
				arr[i] = arr[i + 1];
			}
			topNum--;
		   return true;
		}else {
			return false;
		}
	}
		
}

template <class T>
int Ordered_Array<T>::search(const T& target) {
	for (int i = 0; i < topNum; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
}

template <class T>
void Ordered_Array<T>::clear() {
	topNum = 0;
};
