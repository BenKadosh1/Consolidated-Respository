//File name: bk1139_hw9_q3.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw9_q3

#include <iostream>

//define a variable type for int*
typedef int* int_ptr;


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
/*
  The getPosNums1 function takes three arguments:
	1. A pointer to an array, arr, which points to the address of the first index in the array
	2. An integer, arrSize, which is the size of the array
	3. The address of an integer, outPosArrSize, which will be the size of the array in the return value
  The getPosNums1 function returns an int pointer to a new array that contains only positive numbers

  The function's purpose is to assess an array's contents
  and create a new array dynamically to only store the positive values in the original array

  The function iterates through the array first to determine the size of the dynamic array to be created
  A new dynamic array is then created
  The original array is iterated through again and where there is a positive number it is populated in the new array
*/

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
/*
  The getPosNums2 function takes four arguments:
	1. A pointer to an array, arr, which points to the address of the first index in the array
	2. An integer, arrSize, which is the size of the array
	3. A pointer to the address of an integer, outPosArr, which will be the dynamically created positive array
	4. The address of an integer, outPosArrSize, which will be the size of the dynamically created array
  The getPosNums2 is a void function, and therefore does not have a return value.

  The function's purpose is to assess an array's contents
  and create a new array dynamically to only store the positive values in the original array

  The function iterates through the array first to determine the size of the dynamic array to be created
  A new dynamic array is then created through the pointer to the address of the array provided as an arguement
  The original array is iterated through again and where there is a positive number it is populated in the new array
*/

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
/*
  The getPosNums3 function takes three arguments:
	1. A pointer to an array, arr, which points to the address of the first index in the array
	2. An integer, arrSize, which is the size of the array
	3. An int pointer, outPosArrSizePtr, which points to the size of the array in the return value
  The getPosNums3 function returns an int pointer to a new array that contains only positive numbers

  The function's purpose is to assess an array's contents
  and create a new array dynamically to only store the positive values in the original array

  The function iterates through the array first to determine the size of the dynamic array to be created
  A new dynamic array is then created
  The original array is iterated through again and where there is a positive number it is populated in the new array
*/

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
/*
  The getPosNums4 function takes four arguments:
	1. A pointer to an array, arr, which points to the address of the first index in the array
	2. An integer, arrSize, which is the size of the array
	3. A pointer to a pointer to the address of an integer, outPosArrPtr, which will be the dynamically created positive array
	4. An int pointer, outPosArrSizePtr, which points to the size of the array in the return value
  The getPosNums4 is a void function, and therefore does not have a return value.

  The function's purpose is to assess an array's contents
  and create a new array dynamically to only store the positive values in the original array

  The function iterates through the array first to determine the size of the dynamic array to be created
  A new dynamic array is then created through the pointer to the address of the array provided as an arguement
  The original array is iterated through again and where there is a positive number it is populated in the new array
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

	//create 4 arrays with different sizes and integer values to test
	//create 4 int variables storing the size of each respective array
	int arr_1[6] = { 3,-1,-3,0,6,4 }, arr_2[6] = { -6,-5,-4,-3,-2,-1 }, arr_3[6] = { 6,7,8,9,10,11 }, arr_4[8] = { -1,-4,2,6,-5,-8,-12,9 };
	int arr_1_size = 6, arr_2_size = 6, arr_3_size = 6, arr_4_size = 8;

	//declare and initialize 4 int pointers to each of the respective arrays
	int_ptr arr_1_ptr = arr_1;
	int_ptr arr_2_ptr = arr_2;
	int_ptr arr_3_ptr = arr_3;
	int_ptr arr_4_ptr = arr_4;

	//declare 4 int pointers to null, which will point to the positive arrays that will be dynamically created
	int_ptr pos_array_1_ptr = NULL;
	int_ptr pos_array_2_ptr = NULL;
	int_ptr pos_array_3_ptr = NULL;
	int_ptr pos_array_4_ptr = NULL;

	//declare 4 int variables that will store the size of each respective positive array
	int pos_array_1_size, pos_array_2_size, pos_array_3_size, pos_array_4_size;

	//declare 4 int pointers to point the variables storing the size of the positive arrays that will be dynamically created
	int_ptr pos_array_1_size_ptr = &pos_array_1_size;
	int_ptr pos_array_2_size_ptr = &pos_array_2_size;
	int_ptr pos_array_3_size_ptr = &pos_array_3_size;
	int_ptr pos_array_4_size_ptr = &pos_array_4_size;

	//declare 4 pointers to int pointers that will store the address of pointers to the positive arrays that will be dynamically created
	int_ptr* pos_array_1_ptr_ptr = &pos_array_1_ptr;
	int_ptr* pos_array_2_ptr_ptr = &pos_array_2_ptr;
	int_ptr* pos_array_3_ptr_ptr = &pos_array_3_ptr;
	int_ptr* pos_array_4_ptr_ptr = &pos_array_4_ptr;



	//Output to the user the layout of the results being printed
	cout << "Each function will be split into it's own section where it will test 4 arrays" << endl;
	cout << "The new array containing only positive numbers will be printed below the original" << endl;



	//output the results from the first function
	cout << "\nVersion 1: getPosNums1\n" << endl;

	//set the pointer to the positive array to the return value from the function getPosNums1
	pos_array_1_ptr = getPosNums1(arr_1_ptr, arr_1_size, pos_array_1_size);

	//print the original array and positive version of the array to the user
	printArray(arr_1, arr_1_size);
	printArray(pos_array_1_ptr, pos_array_1_size);

	//delete the dynamically allocated memory provided to create the pos_aaray_1 by deleting the array associated with the pointer to it
	delete[] pos_array_1_ptr;


	//repeat above steps for arr_2,3,and 4
	pos_array_2_ptr = getPosNums1(arr_2_ptr, arr_2_size, pos_array_2_size);

	cout << endl;
	printArray(arr_2, arr_2_size);
	printArray(pos_array_2_ptr, pos_array_2_size);

	delete[] pos_array_2_ptr;


	pos_array_3_ptr = getPosNums1(arr_3_ptr, arr_3_size, pos_array_3_size);

	cout << endl;
	printArray(arr_3, arr_3_size);
	printArray(pos_array_3_ptr, pos_array_3_size);

	delete[] pos_array_3_ptr;


	pos_array_4_ptr = getPosNums1(arr_4_ptr, arr_4_size, pos_array_4_size);

	cout << endl;
	printArray(arr_4, arr_4_size);
	printArray(pos_array_4_ptr, pos_array_4_size);

	delete[] pos_array_4_ptr;



	//output the results from the second function
	cout << "\n\nVersion 2: getPosNums2\n" << endl;

	//call the second function with a ptr to the original array, the original array size, a pointer to the positive array, and the positive array size
	getPosNums2(arr_1_ptr, arr_1_size, pos_array_1_ptr, pos_array_1_size);

	//print the original and positive-only arrays
	printArray(arr_1, arr_1_size);
	printArray(pos_array_1_ptr, pos_array_1_size);

	//free up the heap memory allocated to creating the dynamic array
	delete[] pos_array_1_ptr;

	//repreat the process for arrays 2, 3, and 4
	getPosNums2(arr_2_ptr, arr_2_size, pos_array_2_ptr, pos_array_2_size);

	cout << endl;
	printArray(arr_2, arr_2_size);
	printArray(pos_array_2_ptr, pos_array_2_size);

	delete[] pos_array_2_ptr;


	getPosNums2(arr_3_ptr, arr_3_size, pos_array_3_ptr, pos_array_3_size);

	cout << endl;
	printArray(arr_3, arr_3_size);
	printArray(pos_array_3_ptr, pos_array_3_size);

	delete[] pos_array_3_ptr;


	getPosNums2(arr_4_ptr, arr_4_size, pos_array_4_ptr, pos_array_4_size);

	cout << endl;
	printArray(arr_4, arr_4_size);
	printArray(pos_array_4_ptr, pos_array_4_size);

	delete[] pos_array_4_ptr;



	//output the results from the third function
	cout << "\n\nVersion 3: getPosNums3\n" << endl;

	//set the pointer to the positive array equal to the return value from the third function
	//pass the function a pointer to the original array, the original array size, and a pointer to the new positive array size
	pos_array_1_ptr = getPosNums3(arr_1_ptr, arr_1_size, pos_array_1_size_ptr);

	//print the original and positive-only arrays
	printArray(arr_1, arr_1_size);
	printArray(pos_array_1_ptr, *pos_array_1_size_ptr);

	//free up the heap memory allocated to creating the dynamic array
	delete[] pos_array_1_ptr;

	//repeat for arrays 2, 3, and 4
	pos_array_2_ptr = getPosNums3(arr_2_ptr, arr_2_size, pos_array_2_size_ptr);

	cout << endl;
	printArray(arr_2, arr_2_size);
	printArray(pos_array_2_ptr, *pos_array_2_size_ptr);

	delete[] pos_array_2_ptr;


	pos_array_3_ptr = getPosNums3(arr_3_ptr, arr_3_size, pos_array_3_size_ptr);

	cout << endl;
	printArray(arr_3, arr_3_size);
	printArray(pos_array_3_ptr, *pos_array_3_size_ptr);

	delete[] pos_array_3_ptr;

	pos_array_4_ptr = getPosNums3(arr_4_ptr, arr_4_size, pos_array_4_size_ptr);

	cout << endl;
	printArray(arr_4, arr_4_size);
	printArray(pos_array_4_ptr, *pos_array_4_size_ptr);

	delete[] pos_array_4_ptr;



	//output the results from the fourth function
	cout << "\n\nVersion 4: getPosNums4\n" << endl;

	//call the fourth function with a ptr to the original array, the original array size, a pointer to a pointer to the positive array, and a pointer to the positive array size
	getPosNums4(arr_1_ptr, arr_1_size, pos_array_1_ptr_ptr, pos_array_1_size_ptr);

	//print the original and positive-only arrays
	printArray(arr_1, arr_1_size);
	printArray(*pos_array_1_ptr_ptr, *pos_array_1_size_ptr);

	//free up the heap memory allocated to creating the dynamic array
	delete[] * pos_array_1_ptr_ptr;

	//repeat for arrays 2, 3, and 4
	getPosNums4(arr_2_ptr, arr_2_size, pos_array_2_ptr_ptr, pos_array_2_size_ptr);

	cout << endl;
	printArray(arr_2, arr_2_size);
	printArray(*pos_array_2_ptr_ptr, *pos_array_2_size_ptr);

	delete[] * pos_array_2_ptr_ptr;


	getPosNums4(arr_3_ptr, arr_3_size, pos_array_3_ptr_ptr, pos_array_3_size_ptr);

	cout << endl;
	printArray(arr_3, arr_3_size);
	printArray(*pos_array_3_ptr_ptr, *pos_array_3_size_ptr);

	delete[] * pos_array_3_ptr_ptr;


	getPosNums4(arr_4_ptr, arr_4_size, pos_array_4_ptr_ptr, pos_array_4_size_ptr);

	cout << endl;
	printArray(arr_4, arr_4_size);
	printArray(*pos_array_4_ptr_ptr, *pos_array_4_size_ptr);

	delete[] * pos_array_4_ptr_ptr;

	return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
	//set the array size of the new pos array to 0
	outPosArrSize = 0;

	//iterage through the array, arr, index by index and determine if it contains a positive int --> if so increment outPosArrSize
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			outPosArrSize++;
		}
	}
	//declare a variable of type int_ptr to create a dynamic array to store the positive integers
	int_ptr out_pos_nums_arr = new int[outPosArrSize];

	//declare a variable pos_index and set it to 0
	int pos_index = 0;

	//iterate through arr again and where there is a positive number populate it in the new array out_pos_nums_arr, then increment the index of the positive array
	for (int j = 0; j < arrSize; j++)
	{
		if (arr[j] > 0)
		{
			out_pos_nums_arr[pos_index] = arr[j];
			pos_index++;
		}
	}
	//return the int pointer with the address of the first index in the new dynamic array
	return out_pos_nums_arr;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){	//set array size of the new positive array to 0
	outPosArrSize = 0;

	//iterate through the array, arr, index by index and determine if it contains a positive int --> if so increment outPosArrSize
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			outPosArrSize++;
		}
	}

	//create a new dynamic array of size outPosArrSize and set outPosArr equal to it
	outPosArr = new int[outPosArrSize];

	//declare a variable pos_index and set it to 0
	int pos_index = 0;

	//iterate through arr again and where there is a positive number populate it in the new array outPosArr, then increment the index of the positive array
	for (int j = 0; j < arrSize; j++)
	{
		if (arr[j] > 0)
		{
			outPosArr[pos_index] = arr[j];
			pos_index++;
		}
	}}
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr)
{
	//dereference the pointer to access the value pointed to by outPosArrSizePtr, and set the array size of the new pos array to 0
	*outPosArrSizePtr = 0;

	//iterage through the array, arr, index by index and determine if it contains a positive int
	//if so increment the dereferenced value of outPosArrSizePtr
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			(*outPosArrSizePtr)++;
		}
	}

	//declare a variable of type int_ptr to create a dynamic array to store the positive integers
	int_ptr out_pos_nums_arr = new int[*outPosArrSizePtr];

	//declare a variable pos_index and set it to 0
	int pos_index = 0;

	//iterate through arr again and where there is a positive number populate it in the new array out_pos_nums_arr, then increment the index of the positive array
	for (int j = 0; j < arrSize; j++)
	{
		if (arr[j] > 0)
		{
			out_pos_nums_arr[pos_index] = arr[j];
			pos_index++;
		}
	}

	//return the int pointer with the address of the first index in the new dynamic array
	return out_pos_nums_arr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
	//dereference the pointer to access the value pointed to by outPosArrSizePtr, and set the array size of the new pos array to 0
	*outPosArrSizePtr = 0;

	//iterage through the array, arr, index by index and determine if it contains a positive int
	//if so increment the dereferenced value of outPosArrSizePtr
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > 0)
		{
			(*outPosArrSizePtr)++;
		}
	}

	//create a new dynamic array by dereferencing outPosArrPtr and setting it equal to a new array of size determined by dereferencing the value at outPosArrSizePtr
	*outPosArrPtr = new int[*outPosArrSizePtr];

	//declare a variable pos_index and set it to 0
	int pos_index = 0;

	//iterate through arr again and where there is a positive number populate it in the new array by dereferencing outPosArrPtr and accessing an index of it
	//then increment the index of the positive array
	for (int j = 0; j < arrSize; j++)
	{
		if (arr[j] > 0)
		{
			(*outPosArrPtr)[pos_index] = arr[j];
			pos_index++;
		}
	}
}

void printArray(int arr[], int arrSize)
{
	using namespace std;
	int i;

	//iterate through the array and print the value at each index
	for (i = 0; i < arrSize; i++) 
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}