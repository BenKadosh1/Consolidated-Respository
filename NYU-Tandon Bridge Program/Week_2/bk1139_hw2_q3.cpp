//This code assumes the user will only enter valid integers when prompted****
//This code does not format output to distinguish cases where minutes and/or hours = 1 from plural to singular****

#include <iostream>

using namespace std;

//declare and initialize constant variables of type double with amounts for each respective coin
const int HOURS_IN_A_DAY = 24, MINUTES_IN_AN_HOUR = 60;

int main()
{
	//declare variables of type int for number of days, hours, and minutes worked by John and Bill
	int john_num_days_worked, john_num_hours_worked, john_num_minutes_worked, bill_num_days_worked, bill_num_hours_worked, bill_num_minutes_worked;
	
	//declare variables of type int for number of days, hours, and minutes worked  in total by John and Bill
	int total_num_days_worked, total_num_hours_worked, total_num_minutes_worked;

	//declare variables for any carryover from one unit of time to another (e.g 70 minutes = 1 hour and 10 minutes)
	int total_mins_to_hours_carryover, total_hours_to_days_carryover;

	//Prompt the user to enter the days, hours, and minutes worked by John and Bill
	cout << "Please enter the number of days John has worked: ";
	cin >> john_num_days_worked;

	cout << "Please enter the number of hours John has worked: ";
	cin >> john_num_hours_worked;

	cout << "Please enter the number of minutes John has worked: ";
	cin >> john_num_minutes_worked;


	cout << "\nPlease enter the number of days Bill has worked: ";
	cin >> bill_num_days_worked;

	cout << "Please enter the number of hours Bill has worked: ";
	cin >> bill_num_hours_worked;

	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> bill_num_minutes_worked;

	//determine the total number of minutes worked and whether or not there were enough minutes to consitute an hour to carryover
	total_num_minutes_worked = (john_num_minutes_worked + bill_num_minutes_worked) % MINUTES_IN_AN_HOUR;
	total_mins_to_hours_carryover = (john_num_minutes_worked + bill_num_minutes_worked) / MINUTES_IN_AN_HOUR;

	//determine the total number of hours worked and whether or not there were enough hours to consitute a day to carryover
	total_num_hours_worked = (total_mins_to_hours_carryover + john_num_hours_worked + bill_num_hours_worked) % HOURS_IN_A_DAY;
	total_hours_to_days_carryover = (total_mins_to_hours_carryover + john_num_hours_worked + bill_num_hours_worked) / HOURS_IN_A_DAY;

	//determine the total number of days worked
	total_num_days_worked = total_hours_to_days_carryover + john_num_days_worked + bill_num_days_worked;

	//output the result to the user
	cout << "\nThe total time both of them worked together is: " << total_num_days_worked << " days, " << total_num_hours_worked << " hours and " << total_num_minutes_worked << " minutes." << endl;

	return 0;
}
