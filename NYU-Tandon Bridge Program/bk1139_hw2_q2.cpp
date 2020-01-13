//This code assumes the user will only enter valid integers when prompted and separate them with a space****
//This code does not format output to distinguish cases where any of the coins = 1 from plural to singular****

#include <iostream>

using namespace std;

//declare and initialize constant variables of type double with amounts for each respective coin
const double QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, PENNY = 0.01;

//declare and initialize constant variables of type double with amounts for each respective coin
const int CENTS_IN_A_DOLLAR = 100, CENTS_IN_A_QUARTER = 25, CENTS_IN_A_DIME = 10, CENTS_IN_A_NICKEL = 5, CENTS_IN_A_PENNY = 1;

int main()
{
	//declare variables of type int for the number of dollars and cents entered by the user
	int number_of_dollars, number_of_cents;
	
	//declare variables of type int for the number of each coin
	int number_of_quarters, number_of_dimes, number_of_nickels, number_of_pennies;

	//declare variable of type int for the total amount in cents
	int total_amount_in_cents;
	int remaining_amount_in_cents;

	//Prompt the user for the number of each coin and store that input in each respective number_of_coin variable
	cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;

	//store the number of dollars and cents inputted by the user
	cin >> number_of_dollars >> number_of_cents;

	//output the number of dollars and cents entered
	cout << number_of_dollars << " dollars and " << number_of_cents << " cents are:" << endl;

	//calculate the total number of cents for the amounts entered
	total_amount_in_cents = number_of_dollars * CENTS_IN_A_DOLLAR + number_of_cents;
	
	//calculate the number of quarters by dividing the total amount in cents by 25 and then calculating the remaining amount by % 25
	number_of_quarters = total_amount_in_cents / CENTS_IN_A_QUARTER;
	remaining_amount_in_cents = total_amount_in_cents % CENTS_IN_A_QUARTER;

	//calculate the number of dimes by dividing the remaining amount by 10 and then calculating the remaining amount by % 10
	number_of_dimes = remaining_amount_in_cents / CENTS_IN_A_DIME;
	remaining_amount_in_cents = remaining_amount_in_cents % CENTS_IN_A_DIME;

	//calculate the number of nickels by dividing the remaining amount by 5 and then calculating the remaining amount by % 5
	number_of_nickels = remaining_amount_in_cents / CENTS_IN_A_NICKEL;
	remaining_amount_in_cents = remaining_amount_in_cents % CENTS_IN_A_NICKEL;

	//calculate the number of pennies by dividing the remaining amount by 1 and then calculating the remaining amount by % 1
	number_of_pennies = remaining_amount_in_cents / CENTS_IN_A_PENNY;
	remaining_amount_in_cents = remaining_amount_in_cents % CENTS_IN_A_PENNY;

	//Output to the user the minimum number of coins
	cout << number_of_quarters << " quarters, " << number_of_dimes << " dimes, " << number_of_nickels << " nickels and " << number_of_pennies << " pennies" << endl;

	return 0;
}