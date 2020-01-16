//File name: bk1139_hw11_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw11_q2


#include <iostream>

int sumOfSquares(int arr[], int arrSize);
/*
  The sumOfSquares function takes two arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, arrSize, which stores the size of the array being passes with the sequence of integers
  The sumOfSquares function returns an integer which is the sum of the squares of each value in the sequence in the array, arr.

  The function's purpose is to compute through recursion the sum of squares for a sequence of integers in an array
*/

bool isSorted(int arr[], int arrSize);
/*
  The isSorted function takes two arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, arrSize, which stores the size of the array being passes with the sequence of integers
  The isSorted function returns a bool which signifies whether or not the array it was passed is sorted

  The function's purpose is to determine through recursion if a sequence in an array is sorted in ascending order or not
*/

void print_arr_results(int arr[], int arrSize, int n);
/*
  The print_arr_results function takes three arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, arrSize, which stores the size of the array being passes with the sequence of integers
	3. An int, n, which is the array number
  The print_arr_results function is a void function and therefore does not have a return value

  The function's purpose is to print to the user whether or not an array is sorted and the sum of squares of the values in that array
*/

int main()
{
	using namespace std;
	
	//below are 3 test arrays that are passed to the print_arr_results function, which prints to the user the sum of squares and whether or not the array is sorted
	int arr_1[] = { 2, -1, 3, 10 }, arr_2[] = { 2,3,3,5,6 }, arr_3[] = { 5,4,3,2,1 };
	int arr_1_size = 4, arr_2_size = 5, arr_3_size = 5;

	cout << "Below are the results for the isSorted and SumOfSquares functions on 3 test arrays\n" << endl;

	print_arr_results(arr_1, arr_1_size, 1);
	cout << endl;

	print_arr_results(arr_2, arr_2_size, 2);
	cout << endl;

	print_arr_results(arr_3, arr_3_size, 3);
	cout << endl;

	return 0;
}

bool isSorted(int arr[], int arrSize)
{
	bool recursive_return_val;

	//mark the base case to end the recursive process at arrSize = 1. If the array is of size one it is sorted
	if (arrSize == 1)
	{
		return true;
	}
	else
	{
		//otherwise, recursively call isSorted on a smaller subset of the array
		recursive_return_val = isSorted(arr + 1, arrSize - 1);

		//if the array at position 0 is less than or equal to that to the right of it and the rest of the array is sorted return true, otherwise false
		if (arr[0] <= arr[1] && recursive_return_val)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


int sumOfSquares(int arr[], int arrSize)
{
	//mark the base case to end the recursive process at arrSize = 1. If the array is of size one return the square of values at arr[0]
	if (arrSize == 1)
	{
		return arr[0] * arr[0];
	}
	else
	{
		//else return the sum at position 0 plus the return value of the sumofsquares on an a subset of the array starting from one to the right and reducing the size accordingly
		return (arr[0] * arr[0]) + sumOfSquares(arr + 1, arrSize - 1);
	}
}

void print_arr_results(int arr[], int arrSize, int n)
{
	using namespace std;
	
	//print to the user the array in question and its contents
	cout << "For array # " << n << ":" << endl;
	cout << "[";
	for (int i = 0; i < arrSize; i++)
	{
		if (i != arrSize-1)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i];
		}
	}
	cout << "]" << endl;

	//call the isSorted and sumOfSquares functions and output to the user the results of the functions for the given array
	bool check_sort = isSorted(arr, arrSize);
	if (check_sort)
	{
		cout << "Array # " << n << " is sorted" << endl;
	}
	else
	{
		cout << "Array # " << n << " is not sorted" << endl;
	}

	int sum_squares = sumOfSquares(arr, arrSize);
	cout << "Array # " << n << "'s sum of squares = " << sum_squares << endl;
}