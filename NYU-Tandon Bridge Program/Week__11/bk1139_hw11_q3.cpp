//File name: bk1139_hw11_q3.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw11_q3

#include <iostream>

using namespace std;

int minInArray1(int arr[], int arrSize);
/*
  The minInArray1 function takes two arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, arrSize, which stores the size of the array being passed with the sequence of integers
  The minInArray1 function returns an integer which is the min value in the sequence

  The function's purpose is to find through recursion the minimum value in a sequence of integers in an array
*/

int minInArray2(int arr[], int low, int high);
/*
  The minInArray2 function takes three arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, low, which stores the lower bound of the range of indices
	3. An int, high, which stores the higher bound of the range of indices
  The minInArray2 function returns an integer which is the min value in the sequence

  The function's purpose is to find through recursion the minimum value in a sequence of integers in an array
*/

int main() {
	
	//main program to match the hw prompt
	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res3, res4;
	res1 = minInArray1(arr, 10);
	res2 = minInArray2(arr, 0, 9);
	cout << res1 << " " << res2 << endl; //should both be -9
	res3 = minInArray2(arr, 2, 5);
	res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
	cout << res3 << " " << res4 << endl; //should both be 3

	return 0;

}

int minInArray1(int arr[], int arrSize)
{
	int return_min_val;

	//define the base case as one and return the value at index 0
	if (arrSize == 1)
	{
		return arr[0];
	}
	else
	{
		//if the array is larger than 1 pass a smaller subset of the array to minInArray1
		return_min_val = minInArray1(arr + 1, arrSize - 1);
		
		//once the return_min_val is defined compare it to the value at index 0 to determine the min value
		if (arr[0] <= return_min_val)
		{
			return arr[0];
		}
		else
		{
			return return_min_val;
		}
	}
}

int minInArray2(int arr[], int low, int high)
{
	//calculate the logical size of the array based on high and low
	int arr_size = high - low + 1;

	//define the base case as one and return the value at index 0 = low
	if (arr_size == 1)
	{
		return arr[low];
	}
	else
	{
		//otherwise, if the array is larger than 1 pass a smaller subset of the array to minInArray2
		//initialize int variables for the array range and the ending index, and an int ptr to the new beginning address of the smaller array
		int arr_range = high - low;
		int* new_beg_index = arr + low + 1;
		int new_end_index = arr_range - 1;
		int return_min_val;

		//once the return_min_val is defined compare it to the value at index 0 = low to determine the min value
		return_min_val = minInArray2(new_beg_index, 0, new_end_index);
		if (arr[low] <= return_min_val)
		{
			return arr[low];
		}
		else
		{
			return return_min_val;
		}
	}
}