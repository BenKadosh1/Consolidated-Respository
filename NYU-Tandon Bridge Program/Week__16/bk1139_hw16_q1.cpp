//File name: bk1139_hw16_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw16_q1


//this program assumes the compiler would not allow variables to be declared with the name "begin" or "end" 
//but does account for those words being included in variable names along with other alphanumeric and _ characters 
//https://www.tutorialspoint.com/pascal/pascal_variable_types.htm for reference on how to name variables in pascal

//inputs 7,12,13 attached as well for reference


#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

const int LENGTH_BEGIN = 5, LENGTH_END = 3;

//create templated Stack class
template<class T>
class Stack
{
	public:
		//functions to push and pop data, and access the top data item
		void push(T new_item) { data.push_front(new_item); }
		void pop() { return data.pop_front(); }
		T top() const { return *data.begin(); }

		//functions to check if the stack is empty, what its size is, and to clear the stack
		bool is_empty() const { return data.size() == 0; }
		int size() const { return data.size(); }
		void clear() { data.clear(); }

	private:
		//create an STL list of type T to store the data
		list<T> data;
};

//void function that recieves an ifstream object by reference
//the function runs to open a file and iterates until it does so successfully 
void open_input_file(ifstream& input_file);

//symbol_balance_checker recieves an ifstream object by reference
//it reads in the contents of the file and parses it by line
//it identifies symbols {, [, (, and begin and sends them to the stack
//when }, ], ), and end are encountered they are compared to the top of the stack to check whether the symbols are balanced
bool symbol_balance_checker(ifstream& input_file);

int main()
{
	//create an ifsteam object, and call the open input file while passing the input file
	ifstream input_file;
	open_input_file(input_file);

	//create a bool variable that is set to the return value from the symbol balance checker function for the file
	bool balanced = symbol_balance_checker(input_file);

	//close the input file once we have read in all of the information
	input_file.close();

	//output to the user whether or not the file has all of its symbols balanced
	if (balanced)
	{
		cout << "\nThe test file entered has its symbols balanced" << endl;
	}
	else
	{
		cout << "\nThe test file entered does not have its symbols balanced" << endl;
	}

	return 0;
}

bool symbol_balance_checker(ifstream& input_file)
{
	//create a stack that will store strings
	Stack<string> symbol_stack;

	//create two strings - one to read in a line from the input file, and the other to store the strings we will push to the stack
	string temp_string, push_string;

	//declare a bool variable for symbol match and set it equal to true
	bool symbol_match = true;

	//create a count variable to check that the file starts with begin
	bool pushed_begin = false;

	//while the continue flag is true and there is more to read from the input file continuie
	while (getline(input_file, temp_string))
	{
		cout << temp_string << endl;

		//iterate through each character of the given line of text
		for (int i = 0; i < temp_string.length(); i++)
		{
			//check if there are any opening bracket-type symbols - if yes push the symbol to the stack and reset the push string
			if (temp_string[i] == '{' || temp_string[i] == '(' || temp_string[i] == '[')
			{
				//ensure the first push is begin and not an opening symbol
				if (!pushed_begin)
				{
					symbol_match = false;
				}
				push_string = temp_string[i];
				symbol_stack.push(push_string);
				push_string = "";
			}
			//else if check if there are closing bracket-type symbols. If there are compare to the top of the stack to see if the complementary symbol is there
			//if it isn't set the symbol match bool to false, otherwise pop the top of the stack and reset the push string
			else if (temp_string[i] == '}' || temp_string[i] == ')' || temp_string[i] == ']')
			{
				if (symbol_stack.size() == 0)
				{
					symbol_match = false;
				}
				else
				{
					if ((symbol_stack.top() != "{" && temp_string[i] == '}') || (symbol_stack.top() != "(" && temp_string[i] == ')') || (symbol_stack.top() != "[" && temp_string[i] == ']'))
					{
						symbol_match = false;
					}
					else
					{
						symbol_stack.pop();
					}
					push_string = "";
				}
			}

			//else if check if the character is any of the letters in begin or end. if it isn't reset the push string
			else if (tolower(temp_string[i]) == 'b' || tolower(temp_string[i]) == 'e' || tolower(temp_string[i]) == 'g' || tolower(temp_string[i]) == 'i' || tolower(temp_string[i]) == 'n' || tolower(temp_string[i]) == 'd')
			{
				push_string += tolower(temp_string[i]);

				//check if the current push string is of length 3 and equals end or beg if not disregard it
				if (push_string.length() == LENGTH_END)
				{
					if (push_string != "beg" && push_string != "end")
					{
						push_string = "";
					}
					//if it equals end
					else if (push_string == "end")
					{
						//check if there is anything before or after it
						if (temp_string.length() == LENGTH_END)
						{
							if (symbol_stack.size() == 0)
							{
								symbol_match = false;
							}
							else
							{
								//if it is the keyword compare it to the top of the stack if they match pop it, otherwise set the symbol match to false
								if (symbol_stack.top() == "begin")
								{
									symbol_stack.pop();
									push_string = "";
								}
								else
								{
									symbol_match = false;
								}
							}	
						}
						//else there is something else in the line. check if it is a space, tab or other characters
						else
						{
							//if it is at the end of the line check what comes before end in the lin
							if (i == temp_string.length())
							{
								if (isalnum(temp_string[i - LENGTH_END]) || temp_string[i - LENGTH_END] == '_')
								{
									push_string = "";
								}
								else
								{
									if (symbol_stack.size() == 0)
									{
										symbol_match = false;
									}
									else
									{
										//if the end keyword is found compare it to the top of the stack
										if (symbol_stack.top() == "begin")
										{
											symbol_stack.pop();
											push_string = "";
										}
										else
										{
											symbol_match = false;
										}
									}	
								}
							}
							//if it is somewhere in the middle, check the characters to the right and left of the key word to see if there are additional characters
							//indicating to disregard the word in question
							else if (i >= LENGTH_END)
							{
								if (isalnum(temp_string[i - LENGTH_END]) || temp_string[i - LENGTH_END] == '_' || isalnum(temp_string[i + 1]) || temp_string[i + 1] == '_')
								{
									push_string = "";
								}
								else
								{
									if (symbol_stack.size() == 0)
									{
										symbol_match = false;
									}
									else
									{
										if (symbol_stack.top() == "begin")
										{
											symbol_stack.pop();
											push_string = "";
										}
										else
										{
											symbol_match = false;
										}
									}
									
								}
							}
							//else it is at the beginning of the line and check what follows it
							else
							{
								if (isalnum(temp_string[i + 1]) || temp_string[i + 1] == '_')
								{
									push_string = "";
								}
								else
								{
									if (symbol_stack.size() == 0)
									{
										symbol_match = false;
									}
									else
									{
										if (symbol_stack.top() == "begin")
										{
											symbol_stack.pop();
											push_string = "";
										}
										else
										{
											symbol_match = false;
										}
									}
								}
							}
						}
					}
				}
				//the same approach as above is applied for begin as end
				//we look to see if the line's length matches or exceeds that of begin and then compare the relevant poisitions before or after it
				//we want to avoid picking up begin_x as a begin keyword but if there is a tab and then begin that is something to add to the stack
				else if (push_string.length() == LENGTH_BEGIN)
				{
					if (push_string != "begin")
					{
						push_string = "";
					}
					else
					{
						//check if there is anything before or after it
						if (temp_string.length() == LENGTH_BEGIN)
						{
							symbol_stack.push(push_string);
							push_string = "";
							pushed_begin = true;
						}
						else
						{
							if (i == temp_string.length())
							{

								if (isalnum(temp_string[i - LENGTH_BEGIN]) || temp_string[i - LENGTH_BEGIN] == '_')
								{
									push_string = "";
								}
								else
								{
									symbol_stack.push(push_string);
									push_string = "";
									pushed_begin = true;
								}
							}
							else if (i >= LENGTH_BEGIN)
							{
								if (isalnum(temp_string[i - LENGTH_BEGIN]) || temp_string[i - LENGTH_BEGIN] == '_' || isalnum(temp_string[i + 1]) || temp_string[i + 1] == '_')
								{
									push_string = "";
								}
								else
								{
									symbol_stack.push(push_string);
									push_string = "";
									pushed_begin = true;
								}
							}
							else
							{

								if (isalnum(temp_string[i + 1]) || temp_string[i + 1] == '_')
								{
									push_string = "";
								}
								else
								{
									symbol_stack.push(push_string);
									push_string = "";
									pushed_begin = true;
								}
							}
						}
					}
				}
			}
			else
			{
				push_string = "";
			}
		}
	}

	//check that there are no remaining symbols on the stack. If there are then there wasn't a full balance and set the flag to false
	if (symbol_stack.size() > 0)
	{
		symbol_match = false;
	}

	return symbol_match;
}


void open_input_file(ifstream& input_file)
{
	//create a string to store the filename and prompt the user to enter the file name
	string file_name;
	cout << "Please enter the filename for file which you wish to open: ";
	cin >> file_name;

	//call the open function on the input file
	input_file.open(file_name);
	while (!input_file)
	{
		//if the file was not opened successfully, prompt the user to enter the file name again and clear the necesssary flags before attempting to open again
		cout << "The file was not opened successfully" << endl;
		cout << "Please enter the filename which you wish to open: ";
		cin >> file_name;
		input_file.clear();
		input_file.open(file_name);
	}

	cout << "\nThe contents of the file are printed below:" << endl;
}