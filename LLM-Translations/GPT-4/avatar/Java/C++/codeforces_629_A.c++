#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int num, counter = 0, fine = 0;
    cin >> num;
    vector<string> arr(num);

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }

    cout << fine << endl;
    return 0;
}
// //End of Code
