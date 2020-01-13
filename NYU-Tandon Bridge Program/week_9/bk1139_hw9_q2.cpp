//File name: bk1139_hw9_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw9_q2

//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <string>	

//declare int const values for the alphabet size and the ascii value for the letter a
int const ALPHABET_SIZE = 26;
int const A_ASCII_VALUE = 97;


std::string lower_case_converter(std::string original_str);
/*
  The lower_case_converter function takes one arguement:
	1. A string, original_str, which is a user entered string
  The lower_case_converter function returns a string

  The function's purpose is to convert any uppercase letters in a word to lowercase

  The function iterates through the characters in the string and converts each to lowercase
*/

void letter_counter(std::string text, int arr[], bool& empty);
/*
  The letter_counter function takes three arguements:
	1. A string, text, which will be evaluated at each index to update letter count
	2. An array of integers, arr, which is the array tracking the count of each letter in text
	3. A bool, empty, which is set to true, and if a letter is found reset to false. This is our way to validate that the string isn't empty

  The letter_counter function is a void function, and therefore does not have a return value

  The function's purpose is iterate through the string to evaluate the count of each letter in the string
*/
bool anagram_validator(int arr1[], int arr2[], int length);
/*
  The anagram_validator function takes three arguements:
	1. An array of integers, arr1, which is the array tracking the count of each letter in the first string
	2. An array of integers, arr2, which is the array tracking the count of each letter in the second string
	3. An integer, length, which is the length of arr1 and arr2

  The anagram_validator function returns a bool to signify whether or not the two strings are anagrams

  The function iterates through each index of arr1 and arr2 and compares the value of both at each respective index
  if they differ at any point the bool flag is flipped to false
*/


int main()
{
	using namespace std;

	//declare variables of type string, to store two user entered strings and two strings to store the lower case conversions of each
	string user_string_1, user_string_2;
	string lower_case_string_1, lower_case_string_2;

	//Propmt the user for a first and second string and store them in user_string_1 and user_string_2 respectively
	cout << "Please enter the first string: ";
	getline(cin,user_string_1);
	cout << "Please enter the second string: ";
	getline(cin, user_string_2);

	//pass user_string_1 and user_string_2 to the lower case converter function
	//set lower_case_string_1 and lower_case_string_2 respectively to the returned values from the functions
	lower_case_string_1 = lower_case_converter(user_string_1);
	lower_case_string_2 = lower_case_converter(user_string_2);

	//declare and initalize two int arrays of alphabet size to 0
	//each index represents the count for a given letter in the alphabet from a-z
	int string_1_letter_counter[ALPHABET_SIZE] = { 0 };
	int string_2_letter_counter[ALPHABET_SIZE] = { 0 };

	bool is_empty_1 = true;
	bool is_empty_2 = true;

	//pass the lower case version of each string and the array storing the letter count for each to the letter_counter function
	letter_counter(lower_case_string_1, string_1_letter_counter, is_empty_1);
	letter_counter(lower_case_string_2, string_2_letter_counter, is_empty_2);

	//if both strings don't contain letters output to the user
	if (is_empty_1 && is_empty_2)
	{
		cout << "You entered two strings with no letters. Therefore, the strings can't be evaluated to determine if they are anagrams. Please try again." << endl;
	}
	//else check if they are anagrams
	else
	{
		//pass the two arrays containing the letter count and the size of both to the anagram validator
		//output the results to the user
		if (anagram_validator(string_1_letter_counter, string_2_letter_counter, ALPHABET_SIZE))
		{
			cout << '"' << user_string_1 << '"' << " and " << '"' << user_string_2 << '"' << " are anagrams";
		}
		else
		{
			cout << '"' << user_string_1 << '"' << " and " << '"' << user_string_2 << '"' << " are not anagrams";
		}
	}
	
	return 0; 
}

std::string lower_case_converter(std::string original_str)
{
	using namespace std;

	//create a blank string to store the lower case text
	string lower_case_text = "";

	//iterate through the string and append each char after it has been converted to lowercase
	for (int i = 0; i < original_str.length(); i++)
	{
		lower_case_text += tolower(original_str[i]);
	}
	//return the converted string
	return lower_case_text;
}

void letter_counter(std::string text, int arr[], bool& empty)
{
	using namespace std;
	//declare a variable of type int to determine which index in the array should be incremented
	int letter_index;

	//iterate through each index of text
	for (int i = 0; i < text.length(); i++)
	{
		//if the letter isalpha
		if (isalpha(text[i]))
		{
			//set letter index to the int conversion of the lowercase letter minus the ascii value to determine its index from 0 - 25
			letter_index = (int)text[i] - A_ASCII_VALUE;

			//increment the counter in the array at letter_index
			arr[letter_index]++;

			//update the bool to signify a letter has been found and the string isn't empty
			empty = false;
		}
	}
}

bool anagram_validator(int arr1[], int arr2[], int length)
{
	//declare a variable anagram, of type bool, and set it to true
	bool anagram = true; 

	//iterate through each index of arr1 and arr2 and compare the values in each. If they differ set anagram to false.
	for (int i = 0; i < length; i++)
	{
		if (arr1[i] != arr2[i])
		{
			anagram = false;
		}
	}
	//return whether the strings are anagrams or not
	return anagram;
}