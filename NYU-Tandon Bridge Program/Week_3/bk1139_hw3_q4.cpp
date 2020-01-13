//This code assumes the user will only enter valid responses when prompted****
//This code assumes that 0.5 rounded to nearest whole number is 1 and -0.5 rounded to the nearest whole number is -1

#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1, CEILING_ROUND = 2, ROUND = 3;
const double FLOOR_CEILING_INCREMENT = 1.0, ROUND_THRESHOLD = 0.49;

int main()
{
	//declare variables for user inputs
	double user_input;
	int user_rounding_method;

	//declare variable for remaining decimal amount for rounding to nearest whole number
	double remaining_decimal;

	//Prompt the user for a real number and store it in user input
	cout << "Please enter a Real number:" << endl;
	cin >> user_input;

	//Prompt the user for a rounding method and store it in user rounding method
	cout << "Choose your rounding method:" << "\n1. Floor round" << "\n2. Ceiling round" << "\n3. Round to the nearest whole number" << endl;
	cin >> user_rounding_method;

	//calculate the decimal portion of the amount entered by the user
	remaining_decimal = user_input - double(int(user_input));
	

	//use a switch to handle cases for the different rounding methods chosen by the user
	switch (user_rounding_method)
	{
		//First case = floor rounding --> if a whole number is entered the floor will be equivalent to it, otherwise the number will be rounded down
		case FLOOR_ROUND:
			//if the user input is greater than or equal to 0 or a negative whole number then the output will be the int casting of the entry
			if (user_input>= 0  || (user_input < 0 && remaining_decimal == 0))
			{
				cout << int(user_input);
			}
			//else take the int casting of the user input minus the increment of 1
			else
			{
				cout << int(user_input - FLOOR_CEILING_INCREMENT);
			}
			break;
		
		//Second case = ceiling rounding --> if a whole number is entered the ceiling will be equivalent to it, otherwise the number will be rounded up
		case CEILING_ROUND:
			//if the user input is greater than or equal to 0 and is not a whole number output the int casting of the user input plus 1
			if (user_input >= 0 && remaining_decimal != 0)
			{
				cout << int(user_input + FLOOR_CEILING_INCREMENT);
			}
			//else take the int casting of the user input
			else
			{
				cout << int(user_input);
			}
			break;
		//third case = round to the nearest whole number (4 possibilities here --> positive or negative and greater than or less than or equal to 0.49
		case ROUND:
			//if the number is greater than or equal to 0 and has a decimal amount greater than .49 the nearest whole number is the int casting of the user input plus 1
			if (user_input >= 0 && remaining_decimal > ROUND_THRESHOLD)
			{
				cout << int(user_input + FLOOR_CEILING_INCREMENT);
			}
			//if the number is greater than or equal to 0 and has a decimal amount less than or equal to .49 the nearest whole number is the int casting of the user input
			else if (user_input >= 0 && remaining_decimal <= ROUND_THRESHOLD)
			{
				cout << int(user_input);
			}
			//if the number is less than 0 and has a decimal amount in absolute value terms greater than .49 the nearest whole number is the int casting of the user input minus 1
			else if (user_input < 0 && -remaining_decimal > ROUND_THRESHOLD)
			{
				cout << int(user_input - FLOOR_CEILING_INCREMENT);
			}
			//if the number is less than 0 and has a decimal amount in absolute value terms less than or equal to .49 the nearest whole number is the int casting of the user input
			else
			{
				cout << int(user_input);
			}
			break;
		//default case is the 3 cases listed were not entered resulting in an error message for the user to re-run
		default:
			cout << "You did not enter a valid integer (1, 2, or 3)";
			break;
	}
	
	return 0;
}

