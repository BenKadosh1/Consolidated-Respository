//File name: bk1139_hw8_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw8_q2


//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <string>

using namespace std;

string lowerCaseConverter(string original_string);
/*
  The lowerCaseConverter function takes one arguement:
	1. A string, original_string, which contains a user entered string
  The lowerCaseConverter function returns a string

  The function's purpose is to convert any uppercase letters in a word to lowercase

  The function iterates through the characters in the string and converts each to lowercase
*/

bool isPalindrome(string str);
/*
  The isPalindrome function takes one arguement:
	1. A string, str, which contains a lower case version of the user entered string
  The isPalindrome function returns a bool to signal whether str is a palindrome or not

  The function's purpose is to determine whether a given string is a palindrome or not

  The function iterates from the end of the string to the front and appends each character to palindrome_compare
  The function compares the lower case version of the string entered by the user to palindrome_compare to see if the string is a palindrome
*/

int main()
{
	//declare a variable of type string called user_str to store the user entered string, 
	//and lower_case_str for an all lower case version of the string
	string user_str, lower_case_str;

	//Prompt the user for a word and store it in user_str
	cout << "Please enter a word: ";
	cin >> user_str;

	//call the lowerCaseConverter function with the user entered string to find the all lower case version
	lower_case_str = lowerCaseConverter(user_str);

	//pass lower_case_str to isPalindrome to determine if it is true or false that it is a palindrome
	//if-else to output the result to the user
	if (isPalindrome(lower_case_str))
	{
		cout << user_str << " is a palindrome";
	}
	else
	{
		cout << user_str << " is not a palindrome";
	}

	return 0;
}

string lowerCaseConverter(string original_string)
{
	//create an empty string called lower_case_str
	string lower_case_str = "";

	//iterate through each character in the string and convert it to it's lowercase form
	for (int i = 0; i < original_string.length(); i++)
	{
		lower_case_str += tolower(original_string[i]);
	}
	return lower_case_str;
}

bool isPalindrome(string str)
{
	//create an empty string called palindrome_compare
	string palindrome_compare = "";

	//iterate through each character in the string from end to beginning and 
	//append the character to palindrome_compare
	for (int i = str.length() - 1; i >= 0; i--)
	{
		palindrome_compare += str[i];
	}
	
	//compare the user entered word str to palindrome_compare
	//return true or false if the strings match/don't match respectively
	if (str == palindrome_compare)
	{
		return true;
	}
	else
	{
		return false;
	}
}