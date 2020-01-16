//File name: bk1139_hw10_q3.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw10_q3

//This code assumes the user will enter valid inputs when promoted

#include <iostream>
#include <vector>

using namespace std;

//define int* type to int_ptr
typedef int* int_ptr;


int main1();
/*
  The main1 function takes no arguments:
	
  The main1 function returns an int 0

  The function's purpose is to call the sequence_array_storage and array_num_searcher functions
  The functions will prompt the user to enter a sequence of integers and then enter a number to search for in the sequence
*/

int_ptr sequence_array_storage(int& sequence_size);
/*
  The sequence_array_storage function takes one argument:
	1. An int&, sequence_size, which is the address of the int variable storing the size of the return array
  The sequence_array_storage function returns a pointer to an integer which is the address of the array containing the sequence of integers

  The function's purpose is to prompt the user for a sequence of positive integers and store them in an array and return a pointer to the array and the size of the array
*/

void array_num_searcher(int sequence_array[], int sequence_arr_size);
/*
  The array_num_searcher function takes two arguments:
	1. An array of integers, sequence_array, which contains a sequence of integers that is searched through for a specific integer
	2. An int, sequence_arr_size, which is the size of sequence_array
  The array_num_searcher function is a void function and therefore does not have a return value

  The function's purpose is to search through the user entered sequence for a user entered integer and output to the user where it can be found in the sequence
*/

int main2();
/*
  The main2 function takes no arguments:

  The main2 function returns an int 0

  The function's purpose is to call the sequence_vector_storage and vector_num_searcher functions
  The functions will prompt the user to enter a sequence of integers and then enter a number to search for in the sequence
*/

void sequence_vector_storage(vector<int>& sequence);
/*
  The sequence_vector_storage function takes one argument:
	1. A vector<int>&, sequence, which is the beginning address of the vector of integers storing the sequence entered by the user
  The sequence_vector_storage is a void function and therefore does not have a return value, however the function argument is passed by reference

  The function's purpose is to prompt the user for a sequence of positive integers and store them in a vector
*/

void vector_num_searcher(vector<int>& sequence);
/*
  The vector_num_searcher function takes one argument:
	1. A vector<int>&, sequence, which is the beginning address of the vector of integers storing the sequence entered by the user
  The sequence_vector_storage is a void function and therefore does not have a return value, however the function argument is passed by reference

  The function's purpose is to search through the user entered sequence for a user entered integer and output to the user where it can be found in the sequence
*/

int main()
{
	//Output to the user when main1 and main2 are being entered into and exited from
	//Call main1 and then main2
	cout << "Entering main1()\n" << endl;
	main1();
	cout << "\nExiting main1()" << endl;

	cout << "\nEntering main2()\n" << endl;
	main2();
	cout << "\nExiting main2()" << endl;

	return 0;
}


int main1()
{
	//declare an int variable sequence_size that will store the size of the array of integers entered by the user 
	int sequence_size;

	//declare a pointer to an integer, sequence_array, which will store the address of the array storing the sequence entered by the user
	//call the sequence_array_storage function and pass it the variable sequence_size by reference to store the size of the return array
	int_ptr sequence_array = sequence_array_storage(sequence_size);

	//call the array_num_searcher function with user entered sequence and the array size. The function will prompt the user to enter a number to search for 
	array_num_searcher(sequence_array, sequence_size);

	//free the heap memory allocated to storing the sequence_array 
	delete[] sequence_array;

	return 0;
}

int_ptr sequence_array_storage(int& sequence_size)
{
	//prompt the user for a sequence of positive integers terminating when -1 is entered
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing - 1." << endl;

	//declare a variable of type int which will store the user entries
	int user_int;

	//initalize variables to store the capacity and actual size of the array storing the sequence of integers
	int sequence_arr_capacity = 1;
	int sequence_arr_size = 0;

	//initialize a bool to true to be used as a flag for when to terminate the while loop
	bool continue_flag = true;

	//create a dynamic array called sequence_array of size sequence_arr_capacity
	int_ptr sequence_array = new int[sequence_arr_capacity];

	while (continue_flag)
	{
		//store the user entry in user_int
		cin >> user_int;

		//if the user has entered -1 that is the end of the sequence and we set the bool flag = false
		if (user_int == -1)
		{
			continue_flag = false;
		}

		//otherwise the user has entered a value we need to store in the array
		else
		{
			//if the actual size of the array matches the capacity, we double it to create more capacity
			//we must create another dynamic array with double the capcity and copy the original contents to the temp array
			//we then free up the smaller array and re-direct the pointer to the new larger array
			if (sequence_arr_size == sequence_arr_capacity)
			{
				sequence_arr_capacity *= 2;
				int_ptr temp_array = new int[sequence_arr_capacity];

				for (int i = 0; i < sequence_arr_size; i++)
				{
					temp_array[i] = sequence_array[i];
				}
				delete[] sequence_array;
				sequence_array = temp_array;
			}
			//store the user int in the sequence array and increment its actual size
			sequence_array[sequence_arr_size] = user_int;
			sequence_arr_size++;
		}
	}
	//set the sequence_size passed by reference equal to the local sequence_arr_size
	sequence_size = sequence_arr_size;

	//return a pointer to the array storing the user entered sequence
	return sequence_array;
}

void array_num_searcher(int sequence_array[], int sequence_arr_size)
{
	//declare a variable to store the user entered value to search for
	int num_search;

	//prompt the user for a number and store it in num_search
	cout << "Please enter a number you want to search." << endl;
	cin >> num_search;
	cout << num_search << " shows in ";

	//initialize two int variables one to store the total number of occurences of num_search and the other to index through that count
	int num_search_count = 0, num_search_iterator = 0;

	//iterate through the sequence array to determine the frequency of num_search
	for (int j = 0; j < sequence_arr_size; j++)
	{
		if (sequence_array[j] == num_search)
		{
			num_search_count++;
		}
	}

	//branching statements to account for whether there are none, one, or more than one occurences of num_search
	//if at least one occurrence - output to the user at which line(s) it can be found
	if (num_search_count == 0)
	{
		cout << "no lines." << endl;
	}
	else if (num_search_count == 1)
	{
		for (int j = 0; j < sequence_arr_size; j++)
		{
			if (sequence_array[j] == num_search)
			{
				cout << "line " << j + 1 << "." << endl;
			}
		}
	}
	else
	{
		cout << "lines ";
		for (int j = 0; j < sequence_arr_size; j++)
		{
			if (sequence_array[j] == num_search)
			{
				num_search_iterator++;
				if (num_search_iterator != num_search_count)
				{
					cout << j + 1 << ", ";
				}
				else
				{
					cout << j + 1 << "." << endl;
				}
			}
		}
	}
}

int main2()
{
	//declare a vector of integers to store the sequence to be entered by the user
	vector<int> sequence_vector;

	//pass the sequence vector by reference to the sequence_vector_storage function where it will prompt the user to enter a sequence of integers and store them in the vector
	sequence_vector_storage(sequence_vector);

	//call the vector_num_searcher function with the vector storing user entered sequence. The function will prompt the user to enter a number to search for 
	vector_num_searcher(sequence_vector);

	return 0;
}

void sequence_vector_storage(vector<int>& sequence)
{
	//prompt the user for a sequence of positive integers terminating when -1 is entered
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing - 1." << endl;

	//declare a variable of type int which will store the user entries
	int user_int;

	//initialize a bool to true to be used as a flag for when to terminate the while loop
	bool continue_flag = true;

	while (continue_flag)
	{
		//store the user entry in user_int
		cin >> user_int;

		//if the user entered -1 set thecontinue_flag to false
		if (user_int == -1)
		{
			continue_flag = false;
		}
		//else push back the new value to the sequence
		else
		{
			sequence.push_back(user_int);
		}
	}
}

void vector_num_searcher(vector<int>& sequence)
{
	//declare a variable to store the user entered value to search for
	int num_search;

	//prompt the user for a number and store it in num_search
	cout << "Please enter a number you want to search." << endl;
	cin >> num_search;
	cout << num_search << " shows in ";

	//initialize two int variables one to store the total number of occurences of num_search and the other to index through that count
	int num_search_count = 0, num_search_iterator = 0;

	//iterate through the sequence array to determine the frequency of num_search
	for (int j = 0; j < sequence.size(); j++)
	{
		if (sequence[j] == num_search)
		{
			num_search_count++;
		}
	}

	//branching statements to account for whether there are none, one, or more than one occurences of num_search
	//if at least one occurrence - output to the user at which line(s) it can be found
	if (num_search_count == 0)
	{
		cout << "no lines." << endl;
	}
	else if (num_search_count == 1)
	{
		for (int j = 0; j < sequence.size(); j++)
		{
			if (sequence[j] == num_search)
			{
				cout << "line " << j + 1 << "." << endl;
			}
		}
	}
	else
	{
		cout << "lines ";
		for (int j = 0; j < sequence.size(); j++)
		{
			if (sequence[j] == num_search)
			{
				num_search_iterator++;
				if (num_search_iterator != num_search_count)
				{
					cout << j + 1 << ", ";
				}
				else
				{
					cout << j + 1 << "." << endl;
				}
			}
		}
	}
}