//File name: bk1139_hw11_q4.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw11_q4

#include <iostream>

int jump_it_lowest_cost(int arr[], int arr_size);
/*
  The jump_it_lowest_cost function takes two arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, arr_size, which stores the size of the array being passed with the sequence of integers
  The jump_it_lowest_cost function returns an integer which is the min value to traverse the array with only jumps of 1 or 2 at a time

  The function's purpose is to find through recursion the minimum value to traverse the array
  At each step the function determines whether it makes more sense to move 1 and then 2 or to only move 2
*/

void print_arr_results(int arr[], int arr_size, int n);
/*
  The print_arr_results function takes three arguments:
	1. An int array, arr, which stores a sequence of integers
	2. An int, arr_size, which stores the size of the array being passed with the sequence of integers
	3. An int, n, which is the number of the array
  The print_arr_results function is a void function and therefore does not have a return value

  The function's purpose is to print for the user the array being examined and the min cost to traverse it
*/

int main()
{
	using namespace std; 

	//initialize 5 test arrays to output to the user
	int arr_1[] = { 0,3,80,6,57,10 }, arr_2[] = { 0,100,2,60,5,10,1 }, arr_3[] = { 0,3,98,80,4,100,2,1 }, arr_4[] = { 0,1,2,3,1,4,8,45,6,78,2,1 }, arr_5[] = { 0,1,2,4 };
	int arr_1_size = 6, arr_2_size = 7, arr_3_size = 8, arr_4_size = 12, arr_5_size = 4;

	cout << "Below are the results of the Jump It game for 5 different boards represented as arrays\n" << endl;

	//call print_arr_results and pass the 5 test arrays
	print_arr_results(arr_1, arr_1_size, 1);
	print_arr_results(arr_2, arr_2_size, 2);
	print_arr_results(arr_3, arr_3_size, 3);
	print_arr_results(arr_4, arr_4_size, 4);
	print_arr_results(arr_5, arr_5_size, 5);
	return 0;
}

int jump_it_lowest_cost(int arr[], int arr_size)
{
	using namespace std;

	//declare variables for move size and the min values for each move
	int move_size;
	int min_1, min_2;

	//initialize lowest cost to 0
	int lowest_cost = 0;

	//set the base case to end the recursive process when the array size equals 2, 3, or 4
	if (arr_size<=4)
	{
		//return the amount at the last index of the array
		if (arr_size == 2 || arr_size == 3)
		{
			return arr[arr_size - 1];
		}
		else
		{
			//otherwise, calculate the min value for moving 1 or 2 steps
			min_1 = arr[1];
			min_2 = arr[2];

			//evaluate which has a lower cost and move accordingly
			if (min_1 < min_2)
			{
				return arr[1]+ arr[3];
			}
			else
			{
				return arr[2]+arr[3];
			}
		}
	}
	
	else
	{
		//otherwise, calculate the min values for moving 1 and then 2 steps vs 2 steps at once
		min_1 = arr[1] + arr[3];
		min_2 = arr[2];

		//evaluate which has a lower cost and move accordingly
		if (min_1 < min_2)
		{
			move_size = 1;
			lowest_cost += arr[1];
		}
		else
		{
			move_size = 2;
			lowest_cost += arr[2];
		}
		//call a smaller subset of the array to jump_it_lowest_cost and add what is returned to lowest cost
		lowest_cost += jump_it_lowest_cost(arr + move_size, arr_size - move_size);
	}
}

void print_arr_results(int arr[], int arr_size, int n)
{
	using namespace std;

	//print to the user the array in question and its contents
	cout << "For array #" << n << ":" << endl;
	cout << "[";
	for (int i = 0; i < arr_size; i++)
	{
		if (i != arr_size - 1)
		{
			cout << arr[i] << ", ";
		}
		else
		{
			cout << arr[i];
		}
	}
	cout << "]" << endl;

	//output to the user the lowest cost for the array
	int lowest_cost = jump_it_lowest_cost(arr, arr_size);
	cout << "The lowest cost to cross the board is " << lowest_cost <<"\n"<< endl;
}