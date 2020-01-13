//File name: bk1139_hw8_q6.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw8_q6


//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <string>

void printMaskedString(std::string unmasked_string);
/*
  The printMaskedString function takes one arguement:
	1. A string, unmasked_string, which provides the function with a string to print the masked version of
  The printMaskedString function is a void function, therefore it does not have a return value 

  The function's purpose is to take a string and print the masked version of it

  The function iterates through each index of the string and extracts substrings based on the position of spaces
  The function then calls stringMasker on each substring and returns either that substring or a masked version of it where applicable
*/

std::string stringMasker(std::string parsed_string);
/*
  The stringMasker function takes one arguement:
	1. A string, parsed_string, which provides the function with a string to analyze for masking
  The stringMasker function returns a string

  The function's purpose is to take a string and determine whether or not it should be masked,
  and returns a masked version where applicable, otherwise it returns the original string

  The function iterates through each index of the string and determines if it is solely comprised of integers
  The function then applies masking where applicable
*/

int main()
{
	using namespace std;

	//create a string variable user_text
	string user_text;

	//prompt the user for a line of text and use getline to store the full line
	cout << "Please enter a line of text:" << endl;
	getline(cin, user_text);

	//call printMaskedString function on user_text
	printMaskedString(user_text);

	return 0;
}

void printMaskedString(std::string unmasked_string)
{
	using namespace std;

	//declare and initialize beginning and ending index positions to 0 for locations of substrings
	int beginning_index = 0, ending_index = 0;

	//create a variable to store substring length
	int substring_length;

	/*
	Iterate through each character in the unmasked string passed to the function
	Identify each word based on the position of spaces ' ' 

	Else branch --> If the character is not a space and the ending index isn't the last index, increment the ending index
	Incrementing the ending index expands the substring (word) we will assess for masking

	If branch --> If the character is a space, determine the substring length by subtracting beginning index from ending
	Call the stringMasker function on the given substring starting at beginning index and of length substring_length
	Reset the beginning index to look at the position after the space and ending index to equal beginning index

	Else if branch --> if the last index isn't a space, evaluate the last substring by calling stringMasker on that substring
	*/
	for (int i = 0; i < unmasked_string.length(); i++)
	{
		if (unmasked_string[i] == ' ')
		{
			substring_length = ending_index - beginning_index;
			cout << stringMasker(unmasked_string.substr(beginning_index, substring_length)) << " ";

			beginning_index = i + 1;
			ending_index = beginning_index;
		}
		else if (ending_index == unmasked_string.length()-1)
		{
			ending_index++;
			substring_length = ending_index - beginning_index;
			cout << stringMasker(unmasked_string.substr(beginning_index, substring_length));
		}
		else
		{
			ending_index++;
		}
	}
}

std::string stringMasker(std::string parsed_string)
{
	using namespace std;

	//declare and initialize two variables to count the alpha characters and the numeric characters in parsed_string 
	int alpha_counter = 0;
	int numeric_counter = 0;

	//declare and initialize a blank string that will store the masked_string version of parsed_string where applicable
	string masked_string = "";

	//iterate through each character in the string and analyze whether it is 0 - 9 character or not using isdigit
	for (int i = 0; i < parsed_string.length(); i++)
	{
		if (isdigit(parsed_string[i]))
		{
			numeric_counter++;
		}
		else
		{
			alpha_counter++;
		}
	}

	//if there is a letter in the string it should not be masked and we return the original string
	if (alpha_counter>0)
	{
		return parsed_string;
	}
	//if the string is comprised entirely of digits return a masked string of x's with length matching parsed_string
	else
	{
		for (int j = 0; j < parsed_string.length(); j++)
		{
			masked_string += "x";
		}
		return masked_string;
	}
}