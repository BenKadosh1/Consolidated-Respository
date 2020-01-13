//This code assumes the user will only enter valid responses when prompted****

#include <iostream>
#include <string>

using namespace std;

//declare and initalize variables of type double fo the different rates that can be charged
const double RATE_1 = 0.40, RATE_2 = 0.25, RATE_3 = 0.15;

int main()
{
	//declare variables for user inputs for call start time, duration, and day of the week
	int user_call_start_hour, user_call_start_minute, user_duration_of_call_in_mins;
	char colon_time_format;
	string user_day_of_the_week;


	//set precision for output
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);


	//Prompt the user to enter the time at which the call started and store it in the appropriate variables
	cout << "Please enter the time at which the call started in 24-hour notation (1:30 P.M. should be input as 13:30): ";
	cin >> user_call_start_hour >> colon_time_format >> user_call_start_minute;

	//Prompt the user to enter the day of the week for the call
	cout << "Please enter the day of the week on which the call was started in two letter format (Monday should be input as Mo): ";
	cin >> user_day_of_the_week;

	//Prompt the user to enter the duration of the call
	cout << "Please enter the duration of the call in minutes: ";
	cin >> user_duration_of_call_in_mins;

	//set precision for the output to two decimals places
	cout.precision(2);

	//nested if to determine which day of the week it is, if Mon - Fri then check the times (8am to 6 pm or before or after) to determine the applicable rates
	if (user_day_of_the_week == "Mo" || user_day_of_the_week == "Tu" || user_day_of_the_week == "We" || user_day_of_the_week == "Th" || user_day_of_the_week == "Fr")
	{
		if ((user_call_start_hour >= 8.0 && user_call_start_hour < 18.0) || (user_call_start_hour == 18.0 && user_call_start_minute == 0.0))
		{
			//output the cost of the call to the user
			cout << "The cost of the call was: $" << user_duration_of_call_in_mins * RATE_1;
		}
		else
		{
			//output the cost of the call to the user
			cout << "The cost of the call was: $" << user_duration_of_call_in_mins * RATE_2;
		}
	}
	//Saturday & Sunday
	else
	{
		//output the cost of the call to the user
		cout << "The cost of the call was: $" << user_duration_of_call_in_mins * RATE_3;
	}

	return 0;
}
