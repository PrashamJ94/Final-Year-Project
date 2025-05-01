
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct st_node ST_NODE;
typedef struct st_node
{
	ST_NODE* st_parent;
	ST_NODE* st_left;
	ST_NODE* st_right;
	int s4_key;
};

void insert(ST_NODE**, int);
void print(ST_NODE*);
static void printPreOrder(ST_NODE*);
static void printInOrder(ST_NODE*);
ST_NODE* newST_NODE(int);

int main()
{
	ST_NODE* st_root;
	int numCommand;
	string command;
	int insertKey;

	st_root = nullptr;

	// Number of commands
	cin >> numCommand;

	// Execute commands
	for (int i = 0; i < numCommand; i++)
	{
		// Command (insert or print)
		cin >> command;

		// Execute command
		if (command == "insert")
		{
			// Insert key value
			cin >> insertKey;
			insert(&st_root, insertKey);
		}
		else
		{
			print(st_root);
		}
	}

	return 0;
}

void insert(ST_NODE** st_root, int key)
{
	ST_NODE* parentNode;
	ST_NODE* indexNode;
	ST_NODE* insertNode;

	insertNode = newST_NODE(key);

	parentNode = nullptr;
	indexNode = *st_root;

	while (indexNode != nullptr)
	{
		parentNode = indexNode;
		if (insertNode->s4_key < indexNode->s4_key)
		{
			indexNode = indexNode->st_left;
		}
		else
		{
			indexNode = indexNode->st_right;
		}
	}
	insertNode->st_parent = parentNode;

	if (parentNode == nullptr)
	{
		*st_root = insertNode;
	}
	else if (key < parentNode->s4_key)
	{
		parentNode->st_left = insertNode;
	}
	else
	{
		parentNode->st_right = insertNode;
	}
}

void print(ST_NODE* st_root)
{
	printInOrder(st_root);
	cout << endl;
	printPreOrder(st_root);
	cout << endl;
}

static void printPreOrder(ST_NODE* st_node)
{
	if (st_node == nullptr)
	{
		return;
	}

	cout << " " << st_node->s4_key;
	printPreOrder(st_node->st_left);
	printPreOrder(st_node->st_right);
}

static void printInOrder(ST_NODE* st_node)
{
	if (st_node == nullptr)
	{
		return;
	}

	printInOrder(st_node->st_left);
	cout << " " << st_node->s4_key;
	printInOrder(st_node->st_right);
}

ST_NODE* newST_NODE(int key)
{
	ST_NODE* st_node;
	st_node = new ST_NODE;
	st_node->st_parent = nullptr;
	st_node->st_left = nullptr;
	st_node->st_right = nullptr;
	st_node->s4_key = key;

	return st_node;
}


