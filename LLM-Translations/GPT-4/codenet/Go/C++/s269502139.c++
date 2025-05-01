#include <iostream>
#include <sstream>
#include <string>
#include <list>

class Node {
public:
    int32_t key;
    Node* prev;
    Node* next;

    Node(int32_t key) : key(key), prev(nullptr), next(nullptr) {}

    void rPrint(std::ostream& os) {
        os << key;
        if (next != nullptr) {
            os << " ";
            next->rPrint(os);
        }
    }

    void deleteNode(Node*& first, Node*& last) {
        if (prev != nullptr && next != nullptr) {
            prev->next = next;
            next->prev = prev;
            return;
        }

        if (next == nullptr && prev == nullptr) {
            first = nullptr;
            last = nullptr;
            return;
        }

        if (prev == nullptr) {
            first = next;
            next->prev = nullptr;
        }

        if (next == nullptr) {
            last = prev;
            prev->next = nullptr;
        }
    }
};

int main() {
    std::string line;
    Node* first = nullptr;
    Node* last = nullptr;

    std::getline(std::cin, line);

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "deleteFirst") {
            first->deleteNode(first, last);
        } else if (cmd == "deleteLast") {
            last->deleteNode(first, last);
        } else {
            std::string xcmd;
            int32_t k;
            iss >> xcmd >> k;

            if (xcmd == "delete") {
                for (Node* a = first; a != nullptr; a = a->next) {
                    if (a->key == k) {
                        a->deleteNode(first, last);
                        break;
                    }
                }
            } else if (xcmd == "insert") {
                Node* n = new Node(k);
                n->next = first;
                if (first != nullptr) {
                    first->prev = n;
                }

                first = n;
                if (last == nullptr) {
                    last = n;
                }
            }
        }
    }

    first->rPrint(std::cout);
    std::cout << std::endl;

    return 0;
}

// 
