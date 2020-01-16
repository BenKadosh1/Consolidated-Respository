//File name: bk1139_hw13_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw13_q1


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//declare const ints for the grid dimenensions, the initial populations, the survival and starve counts, number of movement choices, and numeric values for each movement
const int ROW_RANGE = 20, COLUMN_RANGE = 20;
const int INITIAL_ANT_POPULATION = 100;
const int INITIAL_DOODLEBUG_POPULATION = 5;

const int ANT_SURVIVAL_COUNT = 3;
const int DOODLEBUG_SURVIVAL_COUNT = 8;

const int DOODLEBUG_STARVE_COUNT = 3;

const int MOVEMENT_CHOICES = 4;
const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;


//create a struct to store whether a surrounding position is occupied and if it is with what
struct occupied_surroundings
{
	string organism_type = "";
	bool occupied = false;
};

//Organism class definition - base class
class Organism
{
	public:
		//constructors
		Organism() : row_pos(0), column_pos(0), survival_count(0), organism_type("Organism"), moved_flag(false),starve_count(0),surroundings(new occupied_surroundings[MOVEMENT_CHOICES]) {}
		Organism(int row, int column, string type);
		Organism(int row, int column, int count, string type, bool moved, int starve);

		//getters-accessors
		int get_row_pos() const { return row_pos; }
		int get_column_pos() const { return column_pos; }
		int get_survival_count() const { return survival_count; }
		int get_starve_count() const { return starve_count; }
		string get_type() const { return organism_type; }
		bool get_moved_flag() const { return moved_flag; }
		bool get_occupied_surroundings(int index) const { return surroundings[index].occupied; }
		string get_occupied_surroundings_type(int index) const { return surroundings[index].organism_type; }

		//setters-mutators
		void set_row_pos(int row) { row_pos = row; }
		void set_column_pos(int column) { column_pos = column; }
		void set_survival_count(int count) { survival_count = count; }
		void set_starve_count(int count) { starve_count = count; }
		void set_type(string type) { organism_type = type; }
		void set_moved_flag(bool moved) { moved_flag = moved; }
		void set_occupied_surroundings(int index, bool occ, string type) { surroundings[index].occupied = occ, surroundings[index].organism_type = type;}

		//virtual functions
		virtual void move() = 0;


		//copy constructor
		Organism(const Organism& source);

		//= overload
		Organism& operator=(const Organism& source);

		//destructor
		virtual ~Organism() { delete[] surroundings; }

	private:
		//private variables for row and column, survival and starve counts, type, whether or not it has been moved in the given timestep, and its surroundings
		int row_pos;
		int column_pos;
		int survival_count;
		int starve_count;
		string organism_type;
		bool moved_flag;
		occupied_surroundings* surroundings;
};

//loaded Organism constructor definition
Organism::Organism(int row, int column, string type)
{
	//validate out of bounds positions are not entered and that valid count is provided
	if (row < 0 || row >= ROW_RANGE)
	{
		cout << "Illegal row position. Exiting Program";
		exit(1);
	}
	else if (column < 0 || column >= COLUMN_RANGE)
	{
		cout << "Illegal column position. Exiting Program";
		exit(1);
	}
	else
	{
		//set private variables equal to respective arguments passed to the constructor 
		row_pos = row;
		column_pos = column;
		survival_count = 0;
		starve_count = 0;

		//ensure the proper organism types have been passed
		if (type != "Organism" && type != "Ant" && type != "Doodlebug")
		{
			cout << "Incorrect Organism type entered. Exiting Program";
			exit(1);
		}
		else
		{
			organism_type = type;
		}
		moved_flag = false;
		surroundings = new occupied_surroundings[MOVEMENT_CHOICES];
	}
}

//loaded Organism constructor definition
Organism::Organism(int row, int column, int count, string type, bool moved, int starve)
{
	//validate out of bounds positions are not entered and that valid count is provided
	if (row < 0 || row >= ROW_RANGE)
	{
		cout << "Illegal row position. Exiting Program";
		exit(1);
	}
	else if (column < 0 || column >= COLUMN_RANGE)
	{
		cout << "Illegal column position. Exiting Program";
		exit(1);
	}
	else if (count < 0)
	{
		cout << "Illegal count. Exiting Program";
		exit(1);
	}
	else
	{
		//set private variables equal to respective arguments passed to the constructor 
		row_pos = row;
		column_pos = column;
		survival_count = count;
		starve_count = starve;
		
		//ensure the proper organism types have been passed
		if (type != "Organism" && type != "Ant" && type != "Doodlebug")
		{
			cout << "Incorrect Organism type entered. Exiting Program";
			exit(1);
		}
		else
		{
			organism_type = type;
		}
		moved_flag = moved;
		surroundings = new occupied_surroundings[MOVEMENT_CHOICES];
	}
}

//copy constructor
Organism::Organism(const Organism& source)
{
	//set this variables equal to those from source organism
	row_pos = source.row_pos;
	column_pos = source.column_pos;
	survival_count = source.survival_count;
	starve_count = source.starve_count;
	organism_type = source.organism_type;
	moved_flag = source.moved_flag;
	surroundings = new occupied_surroundings[MOVEMENT_CHOICES];

	for (int i = 0; i < MOVEMENT_CHOICES; i++)
	{
		surroundings[i] = source.surroundings[i];
	}
}

//overload = operator
Organism& Organism::operator=(const Organism& source)
{
	//check we aren't setting the same object equal to itself
	if (this == &source)
	{
		return *this;
	}

	//set this variables equal to those from source organism
	row_pos = source.row_pos;
	column_pos = source.column_pos;
	survival_count = source.survival_count;
	starve_count = source.starve_count;
	organism_type = source.organism_type;
	moved_flag = source.moved_flag;

	for (int i = 0; i < MOVEMENT_CHOICES; i++)
	{
		surroundings[i] = source.surroundings[i];
	}
	return *this;
}


//Ant class definition - derived class of Organism
class Ant : public Organism
{
	public:
		//constructors
		Ant() : Organism() { }
		Ant(int row, int column, string type) : Organism(row, column, type) { }
		Ant(int row, int column, int count, string type, bool moved, int starve) : Organism(row, column, count, type, moved, starve) { }

		//virtual functions
		virtual void move();


		//copy constructor
		Ant(const Ant& source) : Organism(source) { }

		//=overload
		Ant& operator=(const Ant& source);

		//destructor
		virtual ~Ant() { }
};

//overload = operator
Ant& Ant::operator=(const Ant& source)
{
	Organism::operator=(source);
	return *this;
}

//Ant class move function definition - does not take any arguments as instructed on Piazza
void Ant::move()
{
	//create a bool variable to store whether or not the Ant has moved in the current timestep
	bool moved = Organism::get_moved_flag();

	//if the ant hasn't already moved in this timestep, evaluate if and where it will move
	if (!moved)
	{
		//create variables to store the ant's position on the grid
		int row = Organism::get_row_pos();
		int column = Organism::get_column_pos();

		//determine the random movement the ant will attempt
		int movement = rand() % MOVEMENT_CHOICES;

		//declare a variable to store whether or not the proposed move is to a position on the grid that is not occupied
		bool not_occupied;

		//evaluate the random movement and see if the ant can execute that move without going of the grid or moving to an occupied position
		if (movement == LEFT)
		{
			//if column is at the left edge we cannot move left, otherwise the organism would go off the board
			if (column != 0)
			{
				//check if it is occupied, if it is you cannot move. If it isn't move left
				not_occupied = !Organism::get_occupied_surroundings(LEFT);
				if (not_occupied)
				{
					Organism::set_column_pos(column - 1);
				}
			}
		}
		else if (movement == RIGHT)
		{
			//if column is at the right edge we cannot move right, otherwise the organism would go off the board
			if (column != COLUMN_RANGE - 1)
			{
				//check if it is occupied, if it is you cannot move. If it isn't move right
				not_occupied = !Organism::get_occupied_surroundings(RIGHT);
				if (not_occupied)
				{
					Organism::set_column_pos(column + 1);
				}
			}
		}
		else if (movement == UP)
		{
			//if row is at the top edge we cannot move up, otherwise the organism would go off the board
			if (row != 0)
			{
				//check if it is occupied, if it is you cannot move. If it isn't move up
				not_occupied = !Organism::get_occupied_surroundings(UP);
				if (not_occupied)
				{
					Organism::set_row_pos(row - 1);
				}
			}
		}
		else
		{
			//if row is at the bottom edge we cannot move down, otherwise the organism would go off the board
			if (row != ROW_RANGE-1)
			{
				//check if it is occupied, if it is you cannot move. If it isn't move down
				not_occupied = !Organism::get_occupied_surroundings(DOWN);
				if (not_occupied)
				{
					Organism::set_row_pos(row + 1);
				}
			}
		}

		//After the ant has moved, update survival count for breeding purposes
		int current_survival_count = Organism::get_survival_count();
		current_survival_count++;
		Organism::set_survival_count(current_survival_count);

		//update the move flag to signify the ant has moved
		Organism::set_moved_flag(1);
		moved = true;
	}
}

//Doodlebug class definition - derived class of Organism
class Doodlebug : public Organism
{
	public:
		//constructors
		Doodlebug() : Organism() { }
		Doodlebug(int row, int column, string type) : Organism(row, column, type) { }
		Doodlebug(int row, int column, int count, string type, bool moved,int starve) : Organism(row, column, count, type, moved,starve) { }

		//virtual functions
		virtual void move();

		//copy constructor
		Doodlebug(const Doodlebug& source) : Organism(source) { }

		//=overload
		Doodlebug& operator=(const Doodlebug& source);

		//destructor
		virtual ~Doodlebug() { }
};

//overload = operator
Doodlebug& Doodlebug::operator=(const Doodlebug& source)
{
	Organism::operator=(source);
	return *this;
}

//Doodlebug class move function definition - does not take any arguments as instructed on Piazza
void Doodlebug::move()
{
	//create a bool variable to store whether or not the Doodlebug has moved in the current timestep
	bool moved = Organism::get_moved_flag();

	//if the Doodlebug hasn't already moved in this timestep, evaluate if and where it will move
	if (!moved)
	{
		//determine if there are surrounding ants which can be eaten
		int surrounding_ant_count = 0;

		if (Organism::get_occupied_surroundings_type(LEFT) == "Ant")
		{
			surrounding_ant_count++;
		}
		if (Organism::get_occupied_surroundings_type(RIGHT) == "Ant")
		{
			surrounding_ant_count++;
		}
		if (Organism::get_occupied_surroundings_type(UP) == "Ant")
		{
			surrounding_ant_count++;
		}
		if (Organism::get_occupied_surroundings_type(DOWN) == "Ant")
		{
			surrounding_ant_count++;
		}

		//create variables to store the doodlebug's position on the grid
		int row = Organism::get_row_pos();
		int column = Organism::get_column_pos();

		//create a variable for the random movement, and starve count
		int movement;
		int updated_starve_count = Organism::get_starve_count();


		//if there is an ant in the doodlebug's surroundings it will eat it. If there is more than one ant it will randomly choose one to eat
		if (surrounding_ant_count >= 1)
		{
			bool random_ant_found = false;
			while (!random_ant_found)
			{
				movement = rand() % MOVEMENT_CHOICES;
				if (Organism::get_occupied_surroundings_type(LEFT) == "Ant" && movement == LEFT)
				{
					Organism::set_column_pos(column - 1);
					random_ant_found = true;
				}
				else if (Organism::get_occupied_surroundings_type(RIGHT) == "Ant" && movement == RIGHT)
				{
					Organism::set_column_pos(column + 1);
					random_ant_found = true;
				}
				else if (Organism::get_occupied_surroundings_type(UP) == "Ant" && movement == UP)
				{
					Organism::set_row_pos(row - 1);
					random_ant_found = true;
				}
				else if (Organism::get_occupied_surroundings_type(DOWN) == "Ant" && movement == DOWN)
				{
					Organism::set_row_pos(row + 1);
					random_ant_found = true;
				}
			}

			//If an ant is eaten, reset starve count to 0
			updated_starve_count = 0;
			Organism::set_starve_count(updated_starve_count);
		}
		//if there are no ants in the doodlebug's surroundings, a random move will be generated and evaluated much like that of an ant (comments above)
		else
		{
			//evaluate the proposed move to ensure it doesn't go off the grid or to a position occupied by another doodlebug
			movement = rand() % MOVEMENT_CHOICES;
			bool not_occupied;
			
			if (movement == LEFT)
			{
				if (column != 0)
				{
					not_occupied = !Organism::get_occupied_surroundings(LEFT);
					if (not_occupied)
					{
						Organism::set_column_pos(column - 1);
					}
				}
			}
			else if (movement == RIGHT)
			{
				if (column != COLUMN_RANGE - 1)
				{
					not_occupied = !Organism::get_occupied_surroundings(RIGHT);
					if (not_occupied)
					{
						Organism::set_column_pos(column + 1);
					}	
				}
			}
			else if (movement == UP)
			{
				if (row != 0)
				{
					not_occupied = !Organism::get_occupied_surroundings(UP);
					if (not_occupied)
					{
						Organism::set_row_pos(row - 1);
					}
				}
			}
			else
			{
				if (row != ROW_RANGE - 1)
				{
					not_occupied = !Organism::get_occupied_surroundings(DOWN);
					if (not_occupied)
					{
						Organism::set_row_pos(row + 1);
					}
				}
			}
			//If there are no surrounding ants, increase starve count
			updated_starve_count++;
			Organism::set_starve_count(updated_starve_count);
		}
		//Update doodlebug survival count
		int current_survival_count = Organism::get_survival_count();
		current_survival_count++;
		Organism::set_survival_count(current_survival_count);
		
		//update the move flag for the current timestep
		Organism::set_moved_flag(1);
		moved = true;
	}
}




typedef Organism* organism_ptr;

//Prints instructions for the user
void print_instructions();

//initialize_environment is a void function that receives an organism*** by reference
//The function will then generate the const int defined number of ants and doodlebugs at random locations on the grid
void initialize_environment(organism_ptr**& environment);

//update_surroundings is a void function that receives an organism*** by reference
//The function will iterate through each position on the grid and update the surroundings for each organism that exists
void update_surroundings(organism_ptr**& environment);

//print_environment is a void function that receives an organism*** by reference
//The function will print the grid and its organisms to the user
void print_environment(organism_ptr**& environment);

//environment_time_step is a void function that receives an organism*** by reference
//The function simulates a timestep in the environment in which doodlebugs move first and ants second
//After each valid move occurs the environment will be updated as well as the surroundings of each existing organism on the grid
//After all moves have occurred, breeding and death will occur when applicable and the grid and surroundings will be updated
//Finally, the move flags will be reset before the next timestep
void environment_time_step(organism_ptr**& environment); 

//update_environment is a void function that receives an organism*** by reference, and row and column positions
//When an organism moves, this function updates the grid accordingly
void update_environment(organism_ptr**& environment, int row, int column);

//breed_organisms is a void function that receives an organism*** by reference
//The function determines which organisms are eligible for breeding and then spawns offa new organism of the same type in a surrounding location (assuming there is an open location)
void breed_organisms(organism_ptr**& environment);

//open_position_count is a function that receives an organism* by reference to a specific organism and returns an int with how many open positions surround it
//The function is a helper function to breed_organisms in determining if there are open positions surrounding the organism and how many
int open_position_count(organism_ptr& org);

//determine_breed_location is a function that receives an organism* by reference to a specific organism and returns an int with the location at which the organism should place its offspring
//The function is a helper function to breed_organisms in determining where the organism should breed in its surroundings
int determine_breed_location(organism_ptr& org);

//remove_doodlebugs is a void function that receives an organism*** by reference
//After each respective timestep the function evaluates if there are any doodlebugs that have starved and should be removed from the grid
void remove_doodlebugs(organism_ptr**& environment);

//reset_move_flags is a void function that receives an organism*** by reference
//After each respective timestep the flags are reset so the organisms can move again. This ensures an organism only moves once every timestep
void reset_move_flags(organism_ptr**& environment);


int main()
{
	//output instructions to the user
	print_instructions();

	//initialize random seed to be used throughout the program for movement and placement of initial creatures
	srand((unsigned)time(0));

	//create 2-d array for the grid/environment the organisms will live on
	organism_ptr** org_environment = new organism_ptr*[ROW_RANGE];
	for (int i = 0; i < ROW_RANGE; i++)
	{
		org_environment[i] = new organism_ptr[COLUMN_RANGE];
	}
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			//set every pointer to null until initialized
			org_environment[i][j] = nullptr;
		}
	}

	//initialize the environnment with the const number of ants and doodlebugs defined - this will update their surroundings and print the initial environment to the user
	initialize_environment(org_environment);
	
	//prompt the user to hit 'enter' to see the next time step and type exit when they want to end the program
	string user_entry;
	bool continue_flag = true;
	int count = 1;
	while (continue_flag)
	{
		getline(cin, user_entry);
		if (user_entry == "exit")
		{
			continue_flag = false;
		}
		else
		{
			if (user_entry.length() > 0)
			{
				cout << "You have entered something other than 'exit' or just the 'enter' key. We will assume you want to continue" << endl;
			}
			cout << "Time Step #" << count << ":" << endl;
			environment_time_step(org_environment);
			count++;
		}
	}
	
	//free up the dynamically allocated heap memory used to store the grid's contents
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			delete org_environment[i][j];
		}
		delete[] org_environment[i];
	}
	delete[] org_environment;
	
	return 0;
}

void print_instructions()
{
	cout << "Welcome to Ben's Doodlebug vs. Ant Simulator!" << endl;
	cout << "Below is an initialized printout of a 20 X 20 world of Organisms with " << INITIAL_DOODLEBUG_POPULATION << " Doodlebugs and " << INITIAL_ANT_POPULATION << " Ants" << endl;
	cout << "Press 'enter' to continue to the next time step of the simulation or type 'exit' to end the simulation\n" << endl;
	cout << "Initial table - Time Step #0:" << endl;
}

void initialize_environment(organism_ptr**& environment)
{
	//declare initial counts of ants and doodlebugs, and variables for the random positions for placement
	int ant_count = 0, doodlebug_count = 0;
	int random_row, random_column;

	//initialize the world with 100 ants at random locations that are not occupied by other organisms
	while (ant_count < INITIAL_ANT_POPULATION)
	{
		random_row = rand() % ROW_RANGE;
		random_column = rand() % COLUMN_RANGE;

		if (environment[random_row][random_column] == nullptr)
		{
			environment[random_row][random_column] = new Ant(random_row, random_column, "Ant");
			ant_count++;
		}
	}

	//initialize the world with 5 doodlebugs at random locations that are not occupied by other organisms
	while (doodlebug_count < INITIAL_DOODLEBUG_POPULATION)
	{
		random_row = rand() % ROW_RANGE;
		random_column = rand() % COLUMN_RANGE;

		if (environment[random_row][random_column] == nullptr)
		{
			environment[random_row][random_column] = new Doodlebug(random_row, random_column, "Doodlebug");
			doodlebug_count++;
		}
	}

	//after we have initialized the grid, we will update the surroundings of each organism in the environment and then print the environment to the user
	update_surroundings(environment);
	print_environment(environment);
}

void update_surroundings(organism_ptr**& environment)
{
	//iterate through each organism in the grid and update its surroundings
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				//These are the following cases that need to be evaluated
				//1. Corners (top left, top right, bottom left, and bottom right)
				//2. Non-corner positions in the top row, bottom row, leftmost column, rightmost column
				//3. Everything else

				//top row
				if (i == 0)
				{
					//top left corner
					if (j == 0)
					{
						//column to the right, row below respectively for if-else branches
						if (environment[i][j + 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, true, environment[i][j + 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, false, "");
						}

						if (environment[i + 1][j] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(DOWN, true, environment[i + 1][j]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(DOWN, false, "");
						}
					}

					//top right corner
					else if (j == COLUMN_RANGE - 1)
					{
						//column to the left, row below respectively for if-else branches
						if (environment[i][j - 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(LEFT, true, environment[i][j - 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(LEFT, false, "");
						}

						if (environment[i + 1][j] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(DOWN, true, environment[i + 1][j]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(DOWN, false, "");
						}
					}
					
					//rest of the top row
					else
					{
						//column to the right, column to the left, row below respectively for if-else branches
						if (environment[i][j + 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, true, environment[i][j + 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, false, "");
						}

						if (environment[i][j - 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(LEFT, true, environment[i][j - 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(LEFT, false, "");
						}

						if (environment[i + 1][j] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(DOWN, true, environment[i + 1][j]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(DOWN, false, "");
						}
					}
				}

				//bottom row - comments follow those in the top row section above
				else if (i == ROW_RANGE - 1)
				{
					if (j == 0)
					{
						if (environment[i][j + 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, true, environment[i][j + 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, false, "");
						}

						if (environment[i - 1][j] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(UP, true, environment[i - 1][j]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(UP, false, "");
						}
					}
					else if (j == COLUMN_RANGE - 1)
					{
						if (environment[i][j - 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(LEFT, true, environment[i][j - 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(LEFT, false, "");
						}

						if (environment[i - 1][j] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(UP, true, environment[i - 1][j]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(UP, false, "");
						}
					}
					else
					{
						if (environment[i][j + 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, true, environment[i][j + 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(RIGHT, false, "");
						}

						if (environment[i][j - 1] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(LEFT, true, environment[i][j - 1]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(LEFT, false, "");
						}

						if (environment[i - 1][j] != nullptr)
						{
							environment[i][j]->set_occupied_surroundings(UP, true, environment[i - 1][j]->get_type());
						}
						else
						{
							environment[i][j]->set_occupied_surroundings(UP, false, "");
						}
					}
				}

				//leftmost column - comments follow those in the top row section above
				else if (j == 0)
				{
					if (environment[i][j + 1] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(RIGHT, true, environment[i][j + 1]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(RIGHT, false, "");
					}

					if (environment[i - 1][j] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(UP, true, environment[i - 1][j]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(UP, false, "");
					}

					if (environment[i + 1][j] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(DOWN, true, environment[i + 1][j]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(DOWN, false, "");
					}
				}

				//rightmost column - comments follow those in the top row section above
				else if (j == COLUMN_RANGE - 1)
				{
					if (environment[i][j - 1] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(LEFT, true, environment[i][j - 1]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(LEFT, false, "");
					}

					if (environment[i - 1][j] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(UP, true, environment[i - 1][j]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(UP, false, "");
					}

					if (environment[i + 1][j] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(DOWN, true, environment[i + 1][j]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(DOWN, false, "");
					}
				}

				//non-edge positions - comments follow those in the top row section abov
				else
				{
					if (environment[i][j - 1] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(LEFT, true, environment[i][j - 1]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(LEFT, false, "");
					}

					if (environment[i][j + 1] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(RIGHT, true, environment[i][j + 1]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(RIGHT, false, "");
					}

					if (environment[i - 1][j] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(UP, true, environment[i - 1][j]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(UP, false, "");
					}

					if (environment[i + 1][j] != nullptr)
					{
						environment[i][j]->set_occupied_surroundings(DOWN, true, environment[i + 1][j]->get_type());
					}
					else
					{
						environment[i][j]->set_occupied_surroundings(DOWN, false, "");
					}
				}
			}
		}
	}
}

void print_environment(organism_ptr**& environment)
{
	//print borderline * to display the edges of the grid above and below and at the beginning and end of each row
	for (int i = 0; i < COLUMN_RANGE + 2; i++)
	{
		cout << "*";
	}
	cout << endl;

	//If there is an ant, output 'o', if it is a doodlebug 'X', otherwise a blank space
	for (int i = 0; i < ROW_RANGE; i++)
	{
		cout << "*";
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				if (environment[i][j]->get_type() == "Ant")
				{
					cout << "o";
				}
				else
				{
					cout << "X";
				}
			}
			else
			{
				cout << " ";
			}
		}
		cout << "*";
		cout << endl;
	}

	for (int i = 0; i < COLUMN_RANGE + 2; i++)
	{
		cout << "*";
	}
	cout << endl;
}

void environment_time_step(organism_ptr**& environment)
{
	//doodlebugs move first
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				if (environment[i][j]->get_type() == "Doodlebug")
				{
					environment[i][j]->move();
					if (environment[i][j]->get_row_pos() != i || environment[i][j]->get_column_pos() != j)
					{
						update_environment(environment, i, j);
						update_surroundings(environment);
					}
				}
			}
		}
	}

	//ants move second
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				if (environment[i][j]->get_type() == "Ant")
				{
					environment[i][j]->move();
					if (environment[i][j]->get_row_pos() != i || environment[i][j]->get_column_pos() != j)
					{
						update_environment(environment, i, j);
						update_surroundings(environment);
					}
				}
			}
		}
	}

	//after all the moves have occurred, evaluate if organisms can breed and if they have starved
	
	//calls update surroundings after each breed
	breed_organisms(environment);

	//remove any doodlebugs that have died from the grid, and then update surroundings
	remove_doodlebugs(environment);
	update_surroundings(environment);

	//reset the move flags and print the environment to the user
	reset_move_flags(environment);
	print_environment(environment);
}

void update_environment(organism_ptr**& environment, int row, int column)
{
	//create variables to store the necessary information from the organism before updating the grid
	int updated_row = environment[row][column]->get_row_pos();
	int updated_column = environment[row][column]->get_column_pos();
	int surv_count = environment[row][column]->get_survival_count();
	string org_type = environment[row][column]->get_type();
	int starve = environment[row][column]->get_starve_count();

	//once we know the ant has moved, we will remove the old organism and create a new one in the new location on the grid
	if (environment[row][column]->get_type() == "Ant")
	{
		environment[updated_row][updated_column] = new Ant(updated_row, updated_column, surv_count, org_type, 1, starve);
	}
	else
	{
		//Evaluate if there is an existing ant at the location where the doodlebug will move. If there is remove it and then create new doodlebug
		if (environment[updated_row][updated_column] != nullptr)
		{
			delete environment[updated_row][updated_column];
			environment[updated_row][updated_column] = nullptr;
		}
		environment[updated_row][updated_column] = new Doodlebug(updated_row, updated_column, surv_count, org_type, 1, starve);
	}

	delete environment[row][column];
	environment[row][column] = nullptr;
}

void breed_organisms(organism_ptr**& environment)
{
	//iterate through each position on the grid and check if there is an organism at that position that has survived long enough to breed
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				string type = environment[i][j]->get_type();
				int surv_count = environment[i][j]->get_survival_count();

				if ((type == "Doodlebug" && surv_count >= DOODLEBUG_SURVIVAL_COUNT) || (type == "Ant" && surv_count >= ANT_SURVIVAL_COUNT))
				{
					//if the organism can breed determine if there are any open positions in its surroundings where the spawn can be placed
					int open_pos_count = open_position_count(environment[i][j]);

					if (open_pos_count >= 1)
					{
						//if there is at least one open position determine which position the spawn should be placed in
						int breed_location = determine_breed_location(environment[i][j]);
						int row = i, column = j;

						if (breed_location == LEFT)
						{
							column--;
						}
						else if (breed_location == RIGHT)
						{
							column++;
						}
						else if (breed_location == UP)
						{
							row--;
						}
						else
						{
							row++;
						}

						//create a new organism of the relevant type at the determined location
						if (type == "Doodlebug")
						{
							environment[row][column] = new Doodlebug(row, column, type);
						}
						else
						{
							environment[row][column] = new Ant(row, column, type);
						}
						//recent the parent organisms survival count to 0 so it must wait the necessary time before producing another offspring
						environment[i][j]->set_survival_count(0);

						//call update surroundings so that all organisms know what is around them once a new organism has entered the grid
						update_surroundings(environment);
					}
				}
			}
		}
	}
}

int open_position_count(organism_ptr& org)
{
	int open_count = 0;
	int row = org->get_row_pos();
	int column = org->get_column_pos();

	//determine if each respective surrounding position of the organism in question is on the board or not. If it is and it is open increment the open_count
	if (!org->get_occupied_surroundings(LEFT) && column != 0)
	{
		open_count++;
	}
	if (!org->get_occupied_surroundings(RIGHT) && column != COLUMN_RANGE - 1)
	{
		open_count++;
	}
	if (!org->get_occupied_surroundings(UP) && row != 0)
	{
		open_count++;
	}
	if (!org->get_occupied_surroundings(DOWN) && row != ROW_RANGE - 1)
	{
		open_count++;
	}
	//return the number of open positions available for breeding
	return open_count;
}

int determine_breed_location(organism_ptr& org)
{
	int row = org->get_row_pos();
	int column = org->get_column_pos();

	bool found = false;
	int ret_val;
	
	//if there are open positions to breed in, randomly determine which location to breed in and return that value
	while (!found)
	{
		int movement = rand() % MOVEMENT_CHOICES;
		if (movement == LEFT && !org->get_occupied_surroundings(LEFT) && column != 0)
		{
			ret_val = LEFT;
			found = true;
		}
		else if (movement == RIGHT && !org->get_occupied_surroundings(RIGHT) && column != COLUMN_RANGE - 1)
		{
			ret_val = RIGHT;
			found = true;
		}
		else if (movement == UP && !org->get_occupied_surroundings(UP) && row != 0)
		{
			ret_val = UP;
			found = true;
		}
		else if (movement == DOWN && !org->get_occupied_surroundings(DOWN) && row != ROW_RANGE-1)
		{
			ret_val = DOWN;
			found = true;
		}
	}
	return ret_val;
}

void remove_doodlebugs(organism_ptr**& environment)
{
	//iterate through the environment. If there is a doodlebug at the given position that has starved remove it from the environment 
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				if (environment[i][j]->get_type() == "Doodlebug" && environment[i][j]->get_starve_count() == DOODLEBUG_STARVE_COUNT)
				{
					delete environment[i][j];
					environment[i][j] = nullptr;
				}
			}
		}
	}
}

void reset_move_flags(organism_ptr**& environment)
{
	//iterate through the grid - if there is an organism at the given position, reset the move flag
	for (int i = 0; i < ROW_RANGE; i++)
	{
		for (int j = 0; j < COLUMN_RANGE; j++)
		{
			if (environment[i][j] != nullptr)
			{
				environment[i][j]->set_moved_flag(false);
			}
		}
	}
}