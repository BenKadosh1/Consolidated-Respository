//File name: bk1139_hw16_q2.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw16_q2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
class Queue
{
	public:
		//supporting functions for determining size and capacity of the queue, and to clear it and see what is at the top of the queue
		void clear() { data.clear(); }
		int size() const { return data.size(); }
		bool is_empty() const{ return occupancy == 0; }
		T top() const { return *data.begin(); }

		//declare enqueue and dequeue functions
		void enqueue(T new_item);
		T dequeue();

		//reset data will reset the indices for front and back index
		void reset_data() {front_index = 0; back_index = -1; }

	private:
		//create an underlying vector of type T to store the data, along with ints to track the front and back indices, and the occupancy of the queue
		vector<T> data;
		int front_index = 0;
		int back_index = -1;
		int occupancy = 0;
};

//define the enqueue function for the Queue class
template <class T>
void Queue<T>::enqueue(T new_item)
{
	//output to the user what is being enqueued 
	cout << "Enqueueing " << new_item << endl;

	//cout << data.capacity() << " " << data.size() << " " << occupancy << " " << front_index << " " << back_index << endl;

	//if the vector is fully occupied 
	if (occupancy == data.size())
	{
		//if the back index is less than the front index and not -1 when initialized it means we have wrapped around
		//we need to create a temp vector to rearrange the queue to maintain its integrity
		//don't want to have 14,11,12,13 (11 front 14 back) pushback 15 be 14,11,12,13,15 but rather 11,12,13,14,15
		if (back_index < front_index && back_index != -1)
		{
			//create the temp vector - populate it and then update the original queue vector
			vector<T> temp;
			for (int i = 0; i < data.size(); i++)
			{
				temp.push_back(data[front_index]);
				if (front_index == data.size() - 1)
				{
					front_index = 0;
				}
				else
				{
					front_index++;
				}
			}
			for (int i = 0; i < data.size(); i++)
			{
				data[i] = temp[i];
			}

			//once we have updated the queue vector pushback the new item and update the occupancy and front and back indices
			data.push_back(new_item);
			occupancy++;
			front_index = 0;
			back_index = data.size() - 1;
		}
		//else - we don't need to rearrange the queue and we simply push back and update occupancy and back
		else
		{
			data.push_back(new_item);
			occupancy++;
			back_index++;
		}
	}
	//else there is open room in queue
	else
	{
		//if there is additional capacity in the vector that has already been allocated
		//then if back is at the end of the vector push back to utilize the additional memory already allocated
		//otherwise store the data at back index and increment 
		//update occupancy
		if (data.capacity() > data.size())
		{
			if (back_index == data.size() - 1)
			{
				data.push_back(new_item);
				occupancy++;
				back_index++;
			}
			//else increment back index and populate in the next slot
			else
			{
				back_index++;
				data[back_index] = new_item;
				occupancy++;
			}
		}
		else
		{
			//if we are at the end of the vector we will wrap around and update the information there
			if (back_index == data.size() - 1)
			{
				back_index = 0;
				data[back_index] = new_item;
				occupancy++;
			}
			//else increment back index and populate in the next slot
			else
			{
				back_index++;
				data[back_index] = new_item;
				occupancy++;
			}
		}	
	}
}

//define the dequeue function for Queue class
template <class T>
T Queue<T>::dequeue()
{
	//if the queue is empty we cannot dequeue further
	if (occupancy == 0)
	{
		cout << "Cannot dequeue further, the Queue is empty. Exiting program" << endl;
		exit(1);
	}
	//else - there is something to dequeue so we will do so and return it's contents 
	else
	{
		//store the information at the front of the queue
		T ret_val = data[front_index];

		//if front is at the end of the vector we will pop its contents and wrap around to the front
		if (front_index == data.size() - 1)
		{
			front_index = 0;
		}
		//otherwise we will simply increment the front index
		else
		{
			front_index++;
		}

		//reduce occupancy 
		occupancy--;

		//if we have dequeued items such that occupancy is now 0 we will call the reset function
		if (occupancy == 0)
		{
			reset_data();
		}

		return ret_val;
	}
}

//2 functions that receive queue objects and enqueue and dequeue objects to them and print the contents to the user
void queue_1_output(Queue<int>& queue_1);
void queue_2_output(Queue<string>& queue_2);

int main()
{
	//output to the user a description for the output produced
	cout << "Below are the outputs for two test queues: one comprised of ints and the other of strings\n" << endl;

	//declare int and string queues and pass them to the respective functions
	cout << "Integer Queue beginning:\n" << endl;
	Queue<int> queue_1_tester;
	queue_1_output(queue_1_tester);
	
	cout << endl;

	cout << "String Queue beginning:\n" << endl;
	Queue<string> queue_2_tester;
	queue_2_output(queue_2_tester);

	return 0;
}


void queue_1_output(Queue<int>& queue_1)
{
	//go through a series of enqueues and dequeues of integers to demonstrate the queue is functioning properly and all elements leave in FIFO order

	
	for (int i = 11; i < 16; i++)
	{
		queue_1.enqueue(i);
	}
	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Dequeueing " << queue_1.dequeue() << endl;
	}
	cout << endl;

	for (int i = 16; i < 19; i++)
	{
		queue_1.enqueue(i);
	}
	cout << endl;

	while (!queue_1.is_empty())
	{
		cout << "Dequeueing " << queue_1.dequeue() << endl;
	}
	cout << endl;
	

	
	for (int i = 19; i < 25; i++)
	{
		queue_1.enqueue(i);
	}
	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Dequeueing " << queue_1.dequeue() << endl;
	}
	cout << endl;

	for (int i = 25; i < 32; i++)
	{
		queue_1.enqueue(i);
	}
	cout << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << "Dequeueing " << queue_1.dequeue() << endl;
	}
	cout << endl;

	for (int i = 32; i < 45; i++)
	{
		queue_1.enqueue(i);
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "Dequeueing " << queue_1.dequeue() << endl;
	}
	cout << endl;

	for (int i = 45; i < 54; i++)
	{
		queue_1.enqueue(i);
	}
	cout << endl;

	while (!queue_1.is_empty())
	{
		cout << "Dequeueing " << queue_1.dequeue() << endl;
	}

	cout << endl;
	
}

void queue_2_output(Queue<string>& queue_2)
{
	//enqueue and then dequeue of strings to demonstrate the queue is functioning properly and all elements leave in FIFO order
	queue_2.enqueue("Hi");
	queue_2.enqueue("there.");
	queue_2.enqueue("I");
	queue_2.enqueue("hope");
	queue_2.enqueue("you");
	queue_2.enqueue("are");
	queue_2.enqueue("having");
	queue_2.enqueue("a");
	queue_2.enqueue("nice");
	queue_2.enqueue("day!");
	
	cout << endl;

	//while the queue still has strings occupying it, call the dequeue function
	while (!queue_2.is_empty())
	{
		cout << "Dequeueing " << queue_2.dequeue() << endl;
	}
}
