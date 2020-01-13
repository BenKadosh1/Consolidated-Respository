//File name: bk1139_hw8_q4.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw8_q4


//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


//declare int consts for the length of possible pin entries (0-9) and the actual pin length (5) 
int const ARRAY_LENGTH = 10;
int const PIN_LENGTH = 5;
//declare an int const array to store the user's actual pin
int const PIN_ARRAY[] = { 1,2,3,4,5 };


void randonNumToPinGenerator(int arr[], int arr_size);
/*
  The randonNumToPinGenerator function takes two arguements:
	1. An int [], arr[], which will essentially call by reference an array where we will store a sequence of random integers
	2. An int, arrSize, to tell the function the size of the array that it has been passed
  The randonNumToPinGenerator function is a void function, so it does not have a return value

  The function's purpose is to randomly select a number between 1-3 10 times and fill the array with those values at each respective index

  The function uses srand to initalize a seed and then rand() to randomly select an integer 
  The function iterates through the array and randomly slelects a number, then % 3, and then places the number (1-3) in the array 
*/

bool PinValidator(int arr[], std::string user_input);
/*
  The PinValidator function takes two arguements:
	1. An int [], arr[], which will essentially call by reference an array storing a sequence of random integers
	2. A string, user_input, to pass to the function the user enterd pin 
  The PinValidator function returns a bool signaling whether the user's pin entry is valid or not

  The function's purpose is to compare the user's pin entry to the actual pin

  The function converts the const int array storing the pin to a string, and then compares it to the user entry
*/

int main()
{
	using namespace std;

	//create an array of array length to store the random numbers from 1-3
	int random_num_array[ARRAY_LENGTH];

	//Prompt the user for their pin according to provided mapping
	cout << "Please enter your PIN according to the following mapping:" << endl;
	cout << "PIN:\t" << "0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "NUM:\t";

	//call randonNumToPinGenerator with the declared array to store the randomized numbers
	randonNumToPinGenerator(random_num_array, ARRAY_LENGTH);

	//store the user's entry in the string user_input
	string user_input;
	cin >> user_input;

	//call the PinValidator function with the user input and the randomized mapping array
	//if the user entered string matches the pin, return true and output to the user that the pin is correct, otherwise that it is not correct
	if (PinValidator(random_num_array, user_input))
	{
		cout << "Your PIN is correct";
	}
	else
	{
		cout << "Your PIN is not correct";
	}
	return 0;
}

void randonNumToPinGenerator(int arr[], int arr_size)
{
	using namespace std;
	
	//create a random variable seed
	srand((unsigned int)time(0));

	//declare a random_number variable of type int
	int random_number;

	//iterate through the array for each possible pin entry (0-9) and fill the array with the respective 1-3 number for each index
	for (int i = 0; i < arr_size; i++)
	{
		random_number = (rand() % 3) + 1;
		arr[i] = random_number;
		cout << random_number << " ";
	}
	cout << endl;
	return;
}

bool PinValidator(int arr[], std::string user_input)
{
	using namespace std;

	//declare and initialize a blank string called compare_pin
	string compare_pin = "";
	//declare a variable pin position which will signify the position in the 1-3 array that we should look at
	int pin_position;

	//iterate through the const int array and convert it to the equivalent sequence of randomized 1-3 values
	for (int i = 0; i < PIN_LENGTH; i++)
	{
		//the original value, pin_position, will be found at each index of PIN_ARRAY
		pin_position = PIN_ARRAY[i];
		//append a string conversion of the randomized 1-3 value in arr at the pin position 
		compare_pin += to_string(arr[pin_position]);
	}

	//compare the user_input to compare_pin --> if they match return true, otherwise return false
	if (user_input == compare_pin)
	{
		return true;
	}
	else
	{
		return false;
	}
}