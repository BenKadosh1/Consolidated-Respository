//This code assumes the user will only enter valid integers when prompted****
//This code does not format output to distinguish cases where dollars/cents = 1 dollar and/or 1 cent from plural to singular****

#include <iostream>

using namespace std;

//declare and initialize constant variables of type double with amounts for each respective coin
const double QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, PENNY = 0.01;

//declare and initialize constant variable of type int with the amount of cents in a dollar
const int CENTS_IN_A_DOLLAR = 100;

int main()
{
	//declare variables of type double for the number of each coin - selected double as they will be multiplied by the constants which are also doubles
	double number_of_quarters, number_of_dimes, number_of_nickels, number_of_pennies;

	//declare variable of type int for the total amount in cents
	int total_amount_in_cents;

	//Prompt the user for the number of each coin and store that input in each respective number_of_coin variable
	cout << "Please enter number of coins:" << endl;

	cout << "# of quarters: ";
	cin >> number_of_quarters;

	cout << "# of dimes: ";
	cin >> number_of_dimes;

	cout << "# of nickels: ";
	cin >> number_of_nickels;

	cout << "# of pennies: ";
	cin >> number_of_pennies;

	//calculate the total amount in cents and explicitly cast the result as an int
	total_amount_in_cents = int(((number_of_quarters * QUARTER) + (number_of_dimes * DIME) + (number_of_nickels * NICKEL) + (number_of_pennies * PENNY))*CENTS_IN_A_DOLLAR);
	
	//Output to the user the total in dollars and cents
	cout << "The total is " << total_amount_in_cents / CENTS_IN_A_DOLLAR << " dollars and " << total_amount_in_cents % CENTS_IN_A_DOLLAR << " cents" << endl;

	return 0;
}
