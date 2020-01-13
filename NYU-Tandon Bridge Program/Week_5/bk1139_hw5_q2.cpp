#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//declare variables of type int to store the random number that is generated, and to store the user entries when prompted
	int random_number, user_input; 

	//declare and initalize variables of type int for the framework of the program --> number of guesses, minimum range, and maximum range
	int number_of_guesses = 5;
	int min_range = 1, max_range = 100;

	//declare and initialize a bool called continue flag and set it to true. This will be used to continue to iterate through the while loop until set to false
	bool continue_flag = true;

	//generate a random number and then mod it by 100 and add one to set the range for 1-100 and store it in random_number
	srand((unsigned int)time(0));
	random_number = (rand() % 100) + 1;

	//Prompt the user to enter a number between 1 and 100
	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

	
	//Loop while continue_flag = true --> until the user guesses the correct number or runs out of guesses
	while (continue_flag)
	{
		//Output to the user the updated min to max range and number of guesses left. Then prompt the user to enter another guess and store it in user_input
		cout << "Range: [" << min_range << ", " << max_range << "], Number of guesses left: " << number_of_guesses << endl;
		cout << "Your guess: ";
		cin >> user_input;

		//decrement the number of guesses during each iteration
		number_of_guesses--;

		
		//If user guess is incorrect and it is the user's last guess -- output out of guesses and what the random number was. Lastly, set continue_flag to false to allow the while loop to stop iterating
		if (user_input != random_number && number_of_guesses == 0)
		{
			cout << "Out of guesses! My number is " << random_number << endl;
			continue_flag = false;
		}
		
		//If the user guess is less than the random number -- output that the random number is bigger.
		else if (user_input < random_number)
		{
			cout << "Wrong! My number is bigger." << endl;

			//Check if the entry is less than the existing minimum range -- if so, keep the current min range, else take the user entry + 1
			if (min_range >= user_input)
			{
				min_range = min_range;
			}
			else
			{
				min_range = user_input + 1;
			}
		}

		//If the user guess is greater than the random number -- output that the random number is smaller.
		else if (user_input > random_number)
		{
			cout << "Wrong! My number is smaller." << endl;

			//Check if the entry is greater than the existing maximum range -- if so, keep the current max range, else take the user entry - 1
			if (max_range <= user_input)
			{
				max_range = max_range;
			}
			else
			{
				max_range = user_input - 1;
			}
		}

		//Otherwise, output to the user that they guessed correctly, and set continue_flag to false to allow the while loop to stop iterating
		else
		{
			//If they guess correctly on first guess it will say 1 guess and not 1 guesses
			if (number_of_guesses == 4)
			{
				cout << "Congrats! You guessed my number in " << 5 - number_of_guesses << " guess." << endl;
			}
			else
			{
				cout << "Congrats! You guessed my number in " << 5 - number_of_guesses << " guesses." << endl;
			}
			continue_flag = false;
		}

		//line break between guesses
		cout << endl;
	}
	return 0;
}
