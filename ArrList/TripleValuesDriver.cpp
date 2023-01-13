//****************************************************************************************************
//
//      File:                TripleValuesDriver.cpp
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #1 part 2
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 August 31, 2020
//
//
//      This program creates objects with three member variables of the same data
//		types and then appleis different funtions on it. Such as summing up the
//		values or returning which value is the lowest one.
//
//      Other files required:
//		    1.    TripleValues.h    -    definition of the ThreeValues class
//
//****************************************************************************************************

#include <iostream>
#include "TripleValues.h"

using namespace::std;

//****************************************************************************************************

template <typename T>
void display(ThreeValues <T> &obj);

//****************************************************************************************************

int main()
{
	ThreeValues <int> intObj;
	ThreeValues <double> doubleObj(5.4, 4.3, 9.6);
	ThreeValues <char> charObj('a', 'b', 'c');
	ThreeValues <long long> unLongObj(56692467, 35893094, 90256734);

	display(intObj);
	display(doubleObj);
	display(charObj);
	display(unLongObj);

}

//****************************************************************************************************

template <typename T>
void display(ThreeValues <T> &obj) 
{
	T temp1,
		temp2,
		temp3;

	obj.getAll(temp1, temp2, temp3);

	cout << "----------------------------------------------------------------------------------------------------" << endl;

	cout << "Initially, the three values are initialized as: " << temp1 << " " << temp2 << " " << temp3 << endl;

	cout << "Now please enter three " << typeid(T).name() << ": ";
	cin >> temp1 >> temp2 >> temp3;
	obj.setFirst(temp1);
	obj.setSecond(temp2);
	obj.setThird(temp3);

	obj.getAll(temp1, temp2, temp3);

	cout << "After modification, the three values are: " << temp1 << " " << temp2 << " " << temp3 << endl;

	cout << "The sum is: " << obj.calcSum() << endl;

	cout << "The minimum value is: " << obj.getMin() << endl;
}


/*
----------------------------------------------------------------------------------------------------
Initially, the three values are initialized as: 0 0 0
Now please enter three int: 5
7
3
After modification, the three values are: 5 7 3
The sum is: 15
The minimum value is: 3
----------------------------------------------------------------------------------------------------
Initially, the three values are initialized as: 5.4 4.3 9.6
Now please enter three double: 2.73
3.14
5.62
After modification, the three values are: 2.73 3.14 5.62
The sum is: 11.49
The minimum value is: 2.73
----------------------------------------------------------------------------------------------------
Initially, the three values are initialized as: a b c
Now please enter three char: x
y
a
After modification, the three values are: x y a
The sum is: R
The minimum value is: a
----------------------------------------------------------------------------------------------------
Initially, the three values are initialized as: 56692467 23893094 90256734
Now please enter three __int64: 34
12
68
After modification, the three values are: 34 12 68
The sum is: 114
The minimum value is: 12
*/
