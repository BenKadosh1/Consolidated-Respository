//File name: bk1139_hw6_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw6_q2



//This code assumes the user will provide valid entries when prompted

#include <iostream>

void printPineTree(int n, char symbol);
/*
  The printPineTree function takes two arguements
	1. An int, n, which sets the number of triangles printed in a sequence
	2. A char, symbol, which sets the symbol that will fill the triangles that are printed
  The printPineTree function is a void function so it returns no value

  The function iterates from 1 to n and determines the number of lines and padding spaces each triangle should have
  The function then calls printShiftedTriangle during each iteration to print the shifted triangles 
*/

void printShiftedTriangle(int n, int m, char symbol);
/*
  The printShiftedTriangle function takes three arguements
	1. An int, n, which sets the number of lines in the triangle
	2. An int, m, which sets the number of padding spaces in the triangle
	3. A char, symbol, which sets the symbol that will fill the triangle being printed
  The printShiftedTriangle function is a void function so it returns no value

  The function iterates from 1 to n for each line in the triangle
  Within the above for loop, there are two additional loops that iterate through each column index first to print
  padded spaces and then to print spaces or symbol to output the desired triangle
*/


int main()
{
	using namespace std;
	
	//declare variables of type int and char to store the num_triangles and symbol values entered by the user
	int num_triangles;
	char symbol;

	//Prompt the user for a positive integer and symbol and store it in num_triangles and symbol
	cout << "Please enter a positive integer for the number of triangles in the tree: ";
	cin >> num_triangles;

	cout << "Please enter the character symbol filling the tree(e.g '*', '+', '#', '$', etc.): ";
	cin >> symbol;
	cout << endl;

	//call the printPineTree function with the user entered values
	printPineTree(num_triangles, symbol);

	return 0;
}

void printPineTree(int n, char symbol)
{
	using namespace std;

	//declare variables of type int for the number of lines and padding spaces to be passed to printShiftedTriangle function
	int num_lines, padding_spaces;

	//iterate from 1 to n to print each triangle
	for (int print_iteration = 1; print_iteration <= n; print_iteration++)
	{
		//determine the number of lines and padding spaces for each triangle and pass those parameters along with symbol to printShiftedTriangle function
		num_lines = print_iteration + 1;
		padding_spaces = (n - print_iteration);
		printShiftedTriangle(num_lines, padding_spaces, symbol);
	}
	return;
}

void printShiftedTriangle(int n, int m, char symbol)
{
	using namespace std;
	
	//determine the height and width of each triangle based on the number of lines provided from the printPineTree function
	int height = n;
	int width = 2 * n - 1;

	//iterate from row = 1 to the height of the triangle 
	for (int row = 1; row <= height; row++)
	{
		//for each row iterate through column indices to output padding spaces where applicable first
		for (int padding_col = 0; padding_col < m; padding_col++)
		{
			cout << " ";
		}
		//after applying padding spaces in each row iterate through the column indices and determine whether to print a space or symbol for the triangle
		for (int column = 1; column <= width; column++)
		{
			if (column <= height - row || column >= height + row)
			{
				cout << " ";
			}
			else
			{
				cout << symbol;
			}
		}
		//linebreak after each line of the triangle
		cout << endl;
	}
	return;
}