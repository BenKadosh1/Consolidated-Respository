//File name: bk1139_hw6_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw6_q1



//This code assumes the user will provide valid entries when prompted

#include <iostream>

int fib(int n);
/*The fib function takes one arguement, n, which is of type int, and returns an int
  The fib function returns the n-th element of the Fibonacci sequence

  The function determines the n-th element by iterating from 1 to n and taking the sum of
  the previous two numbers in the sequence.
*/

int main()
{	
	using namespace std;

	//declare a variable of type int to store the value entered by the user
	int user_int;

	//Prompt the user for a positive integer and store it in user_int
	cout << "Please enter a positive integer: ";
	cin >> user_int;
	
	//output to the user the return value of the fib function for the value they entered
	cout<<fib(user_int);
	
	return 0;
}

int fib(int n)
{
	using namespace std;

	//declare variables of type int for the current fib element as well as the previous 2 numbers in the sequence. 
	int current_fib_element;
	int previous_1, previous_2;

	//iterate through the sequence from one to the user provided entry for the nth element in the Fibonacci sequence
	for (int i = 1; i <= n; i++)
	{ 
		//if i equals one or two then set values for previous and current fib to 1 as they are the values for the first 2 numbers in the sequence
		if (i == 1)
		{
			previous_2 = 1;
			current_fib_element = 1;
		}
		else if (i == 2)
		{
			previous_1 = 1;
			current_fib_element = 1;
		}
		//set the current fib element amount to the sum of the previous two, then set previous_2 to previous_1 and previous_1 to current fib
		else
		{
			current_fib_element = previous_1 + previous_2;
			previous_2 = previous_1;
			previous_1 = current_fib_element;
		}
	}
	//return the current fib element to the main function
	return current_fib_element;
}