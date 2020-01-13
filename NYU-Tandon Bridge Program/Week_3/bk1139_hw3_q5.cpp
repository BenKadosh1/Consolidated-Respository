//This code assumes the user will only enter valid responses when prompted****

#include <iostream>
using namespace std;

//declare and initalize constant variables of type double for conversion amounts and BMI ranges
const double LBS_TO_KGS = 0.453592, INCHES_TO_METERS = 0.0254;
const double BMI_RANGE_UNDERWEIGHT = 18.5, BMI_RANGE_NORMAL = 25.0, BMI_RANGE_OVERWEIGHT = 30.0;

int main()
{
	//declare variables for user inputs
	double user_weight_lbs, user_height_inches;

	//declare variables for converted user inputs
	double user_weight_kgs, user_height_meters, BMI;


	//Prompt the user to enter a weight in pounds and height in inches
	cout << "Please enter weight (in pounds): ";
	cin >> user_weight_lbs;

	cout << "Please enter height (in inches): ";
	cin >> user_height_inches;


	//convert user inputs to appropriate units of measure for BMI calculation
	user_weight_kgs = user_weight_lbs * LBS_TO_KGS;
	user_height_meters = user_height_inches * INCHES_TO_METERS; 

	//calculate BMI
	BMI = user_weight_kgs / (user_height_meters*user_height_meters);


	//if, else-if, else branching to determine weight status
	if (BMI < BMI_RANGE_UNDERWEIGHT)
	{
		cout << "The weight status is: Underweight";
	}
	else if (BMI < BMI_RANGE_NORMAL)
	{
		cout << "The weight status is: Normal";
	}
	else if (BMI < BMI_RANGE_OVERWEIGHT)
	{
		cout << "The weight status is: Overweight";
	}
	else
	{
		cout << "The weight status is: Obese";
	}

	return 0;
}

