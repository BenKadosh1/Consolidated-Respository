//File name: bk1139_hw9_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw9_q1


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

int text_parser_and_counter(std::string unparsed_text, int arr[]);
/*
  The text_parser_and_counter function takes two arguements:
	1. A string, unparsed_text, which will be evaluated and parsed into substrings
	2. An array of integers, arr, which is the array tracking the count of each letter in the unparsed string

  The text_parser_and_counter function returns an int with the number of words in unparsed_text

  The function's purpose is to parse the string to identify number of words and call the letter_counter 
  function to evaluate the count of each letter in the string 

  The function iterates through the characters in the string and identifies substrings to evaluate
*/

void letter_counter(std::string word, int arr[]);
/*
  The letter_counter function takes two arguements:
	1. A string, word, which will be evaluated at each index to update letter count
	2. An array of integers, arr, which is the array tracking the count of each letter in the unparsed string

  The letter_counter function is a void function, and therefore does not have a return value

  The function's purpose is to parse the string to identify number of words and call the letter_counter
  function to evaluate the count of each letter in the string

  The function iterates through the characters in the string and identifies substrings to evaluate
*/
void print_num_words_and_letters(int arr[], int length, int num_words);
/*
  The print_num_words_and_letters function takes three arguements:
	1. An array of integers, arr, which will be evaluated at each index to see if the count is greater than 0
	2. An integer, length, which contains the length of the array arr
	3. An integer, num_words, for the number of words in the user_text

  The print_num_words_and_letters function is a void function, and therefore does not have a return value

  The function's purpose is to print our to the user the number of words and count of each letter used in the text 

  The function iterates through the array to identify where the count is greater than 0 for each letter and then outputs it 
*/


int main()
{
	using namespace std;

	//declare two variables to store the user text and the lower case version of the user text
	string user_text, lower_case_text;

	//Prompt the user for a line of text and store it in user_text
	cout << "Please enter a line of text:" << endl;
	getline(cin, user_text);

	//convert the user_text to lower case and store it lower_case_text
	lower_case_text = lower_case_converter(user_text);

	//declare and initialize an array of alphabet size to 0
	int letter_counter[ALPHABET_SIZE] = { 0 };

	//pass lower_case_text and the letter_counter array to the text_parser_and_counter function
	//this will return the number of words in the user_text and call the letter counter function to analyze each letter in the text
	int word_count = text_parser_and_counter(lower_case_text, letter_counter);

	//call the print_num_words_and_letters function to print the results to the user
	print_num_words_and_letters(letter_counter, ALPHABET_SIZE, word_count);
	
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
	return lower_case_text;
}

int text_parser_and_counter(std::string unparsed_text, int arr[])
{
	using namespace std;

	//declare and initialize variables for the beginning index and length of each subtring, as well as the number of words to 0
	int beginning_index = 0, length = 0, num_words = 0;

	//iterate through the unparsed text at each index
	for (int i = 0; i < unparsed_text.length(); i++)
	{
		//if punctuation has been hit it is possible that a new word has been hit
		if (unparsed_text[i] == ' '|| unparsed_text[i] == ',' || unparsed_text[i] == '.')
		{
			//if the length of the substring is greater than zero then we have encountered at least one letter
			if (length > 0)
			{
				//pass the substring to the letter counter to update the array storing the count of each letter
				letter_counter(unparsed_text.substr(beginning_index, length + 1), arr);

				//increment num_words
				num_words++;
			}

			//reset the beginning index and length for the next substring
			beginning_index += length + 1;
			length = 0;
		}
		//if the last character in the string is a letter and not a space comma or period
		else if (i == unparsed_text.length() - 1)
		{
			//increment length to capture the last letter as well
			length++;

			//pass the substring to the letter counter to update the array storing the count of each letter
			letter_counter(unparsed_text.substr(beginning_index, length), arr);

			//increment num_words
			num_words++;
		}
		else
		{
			//if it is a letter and not the end of the string increment length
			length++;
		}
	}
	return num_words;
}

void letter_counter(std::string word, int arr[])
{
	using namespace std; 

	//declare a variable of type int to determine which index in the array should be incremented
	int letter_index;

	//iterate through each index of the word
	for (int i = 0; i < word.length(); i++)
	{
		//if the letter isalpha
		if (isalpha(word[i]))
		{
			//set letter index to the int conversion of the lowercase letter minus the ascii value to determine its index from 0 - 25
			letter_index = (int)word[i] - A_ASCII_VALUE;

			//increment the counter in the array at letter_index
			arr[letter_index]++;
		}
	}
}

void print_num_words_and_letters(int arr[], int length, int num_words)
{
	using namespace std;
	//output the number of words to the user
	cout << num_words << "\twords" << endl;

	//iterate through the alphabet array and if a letter count is greater than 0 output it to the user
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > 0)
		{
			cout << arr[i] << "\t" << (char)(i+A_ASCII_VALUE) << endl;
		}
	}
}
