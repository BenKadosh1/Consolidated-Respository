//File name: bk1139_hw17_q1.cpp
//Author: Ben Kadosh
//Email address: bk1139@nyu.edu
//Assignment number: hw17_q1

#include <iostream>
#include <ctime>
#include <queue>
#include <string>

using namespace std;

//create const bool variables for red and black color designation
const bool RED = false, BLACK = true;

template <class T>
class RBTree;


//max functions two objects of type T
template <class T>
T& max(T& left, T& right) 
{
	if (left > right)
		return left;
	else
		return right;
}
template <class T>
T max(const T& left, const T& right) 
{
	if (left > right)
		return left;
	else
		return right;
}

//RBTreeNode class for each node in the tree - stores T data, the color, height, parent, left and right children of the node
template <class T>
class RBTreeNode {
	RBTreeNode<T>* parent;
	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	bool color;
	int height;
	T data;
public:
	friend class RBTree < T >;
	RBTreeNode(const T& new_data = T(), RBTreeNode<T>* new_parent = nullptr, RBTreeNode<T>* new_left = nullptr, RBTreeNode<T>* new_right = nullptr, bool new_color = RED) :
		data(new_data), parent(new_parent), left(new_left), right(new_right), color(new_color) {calcHeight();}

	void calcHeight();
	int size()const;
	int depth() const;
};

//RBTreeNode function to calculate the depth of the node
template <class T>
int RBTreeNode<T>::depth() const
{
	int parentDepth = -1;
	if (parent != nullptr)
		parentDepth = parent->depth();
	return 1 + parentDepth;
}

//RBTreeNode function to calculate the size of tree(subtree)
template <class T>
int RBTreeNode<T>::size() const
{
	int leftSize = 0;
	int rightSize = 0;
	if (left != nullptr)
		leftSize = left->size();
	if (right != nullptr)
		rightSize = right->size();
	return 1 + leftSize + rightSize;
}

//RBTreeNode function to calculate the height of a given node
template <class T>
void RBTreeNode<T>::calcHeight()
{
	int leftHeight = -1;
	int rightHeight = -1;
	if (left != nullptr)
		leftHeight = left->height;
	if (right != nullptr)
		rightHeight = right->height;
	height = max(leftHeight, rightHeight) + 1;
	if (parent)
		parent->calcHeight();
}


//define the class for the RBTree which will store a pointer to the root node and manage the tree
template <class T>
class RBTree {
	RBTreeNode<T>* root;
	int size;
	RBTreeNode<T>* recursiveCopy(RBTreeNode<T>* toCopy);
	int heightDiff(RBTreeNode<T>* point);
	
	//rotation of RBTreeNodes
	void singleCCR(RBTreeNode<T>*& point);
	void singleCR(RBTreeNode<T>*& point);
	
	//function to call necessary rotations and adjust color
	void rotate_and_adjust_color(RBTreeNode<T>* point);
public:
	RBTree() :size(0) { root = nullptr; }

	//Big 3
	RBTree(const RBTree<T>& rhs) :root(nullptr) { *this = rhs; }
	virtual ~RBTree() { clear();}
	RBTree& operator=(const RBTree<T>& rhs);

	//define supporting functions to find whether T is in the tree, if the tree is empty, what the size of the tree is
	bool isInTree(const T& toFind) const { return find(toFind) != nullptr; }
	bool isEmpty()const { return root == nullptr; }
	int getSize()const { return size; }
	RBTreeNode<T>* find(const T& toFind) const;

	//removal of nodes from the tree
	void remove(const T& toRemove) {
		RBTreeNode<T>* item = find(toRemove);
		if (item != nullptr)
			remove(item);
	}
	void remove(RBTreeNode<T>*);
	void clear() { while (!isEmpty()) remove(root); }

	//declaration of insert functions
	void insert(const T&);
	void insert(const T&, RBTreeNode<T>*& point);
	
	//function declaration to print level order of the tree
	void printLevelOrder()const;
};

//print level order pushes nodes into the queue by level the left and right child of the node at that level are pushed as are any others
//before the function iterates down to the next level of the tree
template <class T>
void RBTree<T>::printLevelOrder() const {
	
	//create a queue to store the RBTreeNode pointers to each node we want to store in the queue
	queue<RBTreeNode<T>*> q;

	//push the root
	q.push(root);

	//while the queue isn't empty check if there are children to push to the queue as well as popping current item
	while (!q.empty()) {
		RBTreeNode<T>* front = q.front();
		
		//store the color of the node and print it out to the user as well
		string color;
		if (front->color)
		{
			color = "Black";
		}
		else
		{
			color = "Red";
		}

		cout << "Data: " << front->data << "  \tHeight: " << front->height << "  \tColor: " << color << endl;
		
		//if the node has a left and or right child push those to the queue
		if (front->left != nullptr)
			q.push(front->left);
		if (front->right)
			q.push(front->right);
		//pop current so we can iterate to the next nodes in the queue
		q.pop();
	}
}

//rotation clockwise of the node
//we will update the necessary pointers of the parent and grandparent to adjust children and parent pointers of each 
//as well as any of the children's pointers where necessary
template <class T>
void RBTree<T>::singleCR(RBTreeNode<T>*& point) {
	//create parent and grandparent pointers to the relevant nodes
	RBTreeNode<T>* grandparent = point;
	RBTreeNode<T>* parent = point->left;
	
	//update parent's parent, grandparent's parent, grandparent's left and parent's right in this case because it is a clockwise rotation
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->left = parent->right;
	parent->right = grandparent;

	//update necessary pointers in lower level to point to grandparent
	if (grandparent->left != nullptr) 
		grandparent->left->parent = grandparent;

	//if the new parent's parent is pointing to a nullptr it is the root so we will update the root pointer to point to this node
	if (parent->parent == nullptr)
		root = parent;
	//else we want to update the parent's left or right child pointer to point to parent 
	else if (parent->parent->left == grandparent)
		parent->parent->left = parent;
	else
		parent->parent->right = parent;

	grandparent->calcHeight();
	parent->calcHeight();
}

//similar to clockwise roatation above, but rotates counter clockwise
template <class T>
void RBTree<T>::singleCCR(RBTreeNode<T>*& point) {
	RBTreeNode<T>* grandparent = point;
	RBTreeNode<T>* parent = point->right;
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->right = parent->left;
	parent->left = grandparent;
	if (grandparent->right != nullptr)
		grandparent->right->parent = grandparent;
	if (parent->parent == nullptr)
		root = parent;
	else if (parent->parent->right == grandparent)
		parent->parent->right = parent;
	else
		parent->parent->left = parent;
	grandparent->calcHeight();
	parent->calcHeight();
}

//recursively copy the binary tree nodes and return a pointer to the copy version root node
template <class T>
RBTreeNode<T>* RBTree<T>::recursiveCopy(RBTreeNode<T>* toCopy) {
	//base case one we hit nullptrs
	if (toCopy == nullptr)
		return nullptr;

	//create a new node on the heap that copies the data from the current node this will recursively call itself and 
	//iterate down to the bottom of the tree and then work its way up
	RBTreeNode<T>* temp = new RBTreeNode<T>(toCopy->data, nullptr, recursiveCopy(toCopy->left), recursiveCopy(toCopy->right));
	if (temp->left != nullptr)
		temp->left->parent = temp;
	if (temp->right != nullptr)
		temp->right->parent = temp;
	return temp;
}

//big 3 = operator overload for the Binary Tree
template <class T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();

	//recursively copy the tree and then return the tree by reference
	root = recursiveCopy(rhs.root);
	size = rhs.size;
	return *this;
}

//function to remove nodes from the RBTree - a pointer to the node to be removed is passed
template <class T>
void RBTree<T>::remove(RBTreeNode<T>* toRemove) 
{
	if (root == nullptr)
		return; 

	//determine if the node we want to remove has 0, 1, or 2 children and update accordingly
	//in cases with two children we will look for a suitable replacement further down the tree that has no children

	//0 children
	if (toRemove->left == nullptr && toRemove->right == nullptr) { 
		if (toRemove->parent == nullptr) {
			root = nullptr;
		}
		else if (toRemove == toRemove->parent->left) 
			toRemove->parent->left = nullptr; 
		else
			toRemove->parent->right = nullptr;
		delete toRemove;
		size--;
	}

	//1 child to the left
	else if (toRemove->right == nullptr) { 
		if (toRemove->parent == nullptr) {
			root = toRemove->left;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left) { 
			toRemove->parent->left = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		else {
			toRemove->parent->right = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	// 1 child to the right
	else if (toRemove->left == nullptr) { 
		if (toRemove->parent == nullptr) {
			root = toRemove->right;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left) { 
			toRemove->parent->left = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		else {
			toRemove->parent->right = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}

	//2 children
	else { 
		RBTreeNode<T>* temp = toRemove->right;
		while (temp->left != nullptr)
			temp = temp->left;
		toRemove->data = temp->data;
		remove(temp);
	}
}

//find function definition passed a value by reference of type T to search for in the tree and returns a pointer to the node storing that data
template <class T>
RBTreeNode<T>* RBTree<T>::find(const T& toFind) const {
	
	//start at the root and iterate throguh the three either going left or right depending on value to traverse the tree 
	//if the value is found return a pointer to the node storing the value
	RBTreeNode<T>* temp = root;
	while (temp != nullptr && temp->data != toFind) {
		if (toFind < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

//calaculate the height difference for the the given subtree starting at point
template<class T>
int RBTree<T>::heightDiff(RBTreeNode<T>* point) {
	
	//set left and right height - iterate through the points chidlren to determine heights and return the difference
	int leftHeight = -1;
	int rightHeight = -1;
	if (point->left != nullptr)
		leftHeight = point->left->height;
	if (point->right != nullptr)
		rightHeight = point->right->height;
	return (abs(leftHeight - rightHeight));
}

//insert function to insert a value of Type T into the RBTree this will call the other insert funxtion with a pointer to the root tree node
template <class T>
void RBTree<T>::insert(const T& toInsert) 
{
	insert(toInsert, root);
}

//insert function 
template <class T>
void RBTree<T>::insert(const T& toInsert, RBTreeNode<T>*& point) {
	
	//determine if the root is a nullptr then insert the node at root and set the data based on the value passed - ensure color is black
	if (root == nullptr)
	{
		point = new RBTreeNode<T>(toInsert);
		rotate_and_adjust_color(point);
	}
	
	//else if we will traverse the tree until we find a suitable point to insert the node - when we do we will create a new node on the heap
	else if (point == nullptr)
	{
		point = new RBTreeNode<T>(toInsert);
	}

	//else if the data value is less than that at point data we will call insert on point->left and iterate down the tree until we find a 
	//suitable place to enter the node
	//once the node has been created and we return we will update the parent pointer of the node inserted
	//we will then call the rotate_and_adjust_color function to determine if there is a color violation and rotations need to be made
	//if yes the necessary adjustments will be made
	else if (toInsert < point->data) 
	{
		insert(toInsert, point->left);
		point->left->parent = point; 
		point->calcHeight();
		rotate_and_adjust_color(point);
	}

	//else instead of going left we will traverse to the right until we find a suitable point and then repeat the same steps as in 
	//the if else comments defined above
	else 
	{
		insert(toInsert, point->right);
		point->right->parent = point;
		point->calcHeight();
		rotate_and_adjust_color(point);
	}
}

template <class T>
void RBTree<T>::rotate_and_adjust_color(RBTreeNode<T>* point) 
{
	/*
		The function works as follows:
		We check for violations where a parent and child are both red 
		We then determine which of the four cases occur
		4 cases: Left Left, Left Right, Right Left, Right Right
		We then rotate as needed based on the cases
		The rotations include color adjustments and work as follows for each of the four cases
		Left Left - Single Clockwise Rotation
		Left Right - Single Counterclockwise rotation followed by a Single Clockwise Rotation
		Right Right - Single CounterClockwise Rotation
		Right Left - Single clockwise rotation followed by a Single CounterClockwise Rotation

		Special case: if parent and uncle are red, we change the color of parent, uncle, and grandparent and no rotations occur
	*/

	if (point == root)
	{
		root->color = BLACK;
	}

	if (point->color == RED)
	{
		//if point is red check whether it has two children or one child
		//if 2 children check which one is red
		if (point->left != nullptr && point->right != nullptr)
		{
			if (point->left->color == BLACK && point->right->color == BLACK)
			{
				//do nothing
			}
			else
			{
				while (point->color == RED)
				{
					//determine if the parent is the right or left child of the grandparent
					//left child
					if (point == point->parent->left)
					{
						RBTreeNode<T>* uncle = point->parent->right;
						//if there is no uncle
						if (uncle == nullptr)
						{
							//left left case
							if (point->left->color == RED)
							{
								//single rotation clockwise on grandparent - update color of parent and grandparent
								point->parent->color = RED;
								point->color = BLACK;
								singleCR(point->parent);

							}
							//left right case
							else
							{
								//rotate CCR on parent
								singleCCR(point);

								//update point of reference before second rotation
								point = point->parent;

								//single rotation clockwise on grandparent - update color of parent and grandparent
								point->parent->color = RED;
								point->color = BLACK;
								singleCR(point->parent);
							}
						}
						else
						{
							//if uncle isn't a nullptr check it's color if it is red we simply update colors
							if (uncle->color == RED)
							{
								uncle->color = BLACK;
								point->color = BLACK;
								point->parent->color = RED;
							}
							else
							{
								//left left case
								if (point->left->color == RED)
								{
									point->parent->color = RED;
									point->color = BLACK;
									singleCR(point->parent);

								}
								//left right case
								else
								{
									singleCCR(point);
									point = point->parent;
									point->parent->color = RED;
									point->color = BLACK;
									singleCR(point->parent);
								}
							}
						}
					}
					//right child
					else
					{
						RBTreeNode<T>* uncle = point->parent->left;
						if (uncle == nullptr)
						{
							//right right case
							if (point->right->color == RED)
							{
								point->parent->color = RED;
								point->color = BLACK;
								singleCCR(point->parent);

							}
							//right left case
							else
							{
								singleCR(point);
								point = point->parent;
								point->parent->color = RED;
								point->color = BLACK;
								singleCCR(point->parent);
							}
						}
						else
						{
							if (uncle->color == RED)
							{
								uncle->color = BLACK;
								point->color = BLACK;
								point->parent->color = RED;
							}
							else
							{
								//right right case
								if (point->right->color == RED)
								{
									point->parent->color = RED;
									point->color = BLACK;
									singleCCR(point->parent);
								}
								//right left case
								else
								{
									singleCR(point);
									point = point->parent;
									point->parent->color = RED;
									point->color = BLACK;
									singleCCR(point->parent);
								}
							}
						}
					}
				}
			}
			
		}

		//else - there is one child that has been inserted determine if it is a left or right child
		else
		{
			//if a left child has been inserted we can have left left or right left cases
			if (point->left != nullptr)
			{
				//if the child is black do nothing
				if (point->left->color == BLACK)
				{
					
				}
				else
				{
					while (point->color == RED)
					{
						//determine if the parent is the right or left child of the grandparent
						//left child
						if (point == point->parent->left)
						{
							RBTreeNode<T>* uncle = point->parent->right;
							if (uncle == nullptr)
							{
								//left left case - can only have this case becuase we know the child is left child and just proved parent is left child
								if (point->left->color == RED)
								{
									point->parent->color = RED;
									point->color = BLACK;
									singleCR(point->parent);
								}
							}
							else
							{
								//if uncle is red update colors
								if (uncle->color == RED)
								{
									uncle->color = BLACK;
									point->color = BLACK;
									point->parent->color = RED;
								}
								else
								{
									//left left case
									if (point->left->color == RED)
									{
										point->parent->color = RED;
										point->color = BLACK;
										singleCR(point->parent);

									}
								}
							}
						}
						//right child
						else
						{
							RBTreeNode<T>* uncle = point->parent->left;
							if (uncle == nullptr)
							{
								//right left case - we know the child is a left child and proved the parent is a right child
								if(point->left->color == RED)
								{
									singleCR(point);
									point = point->parent;
									point->parent->color = RED;
									point->color = BLACK;
									singleCCR(point->parent);
								}
							}
							else
							{
								if (uncle->color == RED)
								{
									uncle->color = BLACK;
									point->color = BLACK;
									point->parent->color = RED;
								}
								else
								{
									if(point->left->color == RED)
									{
										singleCR(point);
										point = point->parent;
										point->parent->color = RED;
										point->color = BLACK;
										singleCCR(point->parent);
									}
								}
							}
						}
					}
				}
			}
			//if a right child has been inserted we can have left right or right right cases
			else
			{
				if (point->right->color == BLACK)
				{
					//do nothing
				}
				else
				{
					while (point->color == RED)
					{
						//determine if the parent is the right or left child of the grandparent
						//left child
						if (point == point->parent->left)
						{
							RBTreeNode<T>* uncle = point->parent->right;
							if (uncle == nullptr)
							{
								//left right case
								if (point->right->color == RED)
								{
									singleCCR(point);
									point = point->parent;
									point->parent->color = RED;
									point->color = BLACK;
									singleCR(point->parent);
								}
							}
							else
							{
								if (uncle->color == RED)
								{
									uncle->color = BLACK;
									point->color = BLACK;
									point->parent->color = RED;
								}
								else
								{
									//left right case
									if (point->right->color == RED)
									{
										singleCCR(point);
										point = point->parent;
										point->parent->color = RED;
										point->color = BLACK;
										singleCR(point->parent);
									}
								}
							}
						}
						//right child
						else
						{
							RBTreeNode<T>* uncle = point->parent->left;
							if (uncle == nullptr)
							{
								//right right case
								if (point->right->color == RED)
								{
									point->parent->color = RED;
									point->color = BLACK;
									singleCCR(point->parent);
								}
							}
							else
							{
								if (uncle->color == RED)
								{
									uncle->color = BLACK;
									point->color = BLACK;
									point->parent->color = RED;
								}
								else
								{
									//right right case
									if (point->right->color == RED)
									{
										point->parent->color = RED;
										point->color = BLACK;
										singleCCR(point->parent);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


int main() 
{
	//create a red black tree of ints
	RBTree<int> b;
	srand(time(NULL));

	//create 30 random integers, if they are not already in the tree push them to the 
	for (int i = 0; i < 30; i++) 
	{
		int val = rand() % 300;
		
		//only insert unique values
		if (!b.isInTree(val))
		{
			//print the value being inserted and print the level order of the tree to that point
			cout << val << endl;
			b.insert(val);
			b.printLevelOrder();
			cout << endl;
		}
	}

	return 0;
}