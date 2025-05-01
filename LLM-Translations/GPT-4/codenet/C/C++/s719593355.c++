#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node{
  unsigned int key;
  Node *next;
  Node *prev;
};

typedef Node* NodePointer;

NodePointer nil;

NodePointer listSearch(int);
void init(void);
void printList(void);
void deleteNode(NodePointer);
void deleteFirst(void);
void deleteLast(void);
void deleteKey(int);
void insert(int);

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  
  cin >> n;
  
  init();
  
  for (i = 0;i < n;i++){
    cin >> com >> key;
    
    if (com[0] == 'i') {
      insert(key); np++;
      size++;
    }
    
    else if (com[0] == 'd') {
      if (strlen(com) > 6){
	if (com[6] == 'F')
	  deleteFirst();
	
	else if (com[6] == 'L')
	  deleteLast();
      }
      
      else {
	deleteKey(key); nd++; 
      }
      
      size--;
	
    }
    
  }

  printList();
  
  return 0;
}

NodePointer listSearch(int key){
  NodePointer cur = nil->next;

  while (cur != nil && cur->key != key)
    cur = cur->next;

  return cur;
}

void init(void){
  nil = new Node;
  nil->next = nil;
  nil->prev = nil;
}

void printList(void){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  cout << " ";
    cout << cur->key;
    cur = cur->next;
    isf = 0;
  }
  cout << endl;
}

void deleteNode(NodePointer t){
  t->prev->next = t->next;
  t->next->prev = t->prev;
  delete t;
}

void deleteFirst(void){
  NodePointer t = nil->next;
  if ( t == nil )
    return;
  
  deleteNode(t);
}

void deleteLast(void){
  NodePointer t = nil->prev;
  if (t == nil)
    return;
  
  deleteNode(t);
}

void deleteKey(int key){
  NodePointer t = listSearch(key);

  if (t == nil)
    return;

  deleteNode(t);
}


void insert(int key){
  NodePointer x;
  x = new Node;
  x->key = key;

  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;

}

// 
