//File name: bk1139_hw15_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw15_q1


//This program assumes the input text files will match the samples provided in the homework prompt
//This program assumes the input text files are separated by spaces
//Input files input5.txt and input6.txt uploaded for reference as well

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


template <class T>
class LinkedList;

//define LinkedListNode class
template <class T>
class LinkedListNode
{
	public:
		//declare the LinkedList class as a friend class of the LinkedListNode class
		friend class LinkedList<T>;

		//define the LinkedListNode constructor
		LinkedListNode(const T& new_data = T(), LinkedListNode<T>* new_next = nullptr, LinkedListNode<T>* new_previous = nullptr)
			: data(new_data), next(new_next), previous(new_previous) {}	

	private:
		//define the private variables for the class - class object, and pointers to the next and previous nodes
		T data;
		LinkedListNode<T>* next;
		LinkedListNode<T>* previous;
};

//define LinkedList class
template <class T>
class LinkedList
{
	public:
		//declare the LinkedList class constructor
		LinkedList();

		//declare the big 3 for the LinkedList class
		LinkedList(const LinkedList<T>& source);
		LinkedList<T>& operator=(const LinkedList<T>& source);
		~LinkedList<T>();

		//define supporting functions for the LinkedList class - is_empty and clear
		bool is_empty() { return head->next == tail; }
		void clear() { while (!is_empty())pop_front(); }

		//define push_back and push_front functions to add LinkedListNodes either to the beginning or end of the LinkedList
		void push_back(const T& data) { tail->previous = new LinkedListNode<T>(data, tail, tail->previous); tail->previous->previous->next = tail->previous;}
		void push_front(const T& data) { head->next = new LinkedListNode<T>(data, head->next, head); head->next->next->previous = head->next; }
		
		//declare pop functions to remove nodes from the linked list
		T pop_back();
		T pop_front();
		T pop_current(LinkedListNode<T>* current_node_ptr);

		//declare a function to determine the size of the LinkedList
		int size();

		//define getter functions to return pointers to the head and tail of the linked list, and pointers to the next and previous nodes in the list
		LinkedListNode<T>* get_head() { return head; }
		LinkedListNode<T>* get_tail() { return tail; }
		LinkedListNode<T>* get_next_ptr(LinkedListNode<T>* current) { return current->next ; }
		LinkedListNode<T>* get_previous_ptr(LinkedListNode<T>* current) { return current->previous; }

		//getter functions to return the object stored in a Linked List Node by reference, and a pointer to the object in the linked list node
		T& get_data(LinkedListNode<T>* current) const { return current->data; }
		T* get_data_ptr(LinkedListNode<T>* current) const { return &(current->data); }

	private:
		//define the private variables for the class - head and tail pointers
		LinkedListNode<T>* head;
		LinkedListNode<T>* tail;
};

//define LinkedList constructor
template<class T>
LinkedList<T>::LinkedList()
{
	//create new LinkedListNode objects for the head and tail of the list
	head = new LinkedListNode<T>();
	tail = new LinkedListNode<T>();

	//set head and tail's next and previous respectively to the opposite node
	head->next = tail;
	tail->previous = head;
}

//Define copy constructor for the LinkedList class
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& source)
{
	//create new LinkedListNode objects for the head and tail of the list
	head = new LinkedListNode<T>();
	tail = new LinkedListNode<T>();

	//set head and tail's next and previous respectively to the opposite node
	head->next = tail;
	tail->previous = head;
	*this = source;
}

//Define = operator overload for LinkedList class
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& source)
{
	if (this ==&source)
	{
		return *this;
	}
	else
	{
		//create a new LinkedList
		//set a ptr to the head node and then iterate through it copying each node to the new LinkedList
		clear();
		LinkedListNode<T>* ptr = source.head->next;
		while (ptr != source.tail)
		{
			push_back(ptr->data);
			ptr = ptr->next;
		}
		return *this;
	}
}

//Define the destructor for the LinkedList class
template<class T>
LinkedList<T>::~LinkedList()
{
	//call clear function and then delete the head and tail nodes of the LinkedList
	clear();
	delete head;
	delete tail;
}

//Define a size function for the LinkedList class that determines how many nodes are in the list
template<class T>
int LinkedList<T>::size()
{
	//iterate from the head node to the tail node and increment counter so long as tail has not been reached
	LinkedListNode<T>* ptr = head->next;
	int count = 0;
	while (ptr != tail)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}


//Define pop_back function for LinkedList class
template <class T>
T LinkedList<T>::pop_back()
{
	//if there are no nodes construct a node and return it - ensure you are not popping something that isn't there
	if (tail->previous == head)
	{
		return T();
	}
	else
	{
		//identify the node before the tail and store it's object
		//update the relevant pointers for the nodes remaining in the list once the current node is popped
		//free the heap memory for the deleted node
		T return_value = tail->previous->data;
		LinkedListNode<T>* node_to_delete = tail->previous;
		tail->previous = node_to_delete->previous;
		node_to_delete->previous->next = node_to_delete->next;
		delete node_to_delete;
		return return_value;
	}
}

//Define pop_front function for LinkedList class
template<class T>
T LinkedList<T>::pop_front()
{
	//if there are no nodes construct a node and return it - ensure you are not popping something that isn't there
	if (tail->previous == head)
	{
		return T();
	}
	else
	{
		//identify the node after the head and store it's object
		//update the relevant pointers for the nodes remaining in the list once the current node is popped
		//free the heap memory for the deleted node
		T return_value = head->next->data;
		LinkedListNode<T>* node_to_delete = head->next;
		head->next = node_to_delete->next;
		head->next->previous = head;
		delete node_to_delete;
		return return_value;
	}
}

//Define pop_current function for LinkedList class
template<class T>
T LinkedList<T>::pop_current(LinkedListNode<T>* current_node_ptr)
{
	//if there are no nodes construct a node and return it - ensure you are not popping something that isn't there
	if (tail->previous == head)
	{
		return T();
	}
	else
	{
		//identify the current node store it's object
		//update the relevant pointers for the nodes remaining in the list once the current node is popped
		//free the heap memory for the deleted node
		T return_value = current_node_ptr->data;
		LinkedListNode<T>* node_to_delete = current_node_ptr->previous->next;
		current_node_ptr->previous->next = node_to_delete->next;
		current_node_ptr->next->previous = node_to_delete->previous;
		delete node_to_delete;
		return return_value;
	}
}


class Employee
{
	public:
		//Define Employee constructor
		Employee(int in_id_number = 0, double in_hourly_rate = 0.0, string in_name = "") : id_number(in_id_number), hourly_pay_rate(in_hourly_rate), name(in_name), hours_worked(0.0), total_pay(0.0) {}

		//getters/accessor functions
		string get_name() const { return name; }
		int get_id_number() const { return id_number; }
		double get_hourly_pay_rate() const { return hourly_pay_rate; }
		double get_hours_worked() const { return hours_worked; }
		double get_total_pay() const { return total_pay; }

		//setters/mutator functions
		void set_name(string in_name) { name = in_name; }
		void set_id_number(int in_id_number) { id_number = in_id_number; }
		void set_hourly_pay_rate(double in_hourly_rate) { hourly_pay_rate = in_hourly_rate; }
		void set_hours_worked(double in_hours_worked) { hours_worked += in_hours_worked; }

		//define function to determine the total pay for the employee
		void calculate_total_pay() { total_pay = hourly_pay_rate * hours_worked; }

	private:
		//declare the private variables for the Employee class
		string name;
		int id_number;
		double hourly_pay_rate;
		double hours_worked;
		double total_pay;
};


//void function that recieves an ifstream object by reference and a file count number by reference
//the function runs to open a file and iterates until it does so successfully 
void open_input_file(ifstream& input_file, int& count);

//void function that receives a linkedlist of employees by reference
//this function will print the results to the console in sorted descending order
//once a node's information has been printed it will be popped
void print_results_pop_nodes(LinkedList<Employee>& employee_listing);

int main()
{
	//initialize a linkedlist of employees
	LinkedList<Employee> employee_listing; 
	
	//declare two input objects for the two input files to be read in
	ifstream input_file_1, input_file_2;
	
	int file_count = 1;
	
	//call the open_input_file on the first file to be read
	open_input_file(input_file_1, file_count);

	//create temp variables to store the data being read in - id, name, hourly rate
	int temp_id;
	string temp_name;
	double temp_hourly_rate;

	//read in the data while there is more data to read in
	while (input_file_1 >> temp_id)
	{
		input_file_1 >> temp_hourly_rate;
		input_file_1.ignore(9999, ' '); // throw this in a for loop and look for tabs and multiple spaces don't use ignore. Instead use get and put and putback
		getline(input_file_1, temp_name);

		//create a temp employee with the the information read in and push it to the linkedlist
		Employee temp(temp_id, temp_hourly_rate, temp_name);
		employee_listing.push_back(temp);
	}
	//close the input file once we have read in all of the information
	input_file_1.close();
	

	//create pointers for the head of the linkedlist and the pointer to the next node
	LinkedListNode<Employee>* head_ptr = employee_listing.get_head();
	LinkedListNode<Employee>* next_ptr = nullptr;

	//open the second input file
	open_input_file(input_file_2, file_count);

	//create a double variable to store temp hours
	double temp_hours;

	//read in data from the second input file while there is more data to be read and update the objects in the linkedlist based on matching ids
	while (input_file_2 >> temp_id)
	{
		next_ptr = employee_listing.get_next_ptr(head_ptr);
		input_file_2 >> temp_hours;
		for (int i = 0; i < employee_listing.size(); i++)
		{
			Employee* object_ptr = employee_listing.get_data_ptr(next_ptr);
			if (object_ptr->get_id_number() == temp_id)
			{
				object_ptr->set_hours_worked(temp_hours);
				object_ptr->calculate_total_pay();
			}
			next_ptr = employee_listing.get_next_ptr(next_ptr);
		}
	}
	//close the second file after the necessary data has been read in
	input_file_2.close();

	//call the print_results_pop_nodes function to print the results to the user
	print_results_pop_nodes(employee_listing);
	
	return 0;
}

void print_results_pop_nodes(LinkedList<Employee>& employee_listing)
{
	LinkedListNode<Employee>* head_ptr = employee_listing.get_head();
	LinkedListNode<Employee>* next_ptr = nullptr;

	//create variables to store the max amount and employee name
	double max_total = 0;
	string output_name;

	cout << "\n*********Payroll Information********" << endl;

	//iterate so long as the employee listing still has nodes remaining
	while (employee_listing.size() > 0)
	{
		//iterate through the list to find the max amount by comparing the total pay at each node to the max_total variable
		next_ptr = employee_listing.get_next_ptr(head_ptr);
		for (int i = 0; i < employee_listing.size(); i++)
		{
			Employee* object_ptr = employee_listing.get_data_ptr(next_ptr);
			if (object_ptr->get_total_pay() >= max_total)
			{
				max_total = object_ptr->get_total_pay();
				output_name = object_ptr->get_name();
			}
			next_ptr = employee_listing.get_next_ptr(next_ptr);
		}
		//reset the next ptr to the head of the linkedlist
		next_ptr = employee_listing.get_next_ptr(head_ptr);

		//once the max total and name have been found, iterate through the linkedlist to find the relevant node, print its information and pop it
		bool pop_flag = false;
		while (!pop_flag)
		{
			Employee* object_ptr = employee_listing.get_data_ptr(next_ptr);
			double test = object_ptr->get_total_pay();
			if (object_ptr->get_total_pay() == max_total && object_ptr->get_name() == output_name)
			{
				Employee temp = employee_listing.pop_current(next_ptr);
				pop_flag = true;
			}
			else
			{
				//if the node has not been popped yet, shift the next ptr to the next node
				next_ptr = employee_listing.get_next_ptr(next_ptr);
			}
		}
		//set precision
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		//output name and total pay
		cout << output_name << ",\t$" << max_total << endl;
		max_total = 0;
	}
	cout << "*********End payroll**************" << endl;
}

void open_input_file(ifstream& input_file, int& count)
{
	//create a string to store the filename and prompt the user to enter the file name
	string file_name;
	cout << "Please enter the filename for file #" << count << " which you wish to open: ";
	cin >> file_name;

	//call the open function on the input file
	input_file.open(file_name);
	while (!input_file)
	{
		//if the file was not opened successfully, prompt the user to enter the file name again and clear the necesssary flags before attempting to open again
		cout << "The file was not opened successfully" << endl;
		cout << "Please enter the filename which you wish to open: ";
		cin >> file_name;
		input_file.clear();
		input_file.open(file_name);
	}
	count++;
}