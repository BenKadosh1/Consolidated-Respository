
#include <iostream>
using namespace std;

int main()
{
	//Declare a variable of type int to store the user's entry
	int user_int;

	//Prompt the user for a positive integer and store it in user_int
	cout << "Please enter a positive integer:" << endl;
	cin >> user_int;

	//Create an n*n (user_int*user_int) table with two nested for loops for each row and and each column within each row. Iterate through each row and column from 1 to user_int
	for (int row = 1; row <= user_int; row++)
	{
		for (int column = 1; column <= user_int; column++)
		{
			//output the result of row*column for each column in each row and separate the outputs for each column with a tab
			cout << row * column<<"\t";
		}
		//output a linebreak for each new row
		cout << endl;
	}
	return 0;
}
