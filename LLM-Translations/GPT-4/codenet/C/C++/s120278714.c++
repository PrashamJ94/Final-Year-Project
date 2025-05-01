#include <iostream>
#include <vector>

#define MAX 25

using namespace std;

struct Node {
    int l, r, par;
};

vector<Node> nodes(MAX);

void init(int n);
void Preorder(int p);
void Inorder(int p);
void Postorder(int p);

int main() {
    int n, id, l, r;
    int p;

    cin >> n;
    init(n);

    for (int i = 0; i < n; i++) {
        cin >> id >> l >> r;

        if (l != -1) {
            nodes[id].l = l;
            nodes[l].par = id;
        }
        if (r != -1) {
            nodes[id].r = r;
            nodes[r].par = id;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i].par == -1) {
            p = i;
            break;
        }
    }

    cout << "Preorder" << endl;
    Preorder(p);
    cout << endl;

    cout << "Inorder" << endl;
    Inorder(p);
    cout << endl;

    cout << "Postorder" << endl;
    Postorder(p);
    cout << endl;

    return 0;
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        nodes[i].par = nodes[i].l = nodes[i].r = -1;
    }
}

void Preorder(int p) {
    if (p != -1) {
        cout << " " << p;
        Preorder(nodes[p].l);
        Preorder(nodes[p].r);
    }
}

void Inorder(int p) {
    if (p != -1) {
        Inorder(nodes[p].l);
        cout << " " << p;
        Inorder(nodes[p].r);
    }
}

void Postorder(int p) {
    if (p != -1) {
        Postorder(nodes[p].l);
        Postorder(nodes[p].r);
        cout << " " << p;
    }
}

// 
