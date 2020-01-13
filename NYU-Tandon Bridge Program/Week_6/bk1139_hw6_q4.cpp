//File name: bk1139_hw6_q4.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw6_q4



//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <cmath>

void printDivisors(int num);
/*
  The printDivisors function takes one arguement:
	1. An int, num, which will result in an output of all of num's divisors in ascending order
  The printDivisors function is a void function, so it does not have a return value

  The function iterates from i = 1 to i<= sqrt(num) and determines which numbers in that range are divisors of num
  If i is a divisor it is included in the output to the user
  An additional for loop is used following the first one to output divisors greater than sqrt(num)
*/

int main()
{
	using namespace std;

	//declare a variable of type into to store the number entered by the user
	int user_int;

	//prompt the user for a positive integer and store it in user_int
	cout << "Please enter a positive integer >= 2: ";
	cin >> user_int;

	//call the printDivisors function and pass the user_int as an arguement
	printDivisors(user_int);

	return 0;
}

void printDivisors(int num)
{
	using namespace std;

	//declare a variable called square_root and store the sqrt of the arguement num
	double square_root = sqrt(num);

	//iterate from 1 to less than or equal to the squareroot of the int entered by the user
	//this will output the first half of the divisors in ascending order
	for (int i = 1; i <= square_root; i++)
	{
		//if the num provided by the user is divisible by i (it is a divisor) output it to the user
		if (num % i == 0)
		{
			cout << i << " ";
		}
	}
	
	//for the second half of divisors greater than sqrt num decrement to output the divisors in ascending order
	for (int j = square_root; j >= 1; j--)
	{
		//if the num provided by the user is divisible by j and the result doesn't equal j then output num/j
		if (num % j == 0 && num / j != j)
		{
			cout << num / j << " ";
		}
	}
	return;
}