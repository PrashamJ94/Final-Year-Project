#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Node {
public:
    int key;
    Node* parent;
    Node* left;
    Node* right;

    Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
            return;
        }

        Node* currentNode;
        Node* prevNode = nullptr;
        currentNode = root;
        while (currentNode != nullptr) {
            prevNode = currentNode;
            if (currentNode->key < key) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }

        Node* newNode = new Node(key);
        newNode->parent = prevNode;
        if (prevNode->key < key) {
            prevNode->right = newNode;
        } else {
            prevNode->left = newNode;
        }
    }

    void print() {
        std::vector<int> acc;
        if (root == nullptr) {
            std::cout << std::endl << std::endl;
        } else {
            std::cout << " " << join(visitInorder(root, acc)) << std::endl;
            std::cout << " " << join(visitPreorder(root, acc)) << std::endl;
        }
    }

    std::vector<int> visitPreorder(Node* node, std::vector<int>& acc) {
        if (node == nullptr) {
            return acc;
        }
        acc.push_back(node->key);
        if (node->left != nullptr) {
            acc = visitPreorder(node->left, acc);
        }
        if (node->right != nullptr) {
            acc = visitPreorder(node->right, acc);
        }
        return acc;
    }

    std::vector<int> visitInorder(Node* node, std::vector<int>& acc) {
        if (node == nullptr) {
            return acc;
        }
        if (node->left != nullptr) {
            acc = visitInorder(node->left, acc);
        }
        acc.push_back(node->key);
        if (node->right != nullptr) {
            acc = visitInorder(node->right, acc);
        }
        return acc;
    }

    std::string join(const std::vector<int>& is) {
        std::stringstream ss;
        for (size_t i = 0; i < is.size(); ++i) {
            if (i != 0) {
                ss << " ";
            }
            ss << is[i];
        }
        return ss.str();
    }
};

int main() {
    int n;
    std::cin >> n;
    std::string command;
    Tree tree;

    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command == "insert") {
            int key;
            std::cin >> key;
            tree.insert(key);
        } else if (command == "print") {
            tree.print();
        } else {
            std::cerr << "unknown command: " << command << std::endl;
            return 1;
        }
    }

    return 0;
}

// 
