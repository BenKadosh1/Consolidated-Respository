//File name: bk1139_hw7_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw7_q1


//This code assumes the user will provide valid entries when prompted

#include <iostream>

//Declare and initialize const ints to store days in a week and months in a year
const int DAYS_IN_A_WEEK = 7;
const int MONTHS_IN_A_YEAR = 12;

//Declare and initialize const ints to store the number of days in each month of the year
const int DAYS_IN_JAN = 31, DAYS_IN_FEB = 28, DAYS_IN_MAR = 31, DAYS_IN_APR = 30, DAYS_IN_MAY = 31, DAYS_IN_JUN = 30;
const int DAYS_IN_JUL = 31, DAYS_IN_AUG = 31, DAYS_IN_SEPT = 30, DAYS_IN_OCT = 31, DAYS_IN_NOV = 30, DAYS_IN_DEC = 31;


void printYearCalendar(int year, int startingDay);
/*
  The printYearCalendar function takes two arguements:
	1. An int, year, which will dictate whether or not it is a leap year and the format of the calendar that is output to the user
	2. An int, startingDay, which will dictate which day of the week the calendar starts on in week of Jan 1
  The printYearCalendar function is a void function, so it does not have a return value

  The function's purpose is to print out a monthly calendar for a given year and start day

  The function first determines whether or not the year inputted by the user is a leap year
  The function then iterates from month = 1 to the number of months in a year (12)
  During each iteration there is a switch mechanism in place to direct the function to the right case for the current month
  Each case will call the printMonthCalendar function to print the calendar for that month and set the start date for the next month
*/

int printMonthCalendar(int numOfDays, int startingDay);
/*
  The printMonthCalendar function takes two arguements:
	1. An int, numOfDays, which tells the function how many days are in the month to be printed
	2. An int, startingDay, which will dictate which day of the week the calendar starts
  The printMonthCalendar function returns an int, which is the day of the week on the last day of the month

  The function's purpose is to print out a calendar for a given month

  The function first initializes the necessary counter variables for day of the month and day of the week
  The function then calculates the number of weeks in that given month based on the # of days and the starting day of the week
  The function will then iterate using a nested for loop through each week and each day within each week to either output the day of the week or a tab where n/a
  During each iteration there are branching statements to increment counters where applicable
*/

int main()
{
	using namespace std;

	//declare to variables of type int for year and starting day to store user values
	int year, starting_day;

	//Prompt the user for a positive integer for the year and an integer between 1-7 for the starting day of the week
	//store the results in year and starting day respectively
	cout << "Please enter a positive integer that represents a year: ";
	cin >> year;

	cout << "Please enter an integer from 1-7 that represents the day in the week of Jan 1 of the year entered above: ";
	cin >> starting_day;
	cout << endl;

	//call the printYearCalendar function with the user provided inputs
	printYearCalendar(year, starting_day);
	
	return 0;
}

void printYearCalendar(int year, int startingDay)
{
	using namespace std;

	//declare a bool variable for is leap year and set it to false
	bool is_leap_year = false;

	//if the year is divisible by 4 and not divisible by 100 or divisible by 4, 100, and 400 it is a leap year
	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
	{
		is_leap_year = true;
	} 

	//iterate through each month of the year
	for (int month = 1; month <= MONTHS_IN_A_YEAR; month++)
	{
		//use a switch statement with a case for each month, where it outputs the month and year and then calls printMonthCalendar
		//February has a branching statement to handle whether or not it is a leap year
		//set starting day = to the return value of PrintMonthCalendar mod days in the week + 1
		switch (month)
		{
			case 1:
				cout << "January " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_JAN, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 2:
				cout << "February " << year << endl;
				if (is_leap_year)
				{
					startingDay = printMonthCalendar(DAYS_IN_FEB + 1, startingDay) % DAYS_IN_A_WEEK + 1;
				}
				else
				{
					startingDay = printMonthCalendar(DAYS_IN_FEB, startingDay) % DAYS_IN_A_WEEK + 1;
				}
				break;
			case 3:
				cout << "March " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_MAR, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 4:
				cout << "April " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_APR, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 5:
				cout << "May " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_MAY, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 6:
				cout << "June " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_JUN, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 7:
				cout << "July " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_JUL, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 8:
				cout << "August " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_AUG, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 9:
				cout << "September " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_SEPT, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 10:
				cout << "October " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_OCT, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 11:
				cout << "November " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_NOV, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			case 12:
				cout << "December " << year << endl;
				startingDay = printMonthCalendar(DAYS_IN_DEC, startingDay) % DAYS_IN_A_WEEK + 1;
				break;
			default:
				break;
		}
		cout << endl;
	}
}

int printMonthCalendar(int numOfDays, int startingDay)
{
	using namespace std;

	//set day of the week counter to starting day and day of the month counter to 1
	int day_of_the_week_counter = startingDay;
	int day_of_the_month_counter = 1;

	//determine the number of weeks in the month based on the days in the month and starting day of the week
	int row_count;
	if ((numOfDays + startingDay - 1) % DAYS_IN_A_WEEK == 0)
	{
		row_count = (numOfDays + startingDay - 1) / DAYS_IN_A_WEEK;
	}
	else
	{
		row_count = ((numOfDays + startingDay - 1) / DAYS_IN_A_WEEK) + 1;
	}

	//output header line with the days' names
	cout << "Mon" << "\tTue" << "\tWed" << "\tThr" << "\tFri" << "\tSat" << "\tSun" << endl;

	//iterate through each week and within each week through each day of the week
	for (int row = 1; row <= row_count; row++)
	{
		for (int column = 1; column <= DAYS_IN_A_WEEK; column++)
		{
			//if the day of the week is before the starting day of the week for that month output tabs
			//if the day of the week is after the last day of the month output tabs
			if (column < day_of_the_week_counter || day_of_the_month_counter > numOfDays)
			{
				cout << "\t";
			}
			//else output the day of the month, and then increment the day of the month and day of the week
			else
			{
				cout << day_of_the_month_counter << "\t";
				day_of_the_month_counter++;
				day_of_the_week_counter++;
			}
		}
		cout << endl;
		//if the day of the month incremented past the num of days reduce the day of the week counter by one
		if (day_of_the_month_counter > numOfDays)
		{
			day_of_the_week_counter--;
		}
		//else reset the day of the week counter to 1 before starting to iterate through the next week
		else
		{
			day_of_the_week_counter = 1;
		}
	}
	//return the day of the week
	return day_of_the_week_counter;
}