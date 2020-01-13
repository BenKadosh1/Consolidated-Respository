//File name: bk1139_hw7_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw7_q2


//This code assumes the user will provide valid entries when prompted

#include <iostream>
#include <cmath>


bool isPerfect(int num);
/*
  The isPerfect function takes one arguement:
	1. An int, num, which will be evaluated to determine whether or not it is a perfect number
  The isPerfect function returns a bool value

  The function's purpose is to determine if a number is a perfect number

  The function calls analyzeDivisors to determine the sum of its divisors
  it then compares the sum of divisors to num to see if they match or not
*/

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
/*
  The analyzeDivisors function takes three arguements:
	1. An int, num, which is called by value and will be evaluated to determine its divisors
	2. An int, outCountDivs, which is called by reference and will determine the number of divisors for num other than num itself 
	3. An int, outSumDivs, which is called by reference and will determine the sum of divisors for num other than num itself
  The analyzeDivisors function is a void function, so it has no return value, however it does update values for two variables by reference

  The function's purpose is to determine the count of divisors and the sum of divisors for any given number

  The function iterates from i = 1 to sqrt(num) and determines if num is divisible by i
  outCountDivs and OutSumDivs are updated where a divisor exists
*/


//declare global variables outCountDivs and outSumDivs so they can be referenced by multiple functions 
int outCountDivs, outSumDivs;

int main()
{
	using namespace std;

	//declare a variable num that will be provided by the user
	int num;

	//Prompt the user for an integer greater than or equal to 2 and store it in num
	cout << "Please enter a positive integer greater than or equal to 2: ";
	cin >> num;
	
	//output to the user all perfect numbers between two and num
	cout << "\nBelow is a listing of all perfect numbers between 2 and " << num << ":" << endl;
	
	//iterate from 2 to num and call is perfect for each number to determine if it is perfect or not
	for (int i = 2; i <= num; i++)
	{
		if (isPerfect(i) == true)
		{
			cout << i << endl;
		}
	}
	
	//create two variables of type int to store the sumdivs of any potential amicable pair
	int amicable_1_sum_divs, amicable_2_sum_divs;

	//output to the user all pairs of amicable numbers between 2 to num
	cout << "\nBelow is a listing of all pairs of amicable numbers between 2 and " << num << ":" << endl;
	
	/*iterate from 2 to num 
	  for each number j call analyze divisors on j and store outSumDivs in amicable_1_sum_divs
	  then call analyze divisors on amicable_1_sum_divs and store the updated outSumDivs in amicable_2_sum_divs
	  compare amicable_2_sum_divs to j to make sure the sum of the potential second amicable # equals j which is the current number in question
	  output the pair to the user 
	  to avoid duplicate prints of each pair and where one number in the pair exceeds num, print only when amicable 2 < amicable 1 and amicable 1 <= num
	*/
	for (int j = 2; j <= num; j++)
	{
		analyzeDivisors(j, outCountDivs, outSumDivs);
		amicable_1_sum_divs = outSumDivs;
		analyzeDivisors(amicable_1_sum_divs, outCountDivs, outSumDivs);
		amicable_2_sum_divs = outSumDivs;

		if (amicable_2_sum_divs < amicable_1_sum_divs && j == amicable_2_sum_divs && amicable_1_sum_divs<=num)
		{
			cout << "(" << amicable_2_sum_divs << ", " << amicable_1_sum_divs << ")" << endl;
		}
	}
	return 0;
}

bool isPerfect(int num)
{
	//call analyze divisors with the arguement num passed to the function
	analyzeDivisors(num, outCountDivs, outSumDivs);

	//compare num to outSumDivs --> if they are equal it is a perfect square and return true otherwise return false
	if (num == outSumDivs)
	{
		return true;
	}
	else
	{
		return false; 
	}
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs)
{
	using namespace std;

	//set outCountDivs and outSumDivs to 0, to ensure the function initializes the values to 0 and clears any potential values from earlier function calls
	outCountDivs = 0;
	outSumDivs = 0;

	//for i = 1 to sqrt of the num arguement passed to the function, check if num is divisible by i to signify it is a divisor 
	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num% i == 0)
		{
			//if i == 1 or is a divisor such that i^2 = num (e.g 10*10 = 100) increment outCountDivs by 1 and increase outSumDivs by i
			if (i == num / i || i == 1)
			{
				outCountDivs++;
				outSumDivs += i;
			}
			//otherwise there is a divisor greater than sqrt(num) such that i*(num/i) = num that complements i as a divisor
			//increment outCountDivs by 2 for the two divisors and increase outSumDivs by i and (num/i)
			else
			{
				outCountDivs += 2;
				outSumDivs += (i + num / i);
			}
		}
	}
	return;
}