//This code assumes the user will only enter valid integers when prompted****

#include <iostream>

using namespace std;


int main()
{
	// declare variables of type int for storing user entered values
	int user_int_1, user_int_2;

	//set precision to one decimal place for the division calculation to follow
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	//prompt the user to enter two positive integers separated by a space
	cout << "Please enter two positive integers, separated by a space:" << endl;

	//store the user inputs in user_int_1 and _2 respectively.
	cin >> user_int_1 >> user_int_2;

	//output to the user the sum, difference, product, quotient, div and mod results for the two integers entered
	cout << user_int_1 << " + " << user_int_2 << " = " << user_int_1 + user_int_2 << endl;
	cout << user_int_1 << " - " << user_int_2 << " = " << user_int_1 - user_int_2 << endl;
	cout << user_int_1 << " * " << user_int_2 << " = " << user_int_1 * user_int_2 << endl;

	//cast the user integer inputs as doubles to output necessary precision after the decimal
	cout << user_int_1 << " / " << user_int_2 << " = " << double(user_int_1) / double(user_int_2) << endl;

	cout << user_int_1 << " div " << user_int_2 << " = " << user_int_1 / user_int_2 << endl;
	cout << user_int_1 << " mod " << user_int_2 << " = " << user_int_1 % user_int_2 << endl;

	return 0;
}

