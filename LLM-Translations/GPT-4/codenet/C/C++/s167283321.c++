
#include <iostream>
#include <vector>
using namespace std;

const int NIL = -1;

struct Node {
  int parent, left, right;
};

vector<Node> R(10000);
int n;

void preorder(int x) {
  if (x == NIL)
    return;
  cout << " " << x;
  preorder(R[x].left);
  preorder(R[x].right);
}

void inorder(int x) {
  if (x == NIL)
    return;
  inorder(R[x].left);
  cout << " " << x;
  inorder(R[x].right);
}

void postorder(int x) {
  if (x == NIL)
    return;
  postorder(R[x].left);
  postorder(R[x].right);
  cout << " " << x;
}

int main() {
  int i, a, b, c, root;
  cin >> n;

  for (i = 0; i < n; i++)
    R[i].parent = NIL;

  for (i = 0; i < n; i++) {
    cin >> a >> b >> c;
    R[a].left = b;
    R[a].right = c;

    if (b != NIL) R[b].parent = a;
    if (c != NIL) R[c].parent = a;
  }

  for (i = 0; i < n; i++) {
    if (R[i].parent == NIL)
      root = i;
  }

  cout << "Preorder" << endl;
  preorder(root);
  cout << endl;
  cout << "Inorder" << endl;
  inorder(root);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(root);
  cout << endl;

  return 0;
}

// 
