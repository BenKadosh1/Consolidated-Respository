//This program assumes the user will only enter valid positive integers when prompted***
//Precision set to match output per the homework instructions

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//declare int variable to store the sequence length
	int sequence_length;
	//declare int variable as stop flag for while loop implementation 
	int stop_flag = 0;

	//declare variables of type double to store the user input and calculate the geometric mean
	double user_input, geometric_mean;

	//declare and initialize sequence product to 1. product will be multiplied by each user entry
	double sequence_product = 1.0;

	//set precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	//print out section a
	cout << "section a" << endl;

	//Prompt the user for the length of the sequence and store it in sequence_length
	cout << "\nPlease enter the length of the sequence: ";
	cin >> sequence_length;

	//prompt the user to enter the sequence 
	cout << "Please enter your sequence: " << endl;

	//use a for loop to read in each user entry based on the sequence length entered and *= the sequence product by the user input
	for (int i = sequence_length; i > 0; i--)
	{
		cin >> user_input;
		sequence_product *= user_input;
	}
	
	//calculate the geometric mean by taking the nth root of the sequence product. nth root = pow(x, 1/sequence length)
	geometric_mean = pow(sequence_product,(1/(double)sequence_length));

	//output the result to the user
	cout << "The geometric mean is: " << geometric_mean << endl;




	//print out section b
	cout << "\nsection b" << endl;

	//prompt the user for a non-empty sequence of positive integers
	cout << "\nPlease enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: " << endl;
	
	//reset sequence length and sequence product for second section
	sequence_length = 0;
	sequence_product = 1.0;

	//use a while loop to iterate until the user enters -1
	while (stop_flag == 0)
	{
		//read in the user entry to user_input
		cin >> user_input;

		//determine if -1 has been entered to signal the end of the entries or not and update the stop flag
		if (user_input == -1)
		{
			stop_flag = -1;
		}

		//if not, *= the sequence product by the user_input and increment the sequence length
		else
		{
			sequence_product *= user_input;
			sequence_length++;
		}
	}
	//calculate the geometric mean
	geometric_mean = pow(sequence_product, (1 / (double)sequence_length));

	//output the result to the user
	cout << "The geometric mean is: " << geometric_mean << endl;

	return 0;
}


