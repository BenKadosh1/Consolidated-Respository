//This program assumes the user will only enter valid positive integers when prompted***

/* The fundemental structure to the algorithm I used in this code has two major components
1. A while loop to determine the largest exponent x, where 2^x is greater than the user entered value to ensure the index length of the binary value is large enough to properly represent the decimal value
1a. Once we have exceeded the user input we want to reduce the exponent by 1 to ensure the first binary digit equals 1
1b. Reducing the exponent count will apply to all cases except for when the user input is 0, in which case the exponent is still 0

2. a for loop that iterates from the largest index position to 0 and decrements each time
2a. within each iteration of the for loop compare the remaining amount to 2^largest exponent to know whether or not that index position should be filled with a 1 or 0
2b. if a 1 is entered, reduce the remaining balance by 2^ largest exponent
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//declare variables of type long int for the user entered integer and setting up a reminaing amount integer
	long int user_int, remaining_int;

	//declare and initialize largest exponent to 0 
	int largest_exponent = 0; 

	//prompt the user for a decimal number and store it in user_int
	cout << "Enter decimal number:" << endl;
	cin >> user_int;

	//set remaining int amount to the user entered amount
	remaining_int = user_int;


	//use a while loop to determine the largest exponent and increment it by 1 for each iteration
	while (user_int >= pow(2,largest_exponent))
	{
		largest_exponent++;
	}
	
	//if the largest exponent doesn't equal 0 reduce it by 1
	if (largest_exponent != 0)
		largest_exponent--;
	
	//print out message to the user before the binary representation
	cout << "The binary representation of " << user_int << " is ";

	//iterate through a for loop starting from largest exponent to 0 and decrementing by 1 
	for (largest_exponent; largest_exponent >= 0; largest_exponent--)
	{
		//if the remaining amount is greater than or equal to 2^exponent at that index a 1 would fill that index and the remaining amount should be reduced by 2^largest exp
		if (remaining_int >= pow(2, largest_exponent))
		{
			cout << 1;
			remaining_int -= pow(2, largest_exponent);
		}
		//else output 0
		else
		{
			cout << 0;
		}
	} 
	return 0;
}
