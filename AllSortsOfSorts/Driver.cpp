/*************************************************************
*
* Lab / Assignment: Lab2 - All sorts of sorts
*
* Overview:
*		This program will ask the user for how many elements they
*		would like to sort through. It will then go through the
*		following sorts for each C Arrays, Vectors, and my 
*		Templated Array: Brute Force Bubble, Flagged Bubble, Selection, 
*		Insertion, Shell, Heap, Merge (recursive), and Quick (recursive).
*		The times taken for each sort are output to the console and 
*		the file "sort_results.txt" as well as every 1000th element
*		is output to the file to check if successful.
*
* Input:
*		In the initial menu, the user must enter some integer of
*		how much data elements they would like the sorts to use.
*		Also, the program accepts an integer from the console
*		of how many data elements to use.
*
* Output:
*		The program will output the container type, name, and time it took for
*		each sort, and also output the same to a file as well as
*		every 1000th element in the sorted array to easily check if
*		it was successful.
*
**************************************************************/

/*************************************************************
* Author: Dillon Wall
* Filename: Driver.cpp
* Date Created: 1/22/2019
* Modifications:
**************************************************************/

#include "Random.h"
#include "Sort.h"
#include "Array.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios;

typedef void(*CArrayFunctionPointer)(int*, int);  // Define a funtion pointer type
typedef void(*VectorFunctionPointer)(vector<int>*, int);  // Define a funtion pointer type
typedef void(*TArrayFunctionPointer)(Array<int>*, int);  // Define a funtion pointer type

CArrayFunctionPointer cArraySortFunctions[] = {
	Sort<int>::BFBubble, Sort<int>::FlagBubble, Sort<int>::Selection, Sort<int>::Insertion,
	Sort<int>::Shell, Sort<int>::Heap, Sort<int>::Merge, Sort<int>::Quick
};

VectorFunctionPointer vectorSortFunctions[] = {
	Sort<int>::BFBubble, Sort<int>::FlagBubble, Sort<int>::Selection, Sort<int>::Insertion,
	Sort<int>::Shell, Sort<int>::Heap, Sort<int>::Merge, Sort<int>::Quick
};

TArrayFunctionPointer tArraySortFunctions[] = {
	Sort<int>::BFBubble, Sort<int>::FlagBubble, Sort<int>::Selection, Sort<int>::Insertion,
	Sort<int>::Shell, Sort<int>::Heap, Sort<int>::Merge, Sort<int>::Quick
};

const char* funcNames[] = {
	"Brute Force Bubble", "Flag Bubble", "Selection", "Insertion", "Shell", "Heap", "Merge", "Quick"
};

const char* FILE_NAME = "sort_results.txt";

int main(int argc, char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Random::Init();

	int n = 0;
	if (argc != 2)
	{
		cout << "Please enter an integer number of how many elements to sort..." << endl;
		cin >> n;
	}
	else
	{
		n = atoi(argv[1]);
	}

	if (n <= 1)
	{
		cout << "Incorrect input (n was <= 1), terminating program" << endl;
		exit(1);
	}

	///--------------GENERATE-DATA--------------///
	//Initialize data containers
	int* cArrData = new int[n];
	vector<int>* vectData = new vector<int>();
	vectData->reserve(n);
	Array<int>* tArrData = new Array<int>(n);

	//create random data
	for (int i = 0; i < n; ++i)
	{
		int r = Random::GetRand();
		cArrData[i] = r;
		vectData->push_back(r);
		(*tArrData)[i] = r;
	}

	//make backup
	int* cArrBackup = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cArrBackup[i] = cArrData[i];
	}
	vector<int>* vectBackup = new vector<int>(*vectData);
	Array<int>* tArrBackup = new Array<int>(*tArrData);

	//reset file to write to
	ofstream oldFile(FILE_NAME, ios::out | ios::trunc);
	oldFile.close();

	///--------------C-ARRAYS--------------///

	//iterate through sort functions
	int i = 0;
	for (CArrayFunctionPointer func : cArraySortFunctions)
	{
		//perform console tasks
		cout << "-----------------[C Array]-----------------" << endl;
		cout << "Calling function: " << funcNames[i] << endl;

		clock_t startTime;
		clock_t endTime;
		startTime = clock(); //set timer to current time
		func(cArrData, n);
		endTime = clock(); //set timer to current time
		double milliSeconds = (endTime - startTime) / (CLOCKS_PER_SEC / 1000); //difference between now and before
		cout << "It took " << milliSeconds << "ms" << endl;

		//write to file
		ofstream myFile(FILE_NAME, ios::out | ios::app | ios::ate);
		if (myFile.is_open())
		{
			myFile << "-------------[C Array]-------------" << endl;
			myFile << "Function: " << funcNames[i] << endl;
			myFile << "Took " << milliSeconds << "ms" << endl;
			myFile << "---------------DATA----------------" << endl;
			for (int j = 0; j < n; j += 1000)
			{
				myFile << cArrData[j] << endl;
			}
			myFile.close();
		}
		else
		{
			cout << "UNABLE TO OPEN FILE: " << FILE_NAME << endl;
		}

		for (int j = 0; j < n; ++j)
		{
			cArrData[j] = cArrBackup[j];
		}
		++i;
	}

	///--------------VECTORS--------------///

	//iterate through sort functions
	i = 0;
	for (VectorFunctionPointer func : vectorSortFunctions)
	{
		//perform console tasks
		cout << "-----------------[Vector]-----------------" << endl;
		cout << "Calling function: " << funcNames[i] << endl;

		clock_t startTime; 
		clock_t endTime;
		startTime = clock(); //set timer to current time
		func(vectData, n);
		endTime = clock(); //set timer to current time
		double milliSeconds = (endTime - startTime) / (CLOCKS_PER_SEC / 1000); //difference between now and before
		cout << "It took " << milliSeconds << "ms" << endl;

		//write to file
		ofstream myFile(FILE_NAME, ios::out | ios::app | ios::ate);
		if (myFile.is_open())
		{
			myFile << "-------------[Vector]-------------" << endl;
			myFile << "Function: " << funcNames[i] << endl;
			myFile << "Took " << milliSeconds << "ms" << endl;
			myFile << "---------------DATA----------------" << endl;
			for (int j = 0; j < n; j += 1000)
			{
				myFile << vectData->at(j) << endl;
			}
			myFile.close();
		}
		else
		{
			cout << "UNABLE TO OPEN FILE: " << FILE_NAME << endl;
		}

		*vectData = *vectBackup; //reset data
		++i;
	}

	///--------------TEMPLATED-ARRAYS--------------///

		//iterate through sort functions
	i = 0;
	for (TArrayFunctionPointer func : tArraySortFunctions)
	{
		//perform console tasks
		cout << "-----------------[Template Array]-----------------" << endl;
		cout << "Calling function: " << funcNames[i] << endl;

		clock_t startTime;
		clock_t endTime;
		startTime = clock(); //set timer to current time
		func(tArrData, n);
		endTime = clock(); //set timer to current time
		double milliSeconds = (endTime - startTime) / (CLOCKS_PER_SEC / 1000); //difference between now and before
		cout << "It took " << milliSeconds << "ms" << endl;

		//write to file
		ofstream myFile(FILE_NAME, ios::out | ios::app | ios::ate);
		if (myFile.is_open())
		{
			myFile << "----------[Template Array]----------" << endl;
			myFile << "Function: " << funcNames[i] << endl;
			myFile << "Took " << milliSeconds << "ms" << endl;
			myFile << "---------------DATA----------------" << endl;
			for (int j = 0; j < n; j += 1000)
			{
				myFile << (*tArrData)[j] << endl;
			}
			myFile.close();
		}
		else
		{
			cout << "UNABLE TO OPEN FILE: " << FILE_NAME << endl;
		}

		*tArrData = *tArrBackup;
		++i;
	}

	///--------------CLEAN-UP--------------///

	delete cArrData;
	delete cArrBackup;
	delete vectData;
	delete vectBackup;
	delete tArrData;
	delete tArrBackup;

	return 0;
}