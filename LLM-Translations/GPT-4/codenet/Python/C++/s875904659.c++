#include <iostream>
#include <vector>
#include <string>

void bubbleSort(std::vector<std::string> &cards) {
    int n = cards.size();
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (int(cards[j][1]) < int(cards[j-1][1])) {
                std::swap(cards[j], cards[j-1]);
            }
        }
    }
    for (const auto &card : cards) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<std::string> &cards) {
    int n = cards.size();
    for (int i = 0; i < n; ++i) {
        int mini = i;
        for (int j = i; j < n; ++j) {
            if (int(cards[j][1]) < int(cards[mini][1])) {
                mini = j;
            }
        }
        if (mini != i) {
            std::swap(cards[i], cards[mini]);
        }
    }
    for (const auto &card : cards) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> cards(n), cards2;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }
    cards2 = cards;
    
    bubbleSort(cards);
    std::cout << "Stable" << std::endl;
    selectionSort(cards2);
    
    if (cards == cards2) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }

    return 0;
}
// 
