//This code assumes the user will only enter valid responses when prompted****
//Precision set to match output exactly as shown in homework prompt

#include <iostream>
#include <cmath>

using namespace std; 

int main()
{
	//declare variables of type double for user inputs for values a, b, and c in the quadratic equation
	double quadratic_input_a, quadratic_input_b, quadratic_input_c;

	//declare variables of type double for calculating the solutions to the quadratic equation
	double quadratic_discriminant, quadratic_solution_1, quadratic_solution_2;


	//prompt the user for values a, b, and c
	cout << "Please enter value of a: ";
	cin >> quadratic_input_a;

	cout << "Please enter value of b: ";
	cin >> quadratic_input_b;
	
	cout << "Please enter value of c: ";
	cin >> quadratic_input_c;

	//set precision for the outputs
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);


	//use nested if else statement to address the different possibilities for solutions and output to the user

	//if a, b, and c are all 0 then the equation has infinite solutions
	if (quadratic_input_a == 0.0 && quadratic_input_b == 0.0 && quadratic_input_c == 0.0)
	{
		cout << "This equation has an Infinite number of solutions";
	}
	//if a and b are 0 the equation has no solution
	else if (quadratic_input_a == 0.0 && quadratic_input_b == 0.0)
	{
		cout << "This equation has No solution";
	}
	//if a equals 0 and c equals 0 then it is a linear equation with one real solution = 0  (removed negative sign to not have -0)
	else if (quadratic_input_a == 0.0 && quadratic_input_c == 0.0)
	{
		cout << "This equation has a single real solution x=" << quadratic_input_c / quadratic_input_b;
	}
	//if a equals 0 then it is a linear equation with one real solution
	else if (quadratic_input_a == 0.0)
	{
		cout << "This equation has a single real solution x="<< -quadratic_input_c/quadratic_input_b;
	}
	//else calculate the quadratic discriminant to determine if the whole quadratic equation must be used to determine the solutions
	else
	{
		//calculate the quadratic discriminant b squared - 4ac
		quadratic_discriminant = (quadratic_input_b * quadratic_input_b) - (4 * quadratic_input_a * quadratic_input_c);

		//if the quadratic discriminant is negative there is no real solution
		if (quadratic_discriminant < 0.0)
		{
			cout << "This equation has No real solution";
		}
		//else if the quadratic discriminant equals 0 there is a single real solution equal to -b/2a
		else if (quadratic_discriminant == 0.0)
		{
			cout << "This equation has a single real solution x=" << -quadratic_input_b / (2 * quadratic_input_a);
		}
		//else the quadratic discriminant is positive which means there are two real solutions
		else
		{
			//calculate the two real solutions to the quadratic equation
			quadratic_solution_1 = (-quadratic_input_b + sqrt((quadratic_input_b * quadratic_input_b) - (4 * quadratic_input_a * quadratic_input_c))) / (2 * quadratic_input_a);
			quadratic_solution_2 = (-quadratic_input_b - sqrt((quadratic_input_b * quadratic_input_b) - (4 * quadratic_input_a * quadratic_input_c))) / (2 * quadratic_input_a);

			cout << "This equation has two real solutions x=" << quadratic_solution_1 << ", and " << quadratic_solution_2 << endl;
		}
	}
	return 0;
}
