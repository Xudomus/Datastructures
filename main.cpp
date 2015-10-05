#include "array.h"
#include <iostream>

using namespace std;

void runArrayTests(Array<int> arr)
{
	//Test Set/Get functions
	cout << "Length: " << arr.getLength() << endl
		<< "Start Index: " << arr.getStartIndex() << endl
		<< "Set new Length to 7"; arr.setLength(7); cout << endl
		<< "New Length: " << arr.getLength() << endl
		<< "Set Start Index to 5"; arr.setStartIndex(5); cout << endl
		<< "New Start Index: " << arr.getStartIndex() << endl << endl;
	
	//Print array contents
	cout << "Array contents: " << endl;
	for (int i = 0; i < arr.getLength(); i++)
	{
		cout << "Array[" << i << "]: " << arr[i] << endl;
	}
	cout << endl;
}

int main()
{
	try{
		Array<int> noParameters();   // Constructor
		Array<int> lengthTest(20);      // lower bound 0, upper bound 20
		Array<int> assignmentTest(10);

		for (int i = 0; i < lengthTest.getLength(); i++)
		{
			lengthTest[i] = i * 5;
		}
		lengthTest.runArrayTests();
		for (int i = 0; i < assignmentTest.getLength(); i++)
		{
			assignmentTest[i] = i * 10;
		}
		assignmentTest.runArrayTests();
		assignmentTest = lengthTest;
		assignmentTest.runArrayTests();

		exit(EXIT_SUCCESS);
	}
	catch (Exception except)
	{
		cout << except;
		/*if (except == ERR_BAD_LENGTH)
		{
			cout << "ERR_BAD_BOUNDS" << endl;
			exit(EXIT_FAILURE);
		}
		if (except == ERR_MEM_ALLOC)
		{
			cout << "ERR_MEM_ALLOC" << endl;
			exit(EXIT_FAILURE);
		}
		if (except == ERR_OUT_OF_BOUNDS)
		{
		    cout << "ERR_OUT_OF_BOUNDS" << endl;
			exit(EXIT_FAILURE);
		}
		if (except == ERR_MEM_DEALLOC)
		{
			cout << "ERR_MEM_DEALLOC" << endl;
			exit(EXIT_FAILURE);
		}
		else{ cout << "Don't know what happened! Terminated!" << endl; };
		*/
	}
}