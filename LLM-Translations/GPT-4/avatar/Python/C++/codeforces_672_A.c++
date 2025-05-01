#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> li;
    int ind = 0;
    for (int i = 1; i < 371; i++) {
        vector<int> temp;
        int p = i, q = i;
        int count = 0;
        while (p != 0) {
            p /= 10;
            count++;
        }
        if (count == 1) {
            li.push_back(i);
        }
        if (count == 2) {
            temp.clear();
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
        if (count == 3) {
            temp.clear();
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
    }
    li.pop_back();
    li.pop_back();

    int n;
    cin >> n;
    cout << li[n - 1] << endl;

    return 0;
} // End of Code

This C++ code does the same as the Python code you provided: it fills a list with all digits of all numbers from 1 to 370, then it takes an integer input and prints the digit at that position in the list.
