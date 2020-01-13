//File name: bk1139_hw8_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw8_q1


//This code assumes the user will provide valid entries when prompted


#include <iostream>

//declare and initialize an integer constant to store the max size of the array to store the user entered sequence
int const MAX_ARRAY_SIZE = 20;

int minInArray(int arr[], int arrSize);
/*
  The minInArray function takes two arguements:
	1. An int [], arr[], which will essentially call by reference an array storing a sequence of integers entered by the user
	2. An int, arrSize, to tell the function the size of the array that it has been passed
  The minInArray function returns an int with the minimum value in the sequence

  The function's purpose is to determine the minimum value in the sequence

  The function first sets the minimum value to that in arr[0]
  The function then iterates from 1 to MAX_ARRAY_SIZE to compare the minimum value to that in each index 
  and updates the minimum value where applicable
*/

void printMinIndices(int arr[], int arrSize, int min);
/*
  The printMinIndices function takes three arguements:
	1. An int [], arr[], which will essentially call by reference an array storing a sequence of integers entered by the user
	2. An int, arrSize, to tell the function the size of the array that it has been passed
	3. An int, min, which tells the function the minimum value to look for at each index 
  The printMinIndices function is a void function, and therefore does not have a return value

  The function's purpose is to output to the user where in the sequence the minimum value exists

  The function iterates from 0 to MAX_ARRAY_SIZE to compare the minimum value to that in each index
  and outputs the index if the value in that index matches to min
*/

int main()
{
	using namespace std;

	//declare an array of integers called user_sequence of size MAX_ARRAY_SIZE
	int user_sequence[MAX_ARRAY_SIZE];

	//Prompt the user for 20 integers separated by spaces
	cout << "Please enter 20 integers separated by a space:" << endl;

	//iterate through each index of user_sequence and update the value in each index to correspond to the user sequence
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		cin >> user_sequence[i];
	}

	//declare and initialize a variable to store the minimum value in the sequence by calling the
	//minInArray function with the user_sequence and max array size
	int min_in_sequence = minInArray(user_sequence, MAX_ARRAY_SIZE);

	//call printMinIndices to print to the user where the minimum value can be found in the sequence
	printMinIndices(user_sequence, MAX_ARRAY_SIZE, min_in_sequence);
	
	return 0;
}

int minInArray(int arr[], int arrSize)
{
	using namespace std;
	
	//declare and initialize a varible min to the first value in the sequence
	int min = arr[0];

	//iterate through the rest of the array and compare the value at each index to min 
	//to determine if it needs to be updated to a smaller number
	for (int i = 1; i < arrSize; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

void printMinIndices(int arr[], int arrSize, int min)
{
	using namespace std;

	//output to the user what the minimum value is, and at which indices it is located
	cout << "The minimum value is " << min << ", and it is located in the following indices: ";

	//iterate through each index of the array and compare its value to min to determine if 
	//the  index should be outputted to the user
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == min)
		{
			cout << i << " ";
		}
	}
	return;
}