//File name: bk1139_hw8_q5.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw8_q5


//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	//declare three variables of type string to store the user's first, middle and last names
	string first_name, middle_initial, last_name;

	//Prompt the user to enter their full name and store it in the respective string variables
	cout << "Please enter your full name in the following order separated by spaces \nFirst Name, Middle Name or Initial, Last Name:" << endl;
	cin >> first_name >> middle_initial >> last_name;

	//Output to the user last name, followed by first name and the first index in the middle initial along with a period
	cout << last_name << ", " << first_name << " " << middle_initial[0] << "." << endl;
	return 0;
}
