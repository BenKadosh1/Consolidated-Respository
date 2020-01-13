//This program assumes the user will only enter valid positive integers when prompted***

/*The fundemental structure to the algorithm I used in this code has the following major components
1.  Generate the top half of the hour glass
1a. Implement a for loop to iterate from row = user input down to 1 (this represents each row of output)
1b. Determine the number of stars (asterisks) and spaces that should be printed for each row
1c. Number of stars = 2 X iteration - 1 --> number of spaces equals (2 X user input - 1) - number of stars
1d. Use additional for loop to iterate through each index (column) for the given row
1e. At each index within a given row determine if column < num_spaces/2 to determine if spaces should pad to the left of the stars and column >= the left padding + the num stars printed
1f. otherwise output stars (asterisks)

2.  Generate the bottom half of the hour glass using the same methodology as from 1a - 1f with the following changes
2a. Work from 1 star to many stars (few to many) as opposed to from many to few
2b. Increment up instead of down starting with row = 1
*/

#include <iostream>
using namespace std;

int main()
{
	//declare int variables for user input, number of stars, and number of spaces
	int user_int, num_stars, num_spaces;

	//prompt the user for a positive integer and store it in user_int
	cout << "Please input a positive integer: ";
	cin >> user_int;


	//for loop from user int down to 1 for each row in the top half of the hour gass
	for (int row = user_int; row > 0; row--)
	{
		//calculate the number of stars and spaces to output for each row
		num_stars = 2 * row - 1;
		num_spaces = (2 * user_int - 1) - num_stars;

		//iterate through each index in that row with a for loop
		for (int column = 0; column < (2 * user_int - 1); column++)
		{
			//determine if the first n indices and the last n indices should be spaces
			if (column < (num_spaces/2) || column >= num_stars + (num_spaces / 2))
			{
				cout << " ";
			}
			//else output stars
			else
			{
				cout << "*";
			}
		}
		//output a line break for each row of the hour glass
		cout << "\n";
	}


	//apply the same methodology as above for the bottom half of the hour glass. Increment from 1 to user int to populate stars from few to many
	for (int row = 1; row <= user_int; row++)
	{
		num_stars = 2 * row - 1;
		num_spaces = (2 * user_int - 1) - num_stars;

		for (int column = 0; column < (2 * user_int - 1); column++)
		{
			if (column < (num_spaces / 2) || column >= num_stars + (num_spaces / 2))
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << "\n";
	}
	return 0;
}
