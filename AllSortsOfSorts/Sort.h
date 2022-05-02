/*************************************************************
* Author: Dillon Wall
* Filename: Sort.h
* Date Created: 1/22/2019
* Modifications:
**************************************************************/

#pragma once

#define DEBUG true

#include <vector>
#include "Array.h"
using std::vector;

#if DEBUG == true
#include <iostream>
using std::cout;
using std::endl;
#endif

/************************************************************************
* Class: Sort
*
* Purpose: This templated class has static functions that sort data (based
*			on their comparison operators) with	various sorting methods
*
* Manager functions:
*
* Methods:
* static void Swap(<T* || vector<T>* || Array<T>> data, int first, int second)
*		Swaps 2 elements from the data array at indexes first and second
* static void BFBubble(<T* || vector<T>* || Array<T>> data, int size)
*		Performs a brute force bubble sort on the data
* static void FlagBubble(<T* || vector<T>* || Array<T>> data, int size)
*		Performs a flagged bubble sort on the data
* static void Selection(<T* || vector<T>* || Array<T>> data, int size)
*		Performs a selection sort on the data
* static void Insertion(<T* || vector<T>* || Array<T>> data, int size)
*		Performs an insertion sort on the data, with a sequence of 1
* static void Insertion(<T* || vector<T>* || Array<T>> data, int size, int sequence)
*		Helper function for the insertion and shell sort which can
*		take in how many sequences of a shell sort it may do 
*		(1 is default insertion sort as it takes the data in 1 "sequence")
* static void Shell(<T* || vector<T>* || Array<T>> data, int size)
*		Performs a shell sort on the data using the Insertion sequenced function
* static void Heap(<T* || vector<T>* || Array<T>> data, int size)
*		Performs a heap sort on the data
* static void Merge(<T* || vector<T>* || Array<T>> data, int size)
*		Helper function which initiates a merge sort on the data using the MergeSort recursive function
* static void MergeSort(<T* || vector<T>* || Array<T>> data, <T* || vector<T>* || Array<T>> temp, int left, int right)
*		Recursively splits the data and merges it back together with the MergeHalves function
* static void MergeHalves(<T* || vector<T>* || Array<T>> data, <T* || vector<T>* || Array<T>> temp, int left, int right, int rightEnd)
*		Takes two sub arrays and merges them
* static void Quick(<T* || vector<T>* || Array<T>> data, int size)
*		Helper function which prepares and initiates a quick sort on the data 
*		using the Quick 3 arg recursive function
* static void Quick(<T* || vector<T>* || Array<T>> data, int first, int last)
*		Recursively preforms a quick sort using a pivot and splitting the array into subarray
*		
*
*************************************************************************/
template <typename T>
class Sort
{
public:

	//C Arrays
	static void Swap(T* data, int first, int second);
	static void BFBubble(T* data, int size);
	static void FlagBubble(T* data, int size);
	static void Selection(T* data, int size);
	static void Insertion(T* data, int size);
	static void Insertion(T* data, int size, int sequence);
	static void Shell(T* data, int size);
	static void Heap(T* data, int size);
	static void Heapify(T* data, int size, int node);
	static void Merge(T* data, int size);
	static void MergeSort(T* data, T* temp, int left, int right);
	static void MergeHalves(T* data, T* temp, int left, int right, int rightEnd);
	static void Quick(T* data, int size);
	static void Quick(T* data, int first, int last);

	//Vectors
	static void Swap(vector<T>* data, int first, int second);
	static void BFBubble(vector<T>* data, int size);
	static void FlagBubble(vector<T>* data, int size);
	static void Selection(vector<T>* data, int size);
	static void Insertion(vector<T>* data, int size);
	static void Insertion(vector<T>* data, int size, int sequence);
	static void Shell(vector<T>* data, int size);
	static void Heap(vector<T>* data, int size);
	static void Heapify(vector<T>* data, int size, int node);
	static void Merge(vector<T>* data, int size);
	static void MergeSort(vector<T>* data, vector<T>* temp, int left, int right);
	static void MergeHalves(vector<T>* data, vector<T>* temp, int left, int right, int rightEnd);
	static void Quick(vector<T>* data, int size);
	static void Quick(vector<T>* data, int first, int last);

	//Array template
	static void Swap(Array<T>* data, int first, int second);
	static void BFBubble(Array<T>* data, int size);
	static void FlagBubble(Array<T>* data, int size);
	static void Selection(Array<T>* data, int size);
	static void Insertion(Array<T>* data, int size);
	static void Insertion(Array<T>* data, int size, int sequence);
	static void Shell(Array<T>* data, int size);
	static void Heap(Array<T>* data, int size);
	static void Heapify(Array<T>* data, int size, int node);
	static void Merge(Array<T>* data, int size);
	static void MergeSort(Array<T>* data, Array<T>* temp, int left, int right);
	static void MergeHalves(Array<T>* data, Array<T>* temp, int left, int right, int rightEnd);
	static void Quick(Array<T>* data, int size);
	static void Quick(Array<T>* data, int first, int last);

};

/// C ARRAYS ///

template<typename T>
inline void Sort<T>::Swap(T* data, int first, int second)
{
	T temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}

template<typename T>
inline void Sort<T>::BFBubble(T* data, int size)
{
	//CODE HERE
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (data[j + 1] < data[j])
				Swap(data, j, j + 1);
		}
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::FlagBubble(T* data, int size)
{
	//CODE HERE
	bool eFlag = false;
	for (int i = 0; !eFlag && i < size - 1; ++i)
	{
		eFlag = true;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (data[j] > data[j + 1])
			{
				eFlag = false;
				Swap(data, j, j + 1);
			}
		}
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Selection(T* data, int size)
{
	//CODE HERE
	//iterate and maintain max value, then swap
	int max = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		max = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (data[max] < data[j])
				max = j;
		}
		Swap(data, max, size - i - 1);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Insertion(T* data, int size)
{
	//CODE HERE
	//iterate, shift right until end or is correct spot
	for (int i = 1; i < size; ++i)
	{
		T temp = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > temp)
		{
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = temp;
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Insertion(T* data, int size, int sequence)
{
	//CODE HERE
	for (int seq = 0; seq < sequence; ++seq)
	{
		for (int i = seq; i < size; i += sequence)
		{
			T temp = data[i];
			int j = i - sequence;
			while (j >= seq && data[j] > temp)
			{
				data[j + sequence] = data[j];
				j -= sequence;
			}
			data[j + sequence] = temp;
		}
	}
}

template<typename T>
inline void Sort<T>::Shell(T* data, int size)
{
	for (int sequence = (size - 1) / 3; sequence >= 1; sequence = ceil((sequence - 1.0) / 3))
	{
		Insertion(data, size, sequence);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Heap(T* data, int size)
{
	//CODE HERE
	//heapify n/2 -1 to 0, then iteratively pop top and heapify top
	for (int i = (size / 2) + 1; i >= 0; --i)
		Heapify(data, size, i);

	for (int i = 0; i < size - 1; ++i)
	{
		Swap(data, 0, size - i - 1);
		Heapify(data, size - i - 1, 0);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Heapify(T* data, int size, int node)
{
	//CODE HERE
	int first = node;

	while (first < size)
	{
		int largest = first * 2 + 1;
		int last = first * 2 + 2;
		if (last < size && data[last] > data[largest])
			largest = last;
		if (largest < size && data[largest] > data[first])
		{
			Swap(data, first, largest);
			first = largest;
		}
		else
			first = size;
	}
}

template<typename T>
inline void Sort<T>::Merge(T* data, int size)
{
	T* temp = new T[size];

	//CODE HERE
	MergeSort(data, temp, 0, size - 1);

	delete temp;

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::MergeSort(T* data, T* temp, int left, int right)
{
	//CODE HERE
	if (left < right)
	{
		int mid = (right + left) / 2;

		MergeSort(data, temp, left, mid);
		MergeSort(data, temp, mid + 1, right);
		MergeHalves(data, temp, left, mid + 1, right);
	}
}

template<typename T>
inline void Sort<T>::MergeHalves(T* data, T* temp, int left, int right, int rightEnd)
{
	//CODE HERE
	int origLeft = left;
	int tempPos = left;
	int leftEnd = right - 1;

	while (left <= leftEnd && right <= rightEnd)
	{
		if (data[left] <= data[right])
		{
			temp[tempPos] = data[left];
			++left;
		}
		else
		{
			temp[tempPos] = data[right];
			++right;
		}
		++tempPos;
	}

	for (int i = left; i <= leftEnd; ++i)
	{
		temp[tempPos] = data[i];
		++tempPos;
	}

	for (int i = right; i <= rightEnd; ++i)
	{
		temp[tempPos] = data[i];
		++tempPos;
	}

	for (int i = origLeft; i <= rightEnd; ++i)
		data[i] = temp[i];
}

template<typename T>
inline void Sort<T>::Quick(T* data, int size)
{
	//CODE HERE
	//swap largest to end, perform quick on the rest
	int largest = 0;
	for (int i = 1; i < size; ++i)
	{
		if (data[i] > data[largest])
			largest = i;
	}
	Swap(data, largest, size - 1);

	Quick(data, 0, size - 2);


#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data[i] < data[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Quick(T* data, int first, int last)
{
	//CODE HERE
	T pivot = data[first];
	int small = first + 1;
	int large = last;
	while (small <= large)
	{
		while (data[small] < pivot)
			++small;
		while (data[large] > pivot)
			--large;
		if (small < large)
			Swap(data, small++, large--);
		else
			++small;
	}
	Swap(data, large, first);
	if (first < large - 1)
		Quick(data, first, large - 1);
	if (last > large + 1)
		Quick(data, large + 1, last);
}

/// VECTORS ///

template<typename T>
inline void Sort<T>::Swap(vector<T>* data, int first, int second)
{
	T temp = data->at(first);
	data->at(first) = data->at(second);
	data->at(second) = temp;
}

template<typename T>
inline void Sort<T>::BFBubble(vector<T>* data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (data->at(j) > data->at(j + 1))
				Swap(data, j, j + 1);
		}
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i-1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::FlagBubble(vector<T>* data, int size)
{
	bool flag = false;
	for (int i = 0; i < size && !flag; ++i)
	{
		flag = true;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (data->at(j) > data->at(j + 1))
			{
				Swap(data, j, j + 1);
				flag = false;
			}
		}
	}

#if DEBUG == true
	flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Selection(vector<T>* data, int size)
{
	int max = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size - i; ++j)
		{
			if (data->at(j) > data->at(max))
			{
				max = j;
			}
		}
		Swap(data, max, size - i - 1);

		max = 0;
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Insertion(vector<T>* data, int size)
{
	Insertion(data, size, 1);

	//for (int i = 1; i < size; ++i)
	//{
	//	T temp = data->at(i);
	//	int j = i - 1;
	//	while (j >= 0 && data->at(j) > temp)
	//	{
	//		data->at(j + 1) = data->at(j);
	//		--j;
	//	}
	//	data->at(j + 1) = temp;
	//}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Insertion(vector<T>* data, int size, int sequence)
{
	for (int seq = 0; seq < sequence; ++seq)
	{
		for (int i = seq+sequence; i < size; i += sequence)
		{
			T temp = data->at(i);
			int j = i - sequence;
			while (j >= seq && data->at(j) > temp)
			{
				data->at(j + sequence) = data->at(j);
				j-=sequence;
			}
			data->at(j + sequence) = temp;
		}
	}
}

template<typename T>
inline void Sort<T>::Shell(vector<T>* data, int size)
{
	for (int sequence = (size - 1) / 3; sequence >= 1; sequence = ceil((sequence - 1.0) / 3))
	{
		Insertion(data, size, sequence);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Heap(vector<T>* data, int size)
{
	//Build Max heap
	for (int i = (size / 2) - 1; i >= 0; --i)
	{
		Heapify(data, size, i);
	}

	//Extract top of heap and fix heap
	for (int i = 1; i < size; ++i)
	{
		//swap top of heap to end
		Swap(data, 0, size - i);

		Heapify(data, size - i, 0);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Heapify(vector<T>* data, int size, int node)
{
	int first = node;

	//Heapify
	while (first < size)
	{
		int largest = (first * 2) + 1;
		int last = (first * 2) + 2;
		if (last < size && data->at(last) > data->at(largest))
			largest = last;
		if (largest < size && data->at(largest) > data->at(first))
		{
			Swap(data, first, largest);
			first = largest;
		}
		else //we no longer need to go deeper
		{
			first = size; //exits while
		}
	}
}

template<typename T>
inline void Sort<T>::Merge(vector<T>* data, int size)
{
	vector<T>* temp = new vector<T>(size);
	temp->reserve(size);

	MergeSort(data, temp, 0, size - 1);

	delete temp;

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::MergeSort(vector<T>* data, vector<T>* temp, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(data, temp, left, mid);
		MergeSort(data, temp, mid + 1, right);
		MergeHalves(data, temp, left, mid + 1, right);
	}
}

template<typename T>
inline void Sort<T>::MergeHalves(vector<T>* data, vector<T>* temp, int left, int right, int rightEnd)
{
	int leftStart = left;
	int leftEnd = right - 1;
	int tempPos = left;
	int numElements = rightEnd - left + 1;

	while (left <= leftEnd && right <= rightEnd)
	{
		if (data->at(left) <= data->at(right))
		{
			temp->at(tempPos) = data->at(left);
			++left;
		}
		else
		{
			temp->at(tempPos) = data->at(right);
			++right;
		}
		++tempPos;
	}
	for (int i = left; i <= leftEnd; ++i)
	{
		temp->at(tempPos) = data->at(i);
		++tempPos;
	}
	for (int i = right; i <= rightEnd; ++i)
	{
		temp->at(tempPos) = data->at(i);
		++tempPos;
	}

	for (int i = leftStart; i <= rightEnd; ++i)
		data->at(i) = temp->at(i);
}

template<typename T>
inline void Sort<T>::Quick(vector<T>* data, int size)
{
	if (size >= 2)
	{
		//Find largest # and swap to end
		int largest = 0;
		for (int i = 1; i < size; ++i)
		{
			if (data->at(largest) < data->at(i))
				largest = i;
		}
		Swap(data, largest, size - 1);

		Quick(data, 0, size - 2);
	}


#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && data->at(i) < data->at(i - 1))
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Quick(vector<T>* data, int first, int last)
{
	T pivot = data->at(first);
	int small = first + 1;
	int large = last;
	while (small <= large)
	{
		while (data->at(small) < pivot)
			++small;
		while (data->at(large) > pivot)
			--large;
		if (small < large)
			Swap(data, small++, large--);
		else
			++small;
	}
	Swap(data, large, first);
	if (first < large - 1)
		Quick(data, first, large - 1);
	if (last > large + 1)
		Quick(data, large + 1, last);
}

/// ARRAY CLASS ///

template<typename T>
inline void Sort<T>::Swap(Array<T>* data, int first, int second)
{
	T temp = (*data)[first];
	(*data)[first] = (*data)[second];
	(*data)[second] = temp;
}

template<typename T>
inline void Sort<T>::BFBubble(Array<T>* data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if ((*data)[j] > (*data)[j + 1])
				Swap(data, j, j + 1);
		}
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::FlagBubble(Array<T>* data, int size)
{
	bool flag = false;
	for (int i = 0; i < size && !flag; ++i)
	{
		flag = true;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if ((*data)[j] > (*data)[j + 1])
			{
				Swap(data, j, j + 1);
				flag = false;
			}
		}
	}

#if DEBUG == true
	flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Selection(Array<T>* data, int size)
{
	int max = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size - i; ++j)
		{
			if ((*data)[j] > (*data)[max])
			{
				max = j;
			}
		}
		Swap(data, max, size - i - 1);

		max = 0;
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Insertion(Array<T>* data, int size)
{
	Insertion(data, size, 1);

	//for (int i = 1; i < size; ++i)
	//{
	//	T temp = (*data)[i];
	//	int j = i - 1;
	//	while (j >= 0 && (*data)[j] > temp)
	//	{
	//		(*data)[j + 1] = (*data)[j];
	//		--j;
	//	}
	//	(*data)[j + 1] = temp;
	//}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Insertion(Array<T>* data, int size, int sequence)
{
	for (int seq = 0; seq < sequence; ++seq)
	{
		for (int i = seq + sequence; i < size; i += sequence)
		{
			T temp = (*data)[i];
			int j = i - sequence;
			while (j >= seq && (*data)[j] > temp)
			{
				(*data)[j + sequence] = (*data)[j];
				j -= sequence;
			}
			(*data)[j + sequence] = temp;
		}
	}
}

template<typename T>
inline void Sort<T>::Shell(Array<T>* data, int size)
{
	for (int sequence = (size - 1) / 3; sequence >= 1; sequence = ceil((sequence - 1.0) / 3))
	{
		Insertion(data, size, sequence);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Heap(Array<T>* data, int size)
{
	//Build Max heap
	for (int i = (size / 2) - 1; i >= 0; --i)
	{
		Heapify(data, size, i);
	}

	//Extract top of heap and fix heap
	for (int i = 1; i < size; ++i)
	{
		//swap top of heap to end
		Swap(data, 0, size - i);

		Heapify(data, size - i, 0);
	}

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Heapify(Array<T>* data, int size, int node)
{
	int first = node;

	//Heapify
	while (first < size)
	{
		int largest = (first * 2) + 1;
		int last = (first * 2) + 2;
		if (last < size && (*data)[last] > (*data)[largest])
			largest = last;
		if (largest < size && (*data)[largest] > (*data)[first])
		{
			Swap(data, first, largest);
			first = largest;
		}
		else //we no longer need to go deeper
		{
			first = size; //exits while
		}
	}
}

template<typename T>
inline void Sort<T>::Merge(Array<T>* data, int size)
{
	Array<T>* temp = new Array<T>(size);

	MergeSort(data, temp, 0, size - 1);

	delete temp;

#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::MergeSort(Array<T>* data, Array<T>* temp, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(data, temp, left, mid);
		MergeSort(data, temp, mid + 1, right);
		MergeHalves(data, temp, left, mid + 1, right);
	}
}

template<typename T>
inline void Sort<T>::MergeHalves(Array<T>* data, Array<T>* temp, int left, int right, int rightEnd)
{
	int leftStart = left;
	int leftEnd = right - 1;
	int tempPos = left;
	int numElements = rightEnd - left + 1;

	while (left <= leftEnd && right <= rightEnd)
	{
		if ((*data)[left] <= (*data)[right])
		{
			(*temp)[tempPos] = (*data)[left];
			++left;
		}
		else
		{
			(*temp)[tempPos] = (*data)[right];
			++right;
		}
		++tempPos;
	}
	for (int i = left; i <= leftEnd; ++i)
	{
		(*temp)[tempPos] = (*data)[i];
		++tempPos;
	}
	for (int i = right; i <= rightEnd; ++i)
	{
		(*temp)[tempPos] = (*data)[i];
		++tempPos;
	}

	for (int i = leftStart; i <= rightEnd; ++i)
		(*data)[i] = (*temp)[i];
}

template<typename T>
inline void Sort<T>::Quick(Array<T>* data, int size)
{
	if (size >= 2)
	{
		//Find largest # and swap to end
		int largest = 0;
		for (int i = 1; i < size; ++i)
		{
			if ((*data)[largest] < (*data)[i])
				largest = i;
		}
		Swap(data, largest, size - 1);

		Quick(data, 0, size - 2);
	}


#if DEBUG == true
	bool flag = false;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && (*data)[i] < (*data)[i - 1])
			flag = true;
	}
	cout << (flag ? "FAILED" : "WORKED") << endl;
#endif
}

template<typename T>
inline void Sort<T>::Quick(Array<T>* data, int first, int last)
{
	T pivot = (*data)[first];
	int small = first + 1;
	int large = last;
	while (small <= large)
	{
		while ((*data)[small] < pivot)
			++small;
		while ((*data)[large] > pivot)
			--large;
		if (small < large)
			Swap(data, small++, large--);
		else
			++small;
	}
	Swap(data, large, first);
	if (first < large - 1)
		Quick(data, first, large - 1);
	if (last > large + 1)
		Quick(data, large + 1, last);
}