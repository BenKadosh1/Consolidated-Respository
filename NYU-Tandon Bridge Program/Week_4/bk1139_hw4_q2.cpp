//This program assumes the user will only enter valid positive integers when prompted***
#include <iostream>
#include <string>

using namespace std;

//declare and set values for constants of type int for the limit on how many times each Roman digit can be used and the value of each Roman digit in decimal form
const int D_LIMIT = 1, L_LIMIT = 1, V_LIMIT = 1;
const int C_LIMIT = 4, X_LIMIT = 4, I_LIMIT = 4;
const int M_VALUE = 1000, D_VALUE = 500, C_VALUE = 100, L_VALUE = 50, X_VALUE = 10, V_VALUE = 5, I_VALUE = 1; 

int main()
{
	//declare variables for the user entered integer and a remaining amount variable that will chip away at the initial amount as roman digits are added to the string
	int user_int, remaining_amount;

	//declare and initialize counter variables to 0 for each of the Roman digits to ensure they aren't used more than 1 or 4 times where applicable
	int d_counter = 0, l_counter = 0, v_counter = 0, c_counter = 0, x_counter = 0, i_counter = 0;

	//declare and initialize a string variable to "" for the simplified roman numeral
	string simplified_roman_numeral = "";

	
	//prompt the user to enter a decimal number and set user int equal to it
	cout << "Enter decimal number:" << endl;
	cin >> user_int; 

	//set remaining amount to the user entered amount
	remaining_amount = user_int;

	//use a while loop to determine which roman numeral should be used next from largest to smallest and within the confines of the limits for each specific roman digit while the amount is larger than 0
	while (remaining_amount > 0)
	{
		//if the remaining amount is greater than or equal to M = 1000 then add "M" to the roman numeral string and decrease the remaining amount by M, s the next iteration will determine if M or another value should be used
		if (remaining_amount >= M_VALUE)
		{
			simplified_roman_numeral += "M";
			remaining_amount -= M_VALUE;
		}

		//apply the same methodology as per M to the other roman numeral digits in the else if statements. In addition, determine if it is less than the counter limit for each letter and increment the counter where applicable
		else if (remaining_amount >= D_VALUE && d_counter < D_LIMIT)
		{
			simplified_roman_numeral += "D";
			remaining_amount -= D_VALUE;
			d_counter++;
		}
		else if (remaining_amount >= C_VALUE && c_counter < C_LIMIT)
		{
			simplified_roman_numeral += "C";
			remaining_amount -= C_VALUE;
			c_counter++;
		}
		else if (remaining_amount >= L_VALUE && l_counter < L_LIMIT)
		{
			simplified_roman_numeral += "L";
			remaining_amount -= L_VALUE;
			l_counter++;
		}
		else if (remaining_amount >= X_VALUE && x_counter < X_LIMIT)
		{
			simplified_roman_numeral += "X";
			remaining_amount -= X_VALUE;
			x_counter++;
		}
		else if (remaining_amount >= V_VALUE && v_counter < V_LIMIT)
		{
			simplified_roman_numeral += "V";
			remaining_amount -= V_VALUE;
			v_counter++;
		}
		//else the roman numeral must be I
		else
		{
			simplified_roman_numeral += "I";
			remaining_amount -= I_VALUE;
			i_counter++;
		}
	}
	//outut the decimal value as the simplified roman numeral to the user
	cout << user_int << " is " << simplified_roman_numeral << endl;;

	return 0;
}
