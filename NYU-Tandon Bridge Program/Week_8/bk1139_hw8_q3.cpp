//File name: bk1139_hw8_q3.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw8_q3


#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
/*
  The reverseArray function takes two arguements:
	1. An int [], arr[], which will essentially call by reference the location of the first index position arr[0] in an array storing a sequence of integers
	2. An int, arrSize, to tell the function the size of the array that it has been passed
  The reverseArray function is a void function and therefore does not have a return value

  The function's purpose is to reverse the sequence of values in the array

  The function iterates through n/2 positions in the array and swaps the given value 
  with its counterpart in the other n/2 positions
  i with j, i+1 with j-1 and so on with i = 0 and j = n
*/

void removeOdd(int arr[], int& arrSize);
/*
  The removeOdd function takes two arguements:
	1. An int [], arr[], which will essentially call by reference the location of the first index position arr[0] in an array storing a sequence of integers
	2. An int, arrSize, called by reference to tell the function the size of the array that it has been passed
  The removeOdd function is a void function and therefore does not have a return value

  The function's purpose is to remove all odd values in the array

  The function iterates through the array determining where there is an odd integer
  if an even integer is to the right of it in the sequence the even integer will be shifted 
  to the odd position
  variables are reset or incremented where applicable
*/

void splitParity(int arr[], int arrSize);
/*
  The splitParity function takes two arguements:
	1. An int [], arr[], which will essentially call by reference the location of the first index position arr[0] in an array storing a sequence of integers
	2. An int, arrSize, to tell the function the size of the array that it has been passed
  The splitParity function is a void function and therefore does not have a return value

  The function's purpose is set all odd integers in the sequence first before any even integers

  The function iterates through the array determining where there is an odd and even integer
  If an odd integer is to the left of an even number it will be locked in
  if an odd integer is to the right of an even in the sequence the odd integer will be shifted
  to the even position and the even value to the odd position
  variables are reset or incremented where applicable
*/

void printArray(int arr[], int arrSize);
/*
  The printArray function takes two arguements:
	1. An int [], arr[], which will essentially call by reference the location of the first index position arr[0] in an array storing a sequence of integers
	2. An int, arrSize, to tell the function the size of the array that it has been passed
  The printArray function is a void function and therefore does not have a return value

  The function's purpose is to print all values in a given array
*/

int main()
{
	using namespace std; 
	//test cases for each function --> *added additional test cases per Aleks' comments on Piazza

	cout << "Each array will be printed before and after the function on two separate, subsequent lines" << endl;

	//reverse array section
	int arr1[10] = {9,2,14,12,-3}, arr2[10] = {1,2,3,4}, arr3[10] = {7,6,5,4,3,2,1}, arr4[10] = {2,8,4,10,6};
	int arr1Size = 5, arr2Size = 4, arr3Size = 7, arr4Size = 5;
	
	cout << "\nReverse Array Section" << endl;

	printArray(arr1, arr1Size);
	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);
	cout << endl;

	printArray(arr2, arr2Size);
	reverseArray(arr2, arr2Size);
	printArray(arr2, arr2Size);
	cout << endl;

	printArray(arr3, arr3Size);
	reverseArray(arr3, arr3Size);
	printArray(arr3, arr3Size);
	cout << endl;

	printArray(arr4, arr4Size);
	reverseArray(arr4, arr4Size);
	printArray(arr4, arr4Size);
	cout << endl;


	//removeOdd section
	int arr5[10] = { 21,12,6,7,14 }, arr6[10] = { 1,2,3,4 }, arr7[10] = { 9,7,5,3,1,-1,-3 }, arr8[10] = { 2,8,4,10,6 }, arr9[15] = { 1,3,2,4,5,7,9,6,-8,10,11 };
	int arr5Size = 5, arr6Size = 4, arr7Size = 7, arr8Size = 5, arr9Size = 11;

	cout << "\nRemove Odd Section" << endl;

	printArray(arr5, arr5Size);
	removeOdd(arr5, arr5Size);
	printArray(arr5, arr5Size);
	cout << endl;

	printArray(arr6, arr6Size);
	removeOdd(arr6, arr6Size);
	printArray(arr6, arr6Size);
	cout << endl;

	printArray(arr7, arr7Size);
	removeOdd(arr7, arr7Size);
	printArray(arr7, arr7Size);
	cout << endl;

	printArray(arr8, arr8Size);
	removeOdd(arr8, arr8Size);
	printArray(arr8, arr8Size);
	cout << endl;

	printArray(arr9, arr9Size);
	removeOdd(arr9, arr9Size);
	printArray(arr9, arr9Size);
	cout << endl;


	//splitParity section
	int arr10[10] = {3,6,4,1,12}, arr11[10] = { 1,2,3,4 }, arr12[10] = { 8,6,4,2,7,5,3,1 }, arr13[10] = { 8,6,7,5,4,2,3,1 }, arr14[15] = { 1,3,5,2,4,7,5,6,8 };
	int arr10Size = 5, arr11Size = 4, arr12Size = 8, arr13Size = 8, arr14Size = 9;

	cout << "\nSplit Parity Section" << endl;

	printArray(arr10, arr10Size);
	splitParity(arr10, arr10Size);
	printArray(arr10, arr10Size);
	cout << endl;

	printArray(arr11, arr11Size);
	splitParity(arr11, arr11Size);
	printArray(arr11, arr11Size);
	cout << endl;

	printArray(arr12, arr12Size);
	splitParity(arr12, arr12Size);
	printArray(arr12, arr12Size);
	cout << endl;

	printArray(arr13, arr13Size);
	splitParity(arr13, arr13Size);
	printArray(arr13, arr13Size);
	cout << endl;

	printArray(arr14, arr14Size);
	splitParity(arr14, arr14Size);
	printArray(arr14, arr14Size);
	cout << endl;

	return 0;
}

void reverseArray(int arr[], int arrSize)
{
	//create a reverse index variable of type int to store the ending index of the array
	int reverse_index = arrSize - 1;
	//declare a variable of type int to store temp values
	int temp_value;

	//iterate through the first half of the array and swap the value in arr[i] with that at reverse index
	//then set arr[reverse_index] to that which was at position i
	//decrement reverse index
	for (int i = 0; i < arrSize / 2; i++)
	{
		temp_value = arr[i];
		arr[i] = arr[reverse_index];
		arr[reverse_index] = temp_value;
		reverse_index--;
	}
}

void removeOdd(int arr[], int& arrSize)
{
	//declare and initialize an open_position_index to -1 and num of open positions to 0
	int open_position_index = -1;
	int num_open_positions = 0;

	//iterate through the array and assess whether the value at a given index is even or odd
	for (int i = 0; i < arrSize; i++)
	{
		//if odd 
		if (arr[i] % 2 != 0)
		{
			//if this is the first odd index set the open position index
			if (open_position_index < 0)
			{
				open_position_index = i;
			}
			//increment the number of open/odd positions
			num_open_positions++;
		}
		//else it is even
		else
		{
			//if there is an open position (odd number) to the left swap the odd value with the even
			//increment the open_position_index - this will either point to the next odd number in the sequence
			//or the same odd number that is now where the even position was previously
			if (open_position_index > -1)
			{
				arr[open_position_index] = arr[i];
				open_position_index++;
			}
		}
	}
	//reduce array size by the number of open positions (odd numbers in the sequence)
	arrSize -= num_open_positions;
}

void splitParity(int arr[], int arrSize)
{
	//declare and initalize 2 int variables to -1 for the odd and even position indices
	int odd_position_index = -1, even_position_index = -1;

	//declare an int variable to store temp values
	int temp_val;

	//iterate through the array
	for (int i = 0; i < arrSize; i++)
	{
		//determine if the number at i is odd or even
		if (arr[i] % 2 != 0)
		{
			//if the odd position has not been set, set it to i
			if (odd_position_index < 0)
			{
				odd_position_index = i;
			}
		}
		//else --> even
		else
		{
			//if the even position has not been set, set it to i
			if (even_position_index < 0)
			{
				even_position_index = i;
			}
		}

		//once an odd and even index have been evaluated and can be compared
		if (odd_position_index > -1 && even_position_index > -1)
		{
			//if the odd is already to the left of the even we will keep it where it is and reset the odd_position_index
			if (odd_position_index < even_position_index)
			{
				odd_position_index = -1;
			}
			//if there is an odd to the right of an even we will want to shift
			else
			{
				//swap values at odd and even indices --> leverage a temp variable
				temp_val = arr[odd_position_index];
				arr[odd_position_index] = arr[even_position_index];
				arr[even_position_index] = temp_val;

				//once the odd has been placed in the even position reset the odd to -1 to find the next odd int and lock in the current odd
				//increment the even position index this will either point to the next even number in the sequence
				//or the same even number that is now where the odd number was previously
				odd_position_index = -1;
				even_position_index++;
			}
		}
	}
}

void printArray(int arr[], int arrSize) 
{
	int i;
	//iterate through the array and print the value at each index
	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}