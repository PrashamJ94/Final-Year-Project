
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int key;
    Node *next;
    Node *prev;

    Node(int a)
    {
        key = a;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = new Node(0);
        head->next = head;
        head->prev = head;
    }

    void insert(int a)
    {
        Node *x = new Node(a);
        x->next = head->next;
        head->next->prev = x;
        head->next = x;
        x->prev = head;
    }

    void deleteNode(int a)
    {
        Node *x = head;

        while (x->next != head)
        {
            x = x->next;
            if (x->key == a)
            {
                x->prev->next = x->next;
                x->next->prev = x->prev;
                delete x;
                break;
            }
        }
    }

    void deleteFirst()
    {
        Node *x = head->next;
        head->next = x->next;
        x->next->prev = head;
        delete x;
    }

    void deleteLast()
    {
        Node *x = head->prev;
        head->prev = x->prev;
        x->prev->next = head;
        delete x;
    }
};

int main()
{
    int i, n, a;
    string op;
    Node *x;

    DoublyLinkedList dll;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> op;
        if (op == "insert")
        {
            cin >> a;
            dll.insert(a);
        }
        else if (op == "delete")
        {
            cin >> a;
            dll.deleteNode(a);
        }
        else if (op == "deleteFirst")
        {
            dll.deleteFirst();
        }
        else if (op == "deleteLast")
        {
            dll.deleteLast();
        }
    }

    x = dll.head;
    while (x->next != dll.head)
    {
        cout << x->next->key;
        x = x->next;
        if (x->next != dll.head)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

// 
