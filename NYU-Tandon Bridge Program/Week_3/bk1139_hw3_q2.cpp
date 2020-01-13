//This code assumes the user will only enter valid responses when prompted****

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//declare variables for user inputs
	string user_name;
	int user_graduation_year, user_current_year;

	//declare variables for output
	string student_status;


	//Prompt the user to enter their name, graduation year and current year
	cout << "Please enter your name: ";
	cin >> user_name;

	cout << "Please enter your graduation year: ";
	cin >> user_graduation_year;

	cout << "Please enter current year: ";
	cin >> user_current_year;


	//use if, else if, else statements to determine student status (graduated, senior, junior, sophomore, freshman or not in college yet)
	if (user_graduation_year <= user_current_year)
	{
		student_status = "you Graduated";
	}
	else if (user_graduation_year - user_current_year == 1)
	{
		student_status = "you are a Senior";
	}
	else if (user_graduation_year - user_current_year == 2)
	{
		student_status = "you are a Junior";
	}
	else if (user_graduation_year - user_current_year == 3)
	{
		student_status = "you are a Sophomore";
	}
	else if (user_graduation_year - user_current_year == 4)
	{
		student_status = "you are a Freshman";
	}
	else
	{
		student_status = "you are not in college yet";
	}

	//output student status to the user
	cout << user_name << ", " << student_status << endl;

	return 0;
}
