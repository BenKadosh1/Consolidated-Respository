//File name: bk1139_hw12_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw12_q1

//This code assumes the user will enter valid inputs, but has some basic validation checks

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Money class mirrors that which can be found in the text book, with a few additions 
//Money class definition
class Money
{
	public:
		//declare constructors for the Money class - one with no arguements passed, one with only dollars passed, and one with dollars and cents passed as arguments
		Money(long dollars, int cents);
		Money(long dollars);
		Money();

		//getters-accessors --> declare const function that returns the value for all_cents
		double get_value() const;

		//declare friend functions to overload necessary operators 
		friend Money operator +(const Money& amount1, const Money& amount2);
		friend Money operator - (const Money& amount1, const Money& amount2);
		friend Money operator - (const Money& amount);
		friend bool operator == (const Money& amount1, const Money& amount2);
		friend bool operator < (const Money& amount1, const Money& amount2);
		friend istream& operator >>(istream& ins, Money& amount);
		friend ostream& operator <<(ostream& outs, const Money& amount);

	private:
		//declare the private member variables for each object of the Money class
		long all_cents;
};

//Helper function that uses static cast to convert chars to ints
int digit_to_int(char c);

//Money class - constructor definition for dollars and cents passed as arguments
Money::Money(long dollars, int cents)
{
	//exit the program if invalid entries are provided
	if (dollars * cents < 0 || cents > 100)
	{
		cout << "Illegal values for dollars and cents.\n";
		exit(1);
	}

	//otherwise set all_cents equal dollars(in cents) + cents
	all_cents = dollars * 100 + cents;
}

//Money class - constructor definition for dollars passed as an argument
Money::Money(long dollars) : all_cents(dollars * 100)
{

}

//Money class - empty constructor definition
Money::Money() : all_cents(0)
{

}

//getters-accessors --> declare const function that returns the value for private member variable all_cents *.01
double Money::get_value() const
{
	return (all_cents*0.01);
}


//Friend of the Money class - function to overload the + operator
//Returns a money object storing the sum of all_cents from amount1 and amount2
Money operator +(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.all_cents = amount1.all_cents + amount2.all_cents;
	return temp;
}

//Friend of the Money class - function to overload the - operator
//Returns a money object storing the difference of all_cents between amount1 and amount2
Money operator -(const Money& amount1, const Money& amount2)
{
	Money temp;
	temp.all_cents = amount1.all_cents - amount2.all_cents;
	return temp;
}

//Friend of the Money class - function to overload the - operator
//Returns a money object storing the negative value of all_cents from amount
Money operator - (const Money& amount)
{
	Money temp;
	temp.all_cents = -amount.all_cents;
	return temp;
}

//Friend of the Money class - function to overload the == operator
//Evaluates whether the all_cents amount of amount1 equals that of amount2
bool operator == (const Money& amount1, const Money& amount2)
{
	return (amount1.all_cents == amount2.all_cents);
}

//Friend of the Money class - function to overload the < operator
//Evaluates whether the all_cents amount of amount1 is less than that of amount2
bool operator < (const Money& amount1, const Money& amount2)
{
	return (amount1.all_cents < amount2.all_cents);
}

//Friend of the Money class - function to overload the >> operator
//Reads the user entry for the money amount
//Appends to input stream the necessary characters and dollars and cents
//Stores all_cents amount
istream& operator >>(istream& ins, Money& amount)
{
	//declare necessary char variables for potential negative sign, dollar sign and digit1 and 2
	char one_char, decimal_point, digit1, digit2;
	
	//declare long and int variables for dollars and cents
	long dollars;
	int cents;

	//create a bool flag to identify if the money entry is negative
	bool negative;

	//Append to the input stream the first char. If it is '-' it is a negative value so we update the necessary flag and read in a char again which is the $
	ins >> one_char;
	if (one_char == '-')
	{
		negative = true;
		ins >> one_char;
	}
	//otherwise set the negative flag to false
	else
	{
		negative = false;
	}

	//read in the dollars, decimal point, and the tens and ones place for the cents value
	ins >> dollars >> decimal_point >> digit1 >> digit2;

	//if there has been an illegal entry for the money amount output to the user and exit the program
	if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
	{
		cout << "Error illegal form for money input. Please ensure you are including the '$' sign\n";
		exit(1);
	}

	//calculate the cents amount based on digit 1 and 2
	cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

	//store the all_cents amount based on the dollar and cent values
	amount.all_cents = dollars * 100 + cents;

	if (negative)
	{
		amount.all_cents = -amount.all_cents;
	}
	
	//return ins
	return ins;
}


//Friend of the Money class - function to overload the << operator
//Appends to output stream the negative sign(where applicable), the dollar sign followed by the dollars amount, followed by a period, and finally the cents value
ostream& operator <<(ostream& outs, const Money& amount)
{
	//declare long variables for dollars and cents and determine the amounts to be outputted 
	long positive_cents, dollars, cents;
	positive_cents = labs(amount.all_cents);
	dollars = positive_cents / 100;
	cents = positive_cents % 100;
	
	//if negative, output will include a '-' sign
	//then output '$' dollars '.'
	if (amount.all_cents < 0)
	{
		outs << "- $" << dollars << '.';
	}
	else
	{
		outs << "$" << dollars << '.';
	}

	//append to the output the tens place and the ones place values for cents
	if (cents<10)
	{
		outs << '0';
	}
	outs << cents;

	//return outs which has had the money value formatted above appended to the stream
	return outs;
}


int digit_to_int(char c)
{
	//return the value of the static cast of the char - '0'
	return (static_cast<int> (c) - static_cast<int> ('0'));
}




//Check class definition
class Check
{
	public:
		//declare constructors for the Check class - one with no arguements passed, and the other with arguements passed
		Check();
		Check(int num, long dollar_amount, int cent_amount, bool cashed);

		//getters-accessors --> declare const functions that return the values for each private member variable of the class
		double get_money_amount() const    { return check_amount.get_value(); }
		bool get_cashed() const    { return check_cashed; }
		int get_check_number() const    { return check_number; }
		
		//setters-mutators --> declare void functions that are passed arguements to set values for the private member variables of the class
		void set_check_number(int check_num);
		void set_check_cashed(bool cashed);
		void set_money(long dollar_amt, int cent_amt);

		//declare friend functions to overload necessary operators 
		friend bool operator < (const Check& check1, const Check& check2);
		friend ostream& operator <<(ostream& output, const Check& check);
		friend istream& operator >>(istream& input, Check& check);
		
	private:
		//declare the private member variables for each object of the Check class
		int check_number;
		Money check_amount;
		bool check_cashed;
};


//Check class - empty constructor definition
Check::Check()
{
	check_number = 0;
	check_amount = Money();
	check_cashed = 0;
}


//Check class - constructor definition
Check::Check(int num, long dollar_amount, int cent_amount, bool cashed)
{
	//set object's private variables equal to the relevant arguements passed
	//ensure check numbers entered are positive
	if (num > 0)
	{
		check_number = num;
	}
	else
	{
		cout << "Illegal check number entered. Exiting Program";
		exit(1);
	}
	check_amount = Money(dollar_amount, cent_amount);
	check_cashed = cashed;
}


//Check class - mutator function definition for setting the check number
void Check::set_check_number(int check_num)
{
	//if the check number passed as an argument is positive, set check_number equal to it

	if (check_num>0)
	{
		check_number = check_num;
	}
	else
	{
		cout << "Illegal check number entered. Exiting Program";
		exit(1);
	}
}


//Check class - mutator function definition for setting the cashed status of the check
void Check::set_check_cashed(bool cashed)
{
	check_cashed = cashed;
}


//Check class - mutator function definition for setting the money amount of the check
void Check::set_money(long dollar_amt, int cent_amt)
{
	check_amount = Money(dollar_amt, cent_amt);
}

//Friend of the Check class - function to overload the < operator
//Evaluates whether the check number of check 1 is less than that of check 2
bool operator < (const Check& check1, const Check& check2)
{
	return ( check1.get_check_number() < check2.get_check_number());
}


//Friend of the Check class - function to overload the << operator
//Appends to output stream the check number and check amount, as well as if it was cashed or not
ostream& operator <<(ostream& output, const Check& check)
{
	if (check.check_cashed)
	{
		output << "Check #" << check.check_number << ":\t\t" << check.check_amount << " (cashed)." << endl;
	}
	else
	{
		output << "Check #" << check.check_number << ":\t\t" << check.check_amount << " (not cashed)." << endl;
	}

	return output;
}


//Friend of the Check class - function to overload the >> operator
//Prompts the user for the necessary information regarding the check
//Appends to input stream the check number, check amount, and cashed status
istream& operator >>(istream& input, Check& check)
{
	cout << "Enter the check number: ";
	input >> check.check_number;

	if (check.check_number <= 0)
	{
		cout << "Illegal check number entered. Exiting Program";
		exit(1);
	}

	cout << "Enter check amount: ";
	input >> check.check_amount;

	cout << "Was this check cashed? (Enter '1' if yes, '0' if no): ";
	input >> check.check_cashed;

	return input;
}


//The print_instructions function outputs to the user instructions for entering the necessary information for the program
//It is a void function so does not return any value, and it does not receive any arguments
void print_instructions();


//The print_checkbook_summary function outputs to the user a summary based on the old balance, and checks and deposits entered
//It is a void function so does not return any value
//It receives three arguements by reference: a vector storing objects of the Check class, an object of the money class storing the old balance, and a double for the total deposit amount
void print_checkbook_summary(vector<Check>& check_vec, Money& old_bal, double& total_deposit);


int main()
{
	//print instructions for the user
	print_instructions();

	//declare an object of type Money, prompt the user for a balance, and read it in to store the balance in the Money object
	Money old_balance;
	cout << "Please enter your old account balance: ";
	cin >> old_balance;
	cout << endl;

	//declare an int variable to store the check count and set it equal to 1
	int check_count = 1;

	//declare a variable of type char for determining when to complete entering checks, and a bool variable to end the while loop for processing checks
	char process_another_check;
	bool checks_continue_flag = true;

	//create a vector that will store Check objects
	vector<Check> check_vector;

	//use a while loop to iterate until the user has completed entering the desired checks
	while (checks_continue_flag)
	{
		//output the check number for count of checks that have been processed
		cout << "Check #" << check_count << endl;
		
		//create a check object and use the >> overload to read in the desired information about the check. Then push back the object in the check vector
		Check user_check;
		cin >> user_check;
		check_vector.push_back(user_check);


		//prompt the user to see if they would like to enter another check. Update checks_continue_flag where applicable and output to the user if they enter an invalid entry
		cout << "\nWould you like to add another check (y/n)? ";
		cin >> process_another_check;

		if (process_another_check == 'n')
		{
			checks_continue_flag = false;
		}
		else if (process_another_check != 'y')
		{
			cout << "Illegal entry - please ensure you only enter 'y' or 'n'. Exiting program" << endl;
			exit(1);
		}
		check_count++;
		cout << endl;
	}


	/*
	Below are several lines of code I used while testing the setter/mutator functions and constructor
	I commented it out, as it is not needed for the program to run, but left it in in case it might be useful to you 

	Check test_user_check;
	test_user_check.set_check_cashed(true);
	test_user_check.set_check_number(12);
	test_user_check.set_money(50, 60);
	check_vector.push_back(test_user_check);
	cout << test_user_check << endl;
	check_vector.push_back(Check(14, 15, 50, false));
	cout << check_vector[check_vector.size() - 1] << endl;
	*/



	cout << "You have completed the check entering portion.";
	cout<< "\n\nPlease enter your bank deposits separated by a space or entered on separate lines. Enter a deposit of '$0.00' once completed" << endl;
	
	//create a vector that will store Money objects for the deposits
	vector<Money> deposit_vector;

	//create a bool flag to know when to stop processing deposits, and a double to store the total deposit amount
	bool deposit_continue_flag = true;	
	double total_deposit_amount = 0;

	//prompt the user for deposit entries and push back the amounts to the deposit_vector
	while (deposit_continue_flag)
	{
		Money user_deposit;
		cin >> user_deposit;
		if (user_deposit.get_value() == 0)
		{
			deposit_continue_flag = false;
		}
		else
		{
			total_deposit_amount += user_deposit.get_value();
			deposit_vector.push_back(user_deposit);
		}
	}

	//sort the check vector based on the check #'s
	sort(check_vector.begin(), check_vector.end());

	//print the checkbook summary to the user based on the entries provided
	print_checkbook_summary(check_vector, old_balance, total_deposit_amount);
	
	return 0;
}

void print_instructions()
{
	//print instructions to the user
	cout << "Welcome to Ben's checkbook balancing program!\n" << endl;
	cout << "You will be prompted to enter the following:" << endl;
	cout << "1. Your old account balance" << endl;
	cout << "2. All checks that were not cashed as of the last time you balanced your checkbook" << endl;
	cout << "3. All deposits made in that timeframe" << endl;
	cout << "\n***All money amounts should be entered using standard dollar format '$DD.cc'" << endl;
	cout << "\n\nLet's begin\n\n";
}

void print_checkbook_summary(vector<Check>& check_vec, Money& old_bal, double& total_deposit)
{
	//create double variables to store the toal amount of money resulting from cashed checks and non-cashed checks
	double total_cashed_check_amount = 0, total_non_cashed_check_amount = 0;

	//create counter variables to determine if there are cashed and/or non-cashed checks to output to the user
	int cashed_count = 0, not_cashed_count = 0;

	//iterate through the vector storing all of the checks and update the total check amounts and counts based on whether it is a cashed check or not
	for (int i = 0; i < check_vec.size(); i++)
	{
		if (check_vec[i].get_cashed())
		{
			total_cashed_check_amount += check_vec[i].get_money_amount();
			cashed_count++;
		}
		else
		{
			total_non_cashed_check_amount += check_vec[i].get_money_amount();
			not_cashed_count++;
		}
	}

	//declare variables of type double to store the relevant information to output to the user
	double new_balance = old_bal.get_value() + total_deposit - total_cashed_check_amount;
	double pending_balance = new_balance - total_non_cashed_check_amount;
	double balance_difference = total_non_cashed_check_amount;


	//set precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//output to the user the summary information
	cout << endl << "=============================================" << endl;
	cout << "Account Balance Summary\n" << endl;
	cout << "Old Balance:\t\t" << old_bal << endl;
	cout << "New Balance:\t\t$" << new_balance << endl;
	cout << "Pending Balance:\t$" << pending_balance << endl;
	cout << "Balance Difference:\t$" << balance_difference << endl;
	cout << "Total Amount Cashed:\t$" << total_cashed_check_amount << endl;
	cout << "Total Amount Deposited:\t$" << total_deposit << endl;

	//output to the user the sorted listing of cashed checks and their respective amounts
	if (cashed_count > 0)
	{
		cout << "\nCashed Checks:" << endl;
		for (int i = 0; i < check_vec.size(); i++)
		{
			if (check_vec[i].get_cashed())
			{
				cout << check_vec[i];
			}
		}
	}
	//output to the user the sorted listing of non-cashed checks and their respective amounts
	if (not_cashed_count > 0)
	{
		cout << "\nUncashed Checks:" << endl;
		for (int i = 0; i < check_vec.size(); i++)
		{
			if (!check_vec[i].get_cashed())
			{
				cout << check_vec[i];
			}
		}
	}
}