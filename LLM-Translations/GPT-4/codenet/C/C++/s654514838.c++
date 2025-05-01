#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define NIL nullptr

typedef struct node{
	int key;
	int priority;
	struct node *right , *left;
}Node;

Node * Delete(Node **,int);
Node * delete_node(Node **,int);

int find(Node *p,int x)
{
	while(p!=NIL)
	{
		if(p->key==x)return 1;
		else if(p->key > x)p = p->left;
		else p = p->right;
	}
	return 0;
}

void inorder(Node *a)
{
	if(a->left!=NIL) inorder(a->left);
	printf(" %d",a->key);
	if(a->right!=NIL) inorder(a->right);
	return;
}

void preorder(Node *p)
{
	printf(" %d",p->key);
	if(p->left!=NIL) preorder(p->left);
	if(p->right!=NIL) preorder(p->right);
	return;
}

void print(Node *p)
{
	inorder(p);
	printf("\n");
	preorder(p);
	printf("\n");
	return;
}

Node * makenode(int x , int y)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->key = x;
	new_node->priority = y;
	new_node->left = NIL;
	new_node->right = NIL;
	return new_node;
}

Node *rightRotate(Node *p)
{
	Node *q = p->left;
	p->left = q->right;
	q->right = p;
	return q;
}

Node *leftRotate(Node *p)
{
	Node *q = p->right;
	p->right = q->left;
	q->left = p;
	return q;
}

Node* insert(Node **t , int key, int priority)  // Recursively searches
{
	Node *new_node;
	if((*t)==NIL)
	return new_node = makenode(key,priority); // If a leaf is reached, create a new node and return
	if((*t)->key == key)
	return *t;  // Ignore duplicate keys
	
	if(key < (*t)->key) // Move to left child
	{
		(*t)->left = insert(&(*t)->left,key,priority); // Update pointer to left child
		if((*t)->priority < (*t)->left->priority) // If left child has higher priority, rotate right
		(*t) = rightRotate(*t);
	}
	else{ // Move to right child
		(*t)->right = insert(&(*t)->right,key,priority); // Update pointer to right child
		if((*t)->priority < (*t)->right->priority) // If right child has higher priority, rotate left
		(*t) = leftRotate((*t));
	}
	return *t;
}

Node * Delete(Node **t , int key)
{
	if((*t)==NIL)
	return NIL;
	
	if(key < (*t)->key) // Search for the target to delete
	(*t)->left = Delete(&((*t)->left),key);
	
	else if(key > (*t)->key)
	(*t)->right = Delete(&((*t)->right),key);
	
	else return delete_node(t,key);
	return *t;
}

Node * delete_node(Node **t , int key)
{
	if((*t)->left == NIL && (*t)->right == NIL)  // If it's a leaf
	{
		return NIL;
	}
	else if((*t)->left == NIL) // If it has only a right child, rotate left
	{
		(*t) = leftRotate(*t);
	}
	else if((*t)->right ==NIL) // If it has only a left child, rotate right
	{
		(*t) = rightRotate(*t);
	}
	else{ // If it has both left and right children
		if((*t)->left->priority > (*t)->right->priority) // Lift the one with higher priority
		(*t) = rightRotate(*t);
		else
		(*t) = leftRotate(*t);
	}
	return Delete(t,key);
}

int main(void)
{
	int num ,  x, y;
	char com[8];
	Node *root = NIL;
	scanf("%d",&num);
	
	for(int i = 0; i < num; i++)
	{
		scanf("%s",com);
		switch(com[0])
		{
		  case 'i':scanf("%d %d",&x,&y);
			root = insert(&root,x,y);
			break;
		  case 'd':scanf("%d",&x);
			root = Delete(&root,x);
			break;
		  case 'f':scanf("%d",&x);
			if(find(root,x))printf("yes\n");
			else printf("no\n");
			break;
		  case 'p':print(root);
			break;
		}
	}
	return 0;
}

// 
