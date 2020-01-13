//This program assumes the user will only enter valid positive integers when prompted***

/*  The fundemental structure to the algorithm I used in this code has the following major components
1.  Use a for loop to iterate through each integer from one to the user input
1a. During each new iteration we will evaluate a new integer to determine whether it has more even digits than odd
1b. For each iteration we will set the iteration amount we will analyze digit by digit to the iteration i in the for loop
1c. We will reset even_digits and odd_digits counters to 0 for the new number as well as the stop flag

2.  Use a while loop to iterate through each digit of the given number to be analyzed iteration_amount
2a. While the iteration amount does not equal 0 stop flag will equal 0 and the while loop will continue to iterate --> once it hits an amount of 0 the stop flag is set to -1
2b. In order to determine the parity of each digit we need to isolate each digit of the number. In order to do so we can take (iteration_amount % 10) 
2c. We can then take that amount and % 2 it to determine whether it is even or odd and increment the respective variable when that condition is met 
2d. After each iteration divide the iteration amount by 10 to shift to the next digit to analyze for parity
2e. Once the iteration amount equals 0 we can stop the while loop to determine if there are more even digits than odd for that number
2f. If yes, output the number
2g. Then continue with the for loop iteration to the next number from 1 - n to be analyzed
*/
#include <iostream>

using namespace std;

int main()
{
	//declare variables of type int for the user input, iteration amount that will assess each digit to determine parity, even and odd digit counters
	int user_int, iteration_amount, even_digits_counter, odd_digits_counter;
	
	//create stop flag bool for while loop to determine when to stop running
	bool stop_flag;

	//Prompt the user for a positive integer and store it in user_int
	cout << "Please enter a positive integer: ";
	cin >> user_int;

	//Output to the user that the list below is all relevant numbers with more even digits than odd
	cout << "\nBelow is a list of all numbers from 1 to " << user_int << " that have more even digits than odd digits:" << endl;

	//use a for loop to iterate through each integer from one to the user input
	for (int i = 1; i <= user_int; i++)
	{
		//reset iteration amount for analysis, digit counters, and stop flag
		iteration_amount = i;
		even_digits_counter = 0;
		odd_digits_counter = 0;
		stop_flag = true;

		//use a while loop to iterate through each digit of the number being analyzed
		while (stop_flag == true)
		{
			//determine if the digit furthest to the right is even or odd and increment the respective counter variable
			if ((iteration_amount % 10) % 2 == 0)
			{
				even_digits_counter++;
			}
			else
			{
				odd_digits_counter++;
			}

			//after each iteration divide the iteration amount by 10 to shift to the next digit to analyze
			iteration_amount /= 10;
			
			//determine if the amount is equal to zero to stop the while loop by updating the stop flag
			if (iteration_amount == 0)
			{
				stop_flag = false;
			}
		}
		//if the even digit count is greater than the odd digit count output the number to the user
		if (even_digits_counter > odd_digits_counter)
		{
			cout << i << endl;
		}
	}
	return 0;
}
