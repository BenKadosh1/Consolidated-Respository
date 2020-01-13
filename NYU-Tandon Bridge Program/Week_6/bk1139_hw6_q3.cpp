//File name: bk1139_hw6_q3.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw6_q3



//This code assumes the user will provide valid entries when prompted

#include <iostream>

double eApprox(int n);
/*
  The eApprox function takes one arguement:
	1. An int, n, which sets the number of addends in the calculation of the value for 'e'
  The eApprox function returns a double, which is the approximation for the value of 'e'

  The function iterates from 1 to n and determines the approximate value of 'e' by adding 1/(n!) to e and *= the factorial base by num_addends
  Since we calculate the factorial at each additional addened all we have to do is multiply by n not reclaculate n!
*/

int main()
{
	using namespace std;
	
	//set precision 
	cout.precision(30);


	//output the approximation for e with number of addends from 1-15
	for (int n = 1; n <= 15; n++)
	{
		cout << "n = " << n << "\t" << eApprox(n) << endl;
	}

	return 0;
}

double eApprox(int n)
{
	using namespace std; 

	//declare and initalize two variables e and factorial base to 1
	//e and the factorial base will increase with each iteration in the for loop
	double e = 1.0;
	double factorial_base = 1.0;

	//iterate from 1 to n for the number of addends 
	//*= the factorial base to use what has already been calculated and not recalaculate full factorials for each iteration
	//increase e by 1/factorial base
	for (int num_addends = 1; num_addends <= n; num_addends++)
	{
		factorial_base *= num_addends;
		e += (1.0 / factorial_base);
	}
	//return e
	return e;
}

