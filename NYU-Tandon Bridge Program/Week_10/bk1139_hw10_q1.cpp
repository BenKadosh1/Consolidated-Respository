//File name: bk1139_hw10_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw10_q1

#include <string>
#include <iostream>


using namespace std;

//define string* type to str_ptr
typedef string* str_ptr;

bool check_not_empty(string str);
/*
  The check_not_empty function takes one argument:
	1. A string, str, which is a line of text entered by the user
  The check_not_empty function returns a bool

  The function's purpose is to iterate through a line of text, and determine whether or not it is empty
*/

string* createWordsArray(string sentence, int& outWordsArrSize);
/*
  The createWordsArray function takes two arguments:
	1. A string, sentence, which is a line of text where words are delimitted by single spaces
	2. An int&, outWordsArrSize, which is the address of the int variable storing the size of the return array
  The createWordsArray function returns a pointer to a string which is the address of the string array

  The function's purpose is to iterate through a line of text, parse it into words, and store each word in a new index in a new array
*/

void print_words_array(string arr[], int arr_size);
/*
  The print_words_array function takes two arguments:
	1. A string array, arr, which is an array storing each word from a line of text
	2. An int, arr_size, which is the size of the array storing the words
  The print_words_array function is a void function, and therefore does not have a return value

  The function's purpose is to iterate through a string array and print its contents
*/

int main()
{
	//declare a variable, user_sentence, of type string which will store the user entry
	string user_sentence;
	
	//Prompt the user for a sentence and store it in user_sentence
	cout << "Please enter a sentence:" << endl;
	getline(cin, user_sentence);

	//check if the user string is empty or only spaces
	if (!check_not_empty(user_sentence))
	{
		cout << "You have entered an empty string or only spaces, therefore there are no words to store and no array has been created." << endl;
	}
	//if the user has entered a valid entry, proceed with creating an array to store the words entered
	else
	{
		//declare a variable, num_words, of type int which will store the numbers of words in the text entered by the user
		int num_words;

		//declare a string pointer and set it equal to the return value from the createWordsArray function
		//the return value will be a pointer to the array that was created
		str_ptr array_of_words = createWordsArray(user_sentence, num_words);

		//print the words stored in the new array to the user
		print_words_array(array_of_words, num_words);

		//free up the allocated memory on the heap that is no longer needed
		delete[] array_of_words;
	}
	return 0;
}

bool check_not_empty(string str)
{
	//initialize a bool to false for not empty
	bool not_empty = false;

	//iterate through the user entered string and if a value other than space is found then we return that the string is not empty (true)
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			not_empty = true;
		}
	}
	return not_empty;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
	//initialize the size of the dynamic array to 1
	int size = 1;

	//create a string pointer to a dynamic array that will store the words from the user text
	str_ptr sentence_arr_ptr = new string[size];

	//initialize a variable word_index which is the actual size of the array
	int word_index = 0;

	//additional functionality built to account for potential space padding to the left and right prior to letters appearing
	//the code assumes words are separated by single spaces but accounts for multiple spaces before and after words are entered
	//declare a bool to true for left padding, and a space counter to 0 for where multiple spaces are found to the right
	bool left_padding = true;
	int space_counter = 0;


	//iterate through the length of the string index by index and evaluate its contents
	for (int i = 0; i < sentence.length(); i++)
	{
		//if the array is at capacity, we double the capacity to create more room in theta(n)
		//we create a temp array with the new capacity and copy the old contents to the larger array
		//we then free up the heap memory occupied by the smaller array and set the pointer to the new temp array
		if (word_index == size)
		{
			str_ptr temp_arr_ptr = new string[size * 2];
			for (int j = 0; j < size; j++)
			{
				temp_arr_ptr[j] = sentence_arr_ptr[j];
			}
			delete[] sentence_arr_ptr;
			sentence_arr_ptr = temp_arr_ptr;
			size *= 2;
		}

		//if there is left padding continue and iterate to the next char
		if (sentence[i] == ' ' && left_padding)
		{
			continue;
		}
		//otherwise set left padding to false
		else
		{
			left_padding = false;
		}

		//for right padding - check if the number of spaces is greater than 1 meaning that there are consecutive spaces and we have hit right padding
		if (space_counter > 1)
		{
			continue;
		}
		//otherwise, we are either looking at letters or the spaces separating the words
		else
		{
			//if the current char is not a space append it to the string at current word index
			if (sentence[i] != ' ')
			{
				sentence_arr_ptr[word_index] += sentence[i];
				space_counter = 0;
			}
			//otherwise increment word index and space counter
			else
			{
				word_index++;
				space_counter++;
			}
		}
	}

	//if space counter is greater than 1 we reduce the number of words by 1 as we overstepped with spaces to the right
	if (space_counter > 1)
	{
		word_index--;
	}
	//otherwise we increase the word index by 1 to ensure the last word is included as well when not followed by a space
	else
	{
		word_index++;
	}

	//set outWordsArrSize to the number of words (word_index)
	outWordsArrSize = word_index;

	//return the pointer to the string array storing the words
	return sentence_arr_ptr;
}

void print_words_array(string arr[], int arr_size)
{
	//output to the user the words stored in each index of the new array
	cout << "\nIn order to store the words in the sentence you entered, an array of size " << arr_size << " was created." << endl;
	cout << "Below is a print out of the words stored in each index of the array:" << endl;
	cout << "[";

	//iterate through the array and print each word out separated by a comma where applicable
	for (int i = 0; i < arr_size; i++)
	{
		if (i != arr_size-1)
		{
			cout << "\"" << arr[i] << "\"" << ", ";
		}
		else
		{
			cout << "\"" << arr[i] << "\"";
		}
	}
	cout << "]" << endl;
}