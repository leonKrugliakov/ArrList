//****************************************************************************************************
//
//      File:                ArrList.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #2
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 September 7, 2020
//
//
//      This program creates a dynamic array of type short and then manipulates it in many
//		different ways. The program has the ability to display the array, update it,
//		remove items, add items and reset the array.
//
//      Other files required:
//		    1.    ArrListDriver.cpp - The main function.
//
//****************************************************************************************************

#ifndef ARRLIST_H
#define ARRLIST_H

//****************************************************************************************************

using namespace::std;

//****************************************************************************************************

template<class T>
class ArrList {
private:
	int capacity;
	int numValues;
	T *list;
	bool _resize();
public:
	ArrList(int c);
	~ArrList();
	void display(string& view) const;
	bool update(const T& input);
	bool updateFront(const T& input);
	bool updateBack(const  T& input);
	bool updateAtIndex(int index, const T& input);
	bool insertBack(const T& input);
	bool insertFront(const T& input);
	bool insertAtIndex(const T& input, int index);
	bool retrieveAtIndex(int index, T& data) const;
	bool retrieveFront(T& data) const;
	bool retrieveBack(T& data) const;
	bool retrieve(int& location, T arg) const;
	bool removeFront(T& val);
	bool removeBack(T& val);
	bool removeAtIndex(T& val, int index);
	bool removeValue(T val, T& data);
	int getCapacity() const;
	int getNumValues() const;
	bool getSmallest(T& data) const;
	void clearList();
	bool isEmpty() const;

};

//****************************************************************************************************

template <typename T>
ArrList<T>::ArrList(int c)
{
	capacity = c;
	numValues = 0;
	list = new T[capacity];
}

//****************************************************************************************************

template <typename T>
ArrList<T>::~ArrList() 
{
	delete[] list;
	list = nullptr;
	numValues = 0;
	capacity = 0;
}

//****************************************************************************************************

template <typename T>
void ArrList<T>::display(string& view) const 
{
	string temp = "";

	if (numValues > 0) 
	{
		for (int i = 0; i < numValues; i++) 
		{
			temp = temp + to_string(list[i]) + " ";
		}
	}

	view = temp;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::_resize() 
{
	bool successful = false;
	capacity = capacity + capacity / 2;
	T * newList = new (nothrow) T[capacity];

	if (newList != nullptr) 
	{

		for (int i = 0; i < numValues; i++) 
		{
			newList[i] = list[i];
		}

		delete[] list;
		list = newList;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::update(const T& input) 
{
	bool successful = false;

	if (numValues > 0)
	{
		for (int i = 0; !successful && i < numValues; i++) 
		{
			if (list[i] == input)
			{
				list[i] = input;
				successful = true;
			}
		}
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::updateFront(const T& input) 
{
	bool successful = false;

	if (numValues > 0) 
	{
		list[0] = input;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::updateBack(const T& input) 
{
	bool successful = false;

	if (numValues > 0) 
	{
		list[numValues - 1] = input;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::updateAtIndex(int index, const T& input) 
{
	bool successful = false;

	if (numValues > 0 && numValues > index) 
	{
		list[index] = input;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::insertBack(const T& input) 
{
	bool successful = true;

	if (numValues == capacity) 
	{
		successful = _resize();
	}

	if (successful == true) 
	{
		list[numValues] = input;
		numValues++;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::insertFront(const T& input) 
{
	bool successful = true;

	if (numValues == capacity) 
	{
		successful = _resize();
	}

	if (successful == true) {
		for (int i = numValues; i > 0; i--) 
		{
			list[i] = list[i - 1];
		}
		list[0] = input;
		numValues++;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::insertAtIndex(const T& input, int index)
{
	bool successful = false;

	if (index >= 0 && index < numValues) 
	{
		successful = true;

		if (numValues == capacity) 
		{
			successful = _resize();
		}

		if (successful == true) {
			for (int i = numValues; i > index; i--) 
			{
				list[i] = list[i - 1];
			}
			
			list[index] = input;
			numValues++;
		}
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::retrieveAtIndex(int index, T& data) const 
{
	bool successful = false;

	if (index >= 0 && index < numValues)
	{
		data = list[index];
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::retrieveFront(T& data) const 
{
	bool successful = false;

	if (numValues > 0) 
	{
		data = list[0];
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::retrieveBack(T& data) const 
{
	bool successful = false;

	if (numValues > 0) 
	{
		data = list[numValues - 1];
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::retrieve(int& location, T arg) const
{
	bool successful = false;

	if (numValues > 0) 
	{
		for (int i = 0; i < numValues; i++) 
		{
			if (list[i] == arg) {
				location = i;
				successful = true;
			}
		}
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::removeFront(T& val)
{
	bool successful = false;

	if(numValues > 0)
	{
		val = list[0];
		numValues--;

		for (int i = 0; i < numValues; i++)
		{
			list[i] = list[i + 1];
		}

		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::removeBack(T& val) 
{
	bool successful = false;

	if (numValues > 0) 
	{
		val = list[numValues - 1];
		numValues--;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::removeAtIndex(T& val, int index) 
{
	bool successful = false;

	if (index >= 0 && index < numValues)
	{
		val = list[index];
		numValues--;

		for (int i = index; i < numValues; i++) 
		{
			list[i] = list[i + 1];
		}

		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::removeValue(T val, T& data)
{
	bool successful = false;

	if (numValues > 0)
	{
		for (int i = 0; !successful && i < numValues; i++) 
		{
			if (list[i] == val) 
			{
				data = list[i];
				for (int j = i; j < numValues; j++) 
				{
					list[j] = list[j + 1];
				}
				successful = true;
			}
		}

		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
int ArrList<T>::getCapacity() const 
{
	return capacity;
}

//****************************************************************************************************

template <typename T>
int ArrList<T>::getNumValues() const 
{
	return numValues;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::getSmallest(T& data) const
{
	bool successful = false;
	
	if (numValues > 0) 
	{
		T smallest = list[0];

		for (int i = 0; i < numValues; i++)
		{
			if (list[i] < smallest) 
			{
				smallest = list[i];
			}
		}

		data = smallest;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename T>
void ArrList<T>::clearList() 
{
	capacity = 0;
	numValues = 0;
	list = nullptr;
}

//****************************************************************************************************

template <typename T>
bool ArrList<T>::isEmpty() const 
{
	bool empty = false;

	if (numValues == 0) 
	{
		empty = true;
	}

	return empty;
}

#endif
