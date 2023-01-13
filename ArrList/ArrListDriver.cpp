//****************************************************************************************************
//
//      File:                ArrListDriver.cpp
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
//		    1.    TrrList.h - the member functions and class declarations of ArrList
//
//****************************************************************************************************

#include <iostream>
#include <new>
#include <string>
#include "ArrList.h"

//****************************************************************************************************

using namespace::std;

//****************************************************************************************************

int main()
{
	ArrList<short> list(8);
	short temp;
	string output = "";
	
	cout << string(7, '=') << "Initially" << string(10, '=') << endl;
	cout << "Number of values in the list: " << list.getNumValues() << endl;
	cout << "Capacity: " << list.getCapacity() << endl;
	cout << "Is it empty? ";

	if (list.isEmpty()) 
	{
		cout << "yes" << endl;
	}
	else 
	{
		cout << "no" << endl;
	}


	cout << endl << string(7, '=') << "Inserting numbers 7, 8, 9, 2, 1, 6 to the list" << string(10, '=') << endl;
	cout << "Using insert back:" << endl;

	list.insertBack(7);
	list.insertBack(8);
	list.insertBack(9);
	list.insertBack(2);
	list.insertBack(1);
	list.insertBack(6);

	cout << "Capacity: " << list.getCapacity() << endl;
	cout << "And call the display function:" << endl;
	list.display(output);
	cout << output << endl;
	cout << "Inserting 4 to the front:" << endl;
	list.insertFront(4);
	cout << "Inserting 5 at index 2:" << endl;
	list.insertAtIndex(5, 2);
	cout << "And call the display function:" << endl;
	list.display(output);
	cout << output << endl;

	cout << endl << string(7, '=') << "Retrieves" << string(10, '=') << endl;
	list.retrieveFront(temp);
	cout << "The front value: " << temp << endl;
	list.retrieveBack(temp);
	cout << "The back value: " << temp << endl;
	list.retrieveAtIndex(3, temp);
	cout << "The value at index 3: " << temp << endl;
	list.getSmallest(temp);
	cout << "Smallest value: " << temp << endl;

	cout << endl << string(7, '=') << "Updates" << string(10, '=') << endl;
	cout << "Update first value as 100: " << endl;
	list.updateFront(100);
	list.display(output);
	cout << output << endl;
	cout << "Update last value as 50: " << endl;
	list.updateBack(50);
	list.display(output);
	cout << output << endl;
	cout << "Update location 2 as 15: " << endl;
	list.updateAtIndex(2, 15);
	list.display(output);
	cout << output << endl;

	cout << endl << string(7, '=') << "More inserts to test _resize() function" << string(10, '=') << endl;
	cout << "Inserting 4, 3, 1, 6, 3 using front insert:" << endl;
	list.insertFront(4);
	list.insertFront(3);
	list.insertFront(1);
	list.insertFront(6);
	list.insertFront(3);
	cout << "The new capacity of the list is: " << list.getCapacity() << endl;
	cout << "The new list is: " << endl;
	list.display(output);
	cout << output << endl;


	cout << endl << string(7, '=') << "Removes" << string(10, '=') << endl;
	list.removeFront(temp);
	cout << "Removing front and found the front value is: " << temp << endl;
	cout << "Now the new list of values are: " << endl;
	list.display(output);
	cout << output << endl;
	list.removeAtIndex(temp, 2);
	cout << "Removing at index 2 and found the value at it to be: " << temp << endl;
	cout << "Now the new list of values are: " << endl;
	list.display(output);
	cout << output << endl;
	list.removeValue(1, temp);
	cout << "Removing value 1: " << temp << endl;
	list.display(output);
	cout << output << endl;
	list.removeBack(temp);
	cout << "Removing back and found the value at it to be: " << temp << endl;
	cout << "Now the new list of values are: " << endl;
	list.display(output);
	cout << output << endl;

	cout << endl << string(7, '=') << "Finally" << string(10, '=') << endl;
	cout << "New capacity: " << list.getCapacity() << endl;
	cout << "New number of values " << list.getNumValues() << endl;
	cout << "Final list: " << endl;
	list.display(output);
	cout << output << endl;
	cout << "Clearing it out..." << endl;
	list.clearList();
	cout << "Is it empty? ";

	if (list.isEmpty()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}


}

//****************************************************************************************************

/*
=======Initially==========
Number of values in the list: 0
Capacity: 8
Is it empty? yes

=======Inserting numbers 7, 8, 9, 2, 1, 6 to the list==========
Using insert back:
Capacity: 8
And call the display function:
7 8 9 2 1 6
Inserting 4 to the front:
Inserting 5 at index 2:
And call the display function:
4 7 5 8 9 2 1 6

=======Retrieves==========
The front value: 4
The back value: 6
The value at index 3: 8
Smallest value: 1

=======Updates==========
Update first value as 100:
100 7 5 8 9 2 1 6
Update last value as 50:
100 7 5 8 9 2 1 50
Update location 2 as 15:
100 7 15 8 9 2 1 50

=======More inserts to test _resize() function==========
Inserting 4, 3, 1, 6, 3 using front insert:
The new capacity of the list is: 18
The new list is:
3 6 1 3 4 100 7 15 8 9 2 1 50

=======Removes==========
Removing front and found the front value is: 3
Now the new list of values are:
6 1 3 4 100 7 15 8 9 2 1 50
Removing at index 2 and found the value at it to be: 3
Now the new list of values are:
6 1 4 100 7 15 8 9 2 1 50
Removing back and found the value at it to be: 50
Now the new list of values are:
6 1 4 100 7 15 8 9 2 1

=======Finally==========
New capacity: 18
New number of values 10
Final list:
6 1 4 100 7 15 8 9 2 1
Clearing it out...
Is it empty? yes
*/