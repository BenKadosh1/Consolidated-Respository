//File name: bk1139_hw14_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw14_q1

#include <iostream>
#include <vector>
using namespace std;


//min_max_finder is a function that receives an integer vector by reference, along with low and high indices
//The function is a recursive function that uses a divide and conquer approach 
//to find the minimum and maximum values within the range of the vector provided by the high and low indices
//the vector returns an int vector of size 2 with the 0 index storing the min vaue and the 1 index storing the max value
vector<int> min_max_finder(vector<int>& vec, int low, int high);


//the print_min_max receives an int vector by reference and calls min_max_finder and prints the results to the user
void print_min_max(vector<int>& vec);

int main()
{
	//initialize 4 different test vectors
	vector<int> vector_1{7}, vector_2{ 3,1 }, vector_3{ 1,2,3,86,98,42,-9,6 }, vector_4{ 1,6,100,96,-50,8,-2 };

	cout << "Below is a listing of 4 different sequences with their corresponding minimum and maximum values\n" << endl;
	
	//print the results for the 4 vectors
	print_min_max(vector_1);
	print_min_max(vector_2);
	print_min_max(vector_3);
	print_min_max(vector_4);

	return 0;
}

void print_min_max(vector<int>& vec)
{
	//if there are no values in the vector we cannot evaluate for min and max
	if (vec.size() == 0)
	{
		cout << "You have passed an empty vector that cannot be evaluated for min and max values\n" << endl;
	}
	else
	{
		//print the entire sequence out 
		cout << "Sequence: [";
		for (int i = 0; i < vec.size(); i++)
		{
			if (i != vec.size() - 1)
			{
				cout << vec[i] << ", ";
			}
			else
			{
				cout << vec[i] << "]";
			}
		}
		cout << endl;

		//call the min_max_finder to determine the min and max values in the sequence and output that to the user as well
		vector<int> ret_min_max = min_max_finder(vec, 0, vec.size() - 1);
		cout << "Minimum value = " << ret_min_max[0] << "\nMaximum value = " << ret_min_max[1] << endl << endl;
	}

}

vector<int> min_max_finder(vector<int>& vec, int low, int high)
{
	//declare min and max variables to store
	int min, max;

	//declare an int vector to store the min and max (use left for the left side of a branch when running recursively)
	vector<int> min_max_left;

	//if high == low the vector is of size 1 and min and max will be the same. Push both to min_max_left
	if (high == low)
	{
		min_max_left.push_back(vec[low]);
		min_max_left.push_back(vec[high]);
		return min_max_left;
	}
	//if the vector is of size two, compare the values in the vector and push the min followed by the max into the min_max_left vector
	else if (high == low + 1)
	{
		if (vec[low] < vec[high])
		{
			min_max_left.push_back(vec[low]);
			min_max_left.push_back(vec[high]);
		}
		else
		{
			min_max_left.push_back(vec[high]);
			min_max_left.push_back(vec[low]);
		}
		return min_max_left;
	}
	//otherwise use recursion to divide and conquer the vector
	else
	{
		//create an additional vector for the recursive calls on the right side branches when dividing
		vector<int> min_max_right;

		//calculate a mid point for the divide and conquer process
		int mid;
		mid = (low + high) / 2;

		//call the min_max_finder on both halves
		min_max_left = min_max_finder(vec, low, mid);
		min_max_right = min_max_finder(vec, mid + 1, high);

		//compare the min in the left and right min_max vectors and take the min of those two values and place it in the left vector
		if (min_max_left[0] > min_max_right[0])
		{
			min_max_left[0] = min_max_right[0];
		}

		//compare the max in the left and right min_max vectors and take the max of those two values and place it in the left vector
		if (min_max_left[1] < min_max_right[1])
		{
			min_max_left[1] = min_max_right[1];
		}
		//return the min_max_left vector
		return min_max_left;
	}
}



