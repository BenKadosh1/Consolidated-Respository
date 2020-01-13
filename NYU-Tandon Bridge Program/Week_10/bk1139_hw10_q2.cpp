//File name: bk1139_hw10_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw10_q2


#include <iostream>

//define int* type to int_ptr
typedef int* int_ptr;

int* findMissing(int arr[], int n, int& resArrSize);
/*
  The findMissing function takes three arguments:
	1. An integer array, arr, which is an array storing a sequence of integers
	2. An int, n, which is the upper bound of the range of values stored in the array
	2. An int&, resArrSize, which is the address of the int variable storing the size of the return array
  The findMissing function returns a pointer to an integer which is the address of the array containing the missing values

  The function's purpose is to iterate through an array of integers of size n with values from 0 to n and identify the missing values from the allowable range
*/

void print_array(int arr[], int arrSize);
/*
  The print_array function takes two arguments:
	1. An integer array, arr, which is an array storing a sequence of integers
	2. An int, arr_size, which is the size
  The print_array function is a void function, and therefore does not have a return value

  The function's purpose is to iterate through the array and print its contents
*/

int main()
{
	using namespace std;
	 
	//declare and initialize 4 different test arrays along with their respective sizes
	int arr_1[] = { 3,1,3,0,6,4 }, arr_2[] = { 0,0,1,1,2,3 }, arr_3[] = { 1,2,3,4,5,6,7,8}, arr_4[10] = {10,10,4,7,8,9,3,3,6,6};
	int arr_1_size = 6, arr_2_size = 6, arr_3_size = 8, arr_4_size = 10;
	
	//declare a variable, missing_nums_array_size, which will store the size of the new array created to store missing values
	int missing_nums_array_size;

	//output to the user the format of the results from the test cases 
	cout << "Below are the results from calling the findMissing function on 4 different test cases\n" << endl;
	cout << "The output results for each test case show:"<<endl;
	cout << "1. The test array" << endl;
	cout << "2. The test array's range from 0 to n" << endl;
	cout << "3. An array of the missing value(s) from the allowable range" << endl;


	//output to the user the test case in question, followed by the original test array, the allowable range, and the array with the missing numbers
	cout << "\n\nCase #1\n" << endl;
	cout << "Original Array: ";
	print_array(arr_1,arr_1_size);
	cout << "Range: 0 - " << arr_1_size << endl;
	cout << "Missing numbers: ";

	//initialize an int pointer and set it equal to the new array returned from the findMissing function on the test array
	int_ptr missing_nums_array = findMissing(arr_1, arr_1_size, missing_nums_array_size);
	print_array(missing_nums_array, missing_nums_array_size);
	
	//free the heap memory allocated to the array to store the missing values
	delete[] missing_nums_array;


	//repeat the same steps for test arrays 2, 3, and 4


	cout << "\n\nCase #2\n" << endl;
	cout << "Original Array: ";
	print_array(arr_2, arr_2_size);
	cout << "Range: 0 - " << arr_2_size << endl;
	cout << "Missing numbers: ";

	missing_nums_array = findMissing(arr_2, arr_2_size, missing_nums_array_size);
	print_array(missing_nums_array, missing_nums_array_size);

	delete[] missing_nums_array;



	cout << "\n\nCase #3\n" << endl;
	cout << "Original Array: ";
	print_array(arr_3, arr_3_size);
	cout << "Range: 0 - " << arr_3_size << endl;
	cout << "Missing numbers: ";

	missing_nums_array = findMissing(arr_3, arr_3_size, missing_nums_array_size);
	print_array(missing_nums_array, missing_nums_array_size);

	delete[] missing_nums_array;


	cout << "\n\nCase #4\n" << endl;
	cout << "Original Array: ";
	print_array(arr_4, arr_4_size);
	cout << "Range: 0 - " << arr_4_size << endl;
	cout << "Missing numbers: ";

	missing_nums_array = findMissing(arr_4, arr_4_size, missing_nums_array_size);
	print_array(missing_nums_array, missing_nums_array_size);

	delete[] missing_nums_array;

	return 0;
}

int* findMissing(int arr[], int n, int& resArrSize)
{
	//initialize an int variable, full_range_size to n+1 
	int full_range_size = n + 1;

	//create a dnymaic array of the full range size
	int_ptr full_range_array = new int[full_range_size];

	//iterate through the dynamic array and populate it with values from 0 to n at each respective index
	//this array will store all possible values for us to compare to the originial array and determine the missing values
	for (int i = 0; i < full_range_size; i++)
	{
		full_range_array[i] = i;
	}

	//create an int new size that will store the final size of the return array with only the missing values
	//set the initial value to the full range size
	int new_size = full_range_size;

	//declare a variable that will store the index of each value in the test array and direct the full range value array to that index
	int full_range_array_index;

	//iterate through the original test array - take the value at each index and evalaute the full range index array at the index matching the value
	//set those values equal to -1. The remaining values will be the missing values
	for (int j = 0; j < n; j++)
	{
		full_range_array_index = arr[j];
		if (full_range_array[full_range_array_index] != -1)
		{
			full_range_array[full_range_array_index] = -1;

			//reduce the size of the missing values array
			new_size--;
		}
	}

	//create a new array to store the missing values of size new_size
	int_ptr missing_nums_array = new int[new_size];

	//create an int set to 0 for the indices of the missing nums array to be populated
	int missing_nums_array_index = 0;

	//iterate through the full range array and where there is a value that isn't -1 populate the new missing nums array and increment the index when this occurs
	for (int k = 0; k < full_range_size; k++)
	{
		if (full_range_array[k] != -1)
		{
			missing_nums_array[missing_nums_array_index] = full_range_array[k];
			missing_nums_array_index++;
		}
	}

	//free up the heap memory allocated to storing the full range array
	delete[] full_range_array;

	//return the new size and a pointer to the new array storing the missing nums
	resArrSize = new_size;
	return missing_nums_array;
}

void print_array(int arr[], int arr_size)
{
	using namespace std;
	int i;

	//output brackets at both ends to signify array contents
	cout << "[";

	//iterate through the array and print the value at each index delimitted by commas where applicable
	for (i = 0; i < arr_size; i++)
	{
		if (i != arr_size-1)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i];
		}	
	}
	cout <<"]"<< endl;
}


