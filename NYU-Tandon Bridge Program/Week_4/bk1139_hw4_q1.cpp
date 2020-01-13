//This program assumes the user will only enter valid positive integers when prompted
//This program assumes 2 is the first even number

#include <iostream>

using namespace std;

int main()
{
	//declare variable for user entered integer
	int user_int;

	//declare and initialize counter variable to 1 to increment with each iteration of the loop
	int counter = 1;

	//print out section a for the while loop section
	cout << "section a" << endl;
	
	//prompt the user to enter a positive integer and store it in user_int
	cout << "\nPlease enter a positive integer: ";
	cin >> user_int;

	//use a while loop to run while the counter variable is less than or equal to the positive integer entered by the user
	while (counter <= user_int)
	{
		//even integer equals 2 * the counter variable
		cout << 2 * counter << endl;

		//increment the counter variable after each iteration
		counter++;
	}

	//output to indicate section b has begun
	cout << "\nsection b" << endl;

	//prompt the user to enter a positive integer and store it in user_int
	cout << "\nPlease enter a positive integer: ";
	cin >> user_int;

	//use a for loop to reset the counter variable to 1 and while the counter is less than the user entered integer run and then increment by 1 
	for (counter = 1; counter <= user_int; counter++)
	{
		//even integer equals 2 * the counter variable
		cout << 2 * counter << endl;
	}

	return 0;
}
