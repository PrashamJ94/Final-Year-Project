#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{
  Node *right;
  Node *left;
  Node *parent;
  int key;
};

Node *root = NULL;

Node* treeMinimum(Node* x){
  while(x->left != NULL) x = x->left;
  return x;
}

Node* treeMaximum(Node* x){
  while(x->right != NULL) x = x->right;
  return x;
}

Node* treeSearch(Node* u, int k){
  if(u == NULL || k == u->key) return u;

  if(k < u->key) return treeSearch(u->left, k);
  else return treeSearch(u->right, k);
}

Node* treeSuccessor(Node* x){
  Node* y;
  if(x->right != NULL) return treeMinimum(x->right);

  y = x->parent;
  while(y != NULL && x == y->right){
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node* z){
  Node *y, *x;

  if(z->left == NULL || z->right == NULL) y = z;
  else y = treeSuccessor(z);

  if(y->left != NULL) x = y->left;
  else x = y->right;

  if(x != NULL) x->parent = y->parent;

  if(y->parent == NULL) root = x;
  else if(y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;

  if(y != z) z->key = y->key;
}

void insert(int k){
  Node *y = NULL;
  Node *x = root;
  Node *z;

  z = new Node;
  z->key = k;
  z->left = NULL;
  z->right = NULL;

  while (x != NULL){
    y = x;
    if(z->key < x->key){
      x = x->left;
    }
    else{
      x = x->right;
    }
  }
  z->parent = y;
  if(y == NULL) root = z;
  else if(z->key < y->key) y->left = z;
  else y->right = z;
}

void inorder(Node* u){
  if(u == NULL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}
void preorder(Node* u){
  if(u == NULL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main(){
  int n, i, x;
  string com;
  cin >> n;

  for (i = 0; i < n; i++){
    cin >> com;
    if (com[0] == 'f'){
      cin >> x;
      Node *t = treeSearch(root, x);
      if (t != NULL) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if (com[0] == 'i'){
      cin >> x;
      insert(x);
    } else if (com[0] == 'p'){
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    } else if (com[0] == 'd'){
      cin >> x;
      treeDelete(treeSearch(root, x));
    }
  }

  return 0;
}
// 
