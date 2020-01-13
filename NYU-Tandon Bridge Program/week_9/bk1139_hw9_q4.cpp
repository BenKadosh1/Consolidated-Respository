//File name: bk1139_hw9_q4.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw9_q4

#include <iostream>

//define int* type to int_ptr
typedef int* int_ptr;


void oddsKeepEvensFlip(int arr[], int arrSize);
/*
  The oddsKeepEvensFlip function takes two arguments:
	1. An array, arr, which contains a sequence of integers
	2. An int, arrSize, which is the size of the array
  The oddsKeepEvensFlip function is a void function, and therefore does not have a return value

  The function's purpose is to reorder the sequence in the array such that odds come first and then evens in reversed order
*/

void printArray(int arr[], int arrSize);
/*
  The printArray function takes two arguments:
	1. An array, arr, which contains a sequence of integers
	2. An integer, arrSize, which is the size of the array
  The printArray function is a void function, and therefore does not have a return value.

  The function's purpose is to print the contents at each index of the array
*/

int main()
{
	using namespace std;

	//create 4 test arrays of integers
	int arr_1[6] = { 5,2,11,7,6,4 }, arr_2[6] = { 1,3,5,7,9,11 }, arr_3[6] = { 2,4,6,8,10,12 }, arr_4[8] = {12,16,1,3,5,4,7,80 };
	
	//declare and initialize the size of each test array
	int arr_1_size = 6, arr_2_size = 6, arr_3_size = 6, arr_4_size = 8;

	//output to the user how the results will be presented
	cout << "Below are the before and after results for 4 different arrays passed to the oddsKeepEvensFlip function:\n" << endl;

	//print array 1, then call oddsKeepEvensFlip and pass array 1 as an arguement, then print out array 1 again to show the change
	cout << "Array 1:" << endl;
	printArray(arr_1, arr_1_size);
	oddsKeepEvensFlip(arr_1, arr_1_size);
	printArray(arr_1, arr_1_size);
	cout << endl;

	//repeat for arrays 2, 3, 4
	cout << "Array 2:" << endl;
	printArray(arr_2, arr_2_size);
	oddsKeepEvensFlip(arr_2, arr_2_size);
	printArray(arr_2, arr_2_size);
	cout << endl;

	cout << "Array 3:" << endl;
	printArray(arr_3, arr_3_size);
	oddsKeepEvensFlip(arr_3, arr_3_size);
	printArray(arr_3, arr_3_size);
	cout << endl;

	cout << "Array 4:" << endl;
	printArray(arr_4, arr_4_size);
	oddsKeepEvensFlip(arr_4, arr_4_size);
	printArray(arr_4, arr_4_size);
	cout << endl;

	return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
	//declare and initialize variables to store the number of odd and even numbers in the array and index positions that will be used to reorder them
	int odd_count = 0, even_count = 0;
	int odd_index = 0, even_index = 0;

	//iterate through the array and determine the number of odd and even values
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_count++;
		}
		else
		{
			odd_count++;
		}
	}

	//create two int_ptrs that will point to dynamically created arrays to store the odd and even values in the original array
	int_ptr odds_array = new int[odd_count];
	int_ptr evens_array = new int[even_count];

	//iterate through the original array again and populate the odd and even values in each respective dynamic array in the order in which they appear
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] % 2 == 0)
		{
			evens_array[even_index] = arr[i];
			even_index++;
		}
		else
		{
			odds_array[odd_index] = arr[i];
			odd_index++;
		}
	}

	//lastly iterate through the array one more time
	//first look at the odds_array and set the first x positions in the original array to match the odds_array
	//Then set the remaining positions to the reverse order of the evens_array
	for (int i = 0; i < arrSize; i++)
	{
		if (i < odd_count)
		{
			arr[i] = odds_array[i];
		}
		else
		{
			arr[i] = evens_array[even_index - 1];
			even_index--;
		}
	}

	//free up the heap memory allocated to storing the dynamic arrays of odd and even values
	delete[] odds_array;
	delete[] evens_array;
}

void printArray(int arr[], int arrSize)
{
	using namespace std;
	int i;
	//iterate through the array and print the value at each index
	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
