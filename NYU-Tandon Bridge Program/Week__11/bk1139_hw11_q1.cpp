//File name: bk1139_hw11_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw11_q1


#include <iostream>

void printTriangle(int n);
/*
  The printTriangle function takes one argument:
	1. An int, n, which represents the number of lines with asterisks to print a triangle
  The printTriangle function is a void function and therefore does not have a return value

  The function's purpose is to recursively print a triangle with 1-n stars in each line from 1-n respectively
*/

void printOppositeTriangles(int n);
/*
  The printOppositeTriangles function takes one argument:
	1. An int, n, which represents the number of lines with asterisks to print each of two opposing triangles
  The printOppositeTriangles function is a void function and therefore does not have a return value

  The function's purpose is to recursively print two triangles with n to 1 and then 1 to n stars in each line for 2n lines
*/

void printRuler(int n);
/*
  The printRuler function takes one argument:
	1. An int, n, which represents the max width of the ruler and will dictate how many lines are printed
  The printRuler function is a void function and therefore does not have a return value

  The function's purpose is to recursively print a ruler with 2^n - 1 lines with corresponding units of measure at each line
*/

int main()
{
	using namespace std;

	//Call each of the three recursive functions and pass it the integer 4, then output the results to the user
	cout << "Below are sample outputs for three recursive functions when passed the positive integer 4 for each" << endl;
	cout << "\nprintTriangle function:" << endl;
	printTriangle(4);

	cout << "\nprintOppositeTriangles function:" << endl;
	printOppositeTriangles(4);

	cout << "\nprintRuler function:" << endl;
	printRuler(4);

	return 0;
}

void printRuler(int n)
{
	using namespace std;
	//set the base case to n = 1 and when it is one print 1 dash
	if (n == 1)
	{
		cout << "-" << endl;
		return;
	}
	else
	{
		//else we will use two recursive calls with a for loop in between to print all applicable increments from the ruler
		//we use two recursive calls to ensure we print both sides of each respective larger mark
		//for example when we have n = 2 we call n-1 to print - then we print - -  and then - 
		printRuler(n - 1);
		for (int i = 1; i <= n; i++)
		{
			cout << "- ";
		}
		cout << endl;
		printRuler(n - 1);
	}
}

void printTriangle(int n)
{
	using namespace std;

	//if n equals 1 is our base case to end the recursion - print one asterisk and return
	if (n == 1)
	{
		cout << "*" << endl;
		return;
	}
	else
	{
		//we recursively call the function on n-1 first to iterate to the lowest n first before printing stars
		//this is so we print as we ascend to go from 1 to n
		printTriangle(n - 1);
		
		//after the function returns print asterisks from 1 to n
		for (int j = 1; j <= n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void printOppositeTriangles(int n)
{
	using namespace std;

	//declare a base case of n equals 0 of where the recursion will stop. If it hits 0 we simply return
	if (n == 0)
	{
		return;
	}
	else
	{
		//otherwise as we recursively drill down to lower n values and as we come back up to n we will print stars using 2 for loops
		//The two for loops allow for printing the stars in descending and then ascending order
		//We place one for loop before the recursive call and one after it

		for (int j = 1; j <= n; j++)
		{
			cout << "*";
		}
		cout << endl;
		printOppositeTriangles(n - 1);
		for (int j = 1; j <= n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}