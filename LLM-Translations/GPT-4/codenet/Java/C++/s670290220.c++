#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        input[i] = (char)((input[i] - 'A' + N) % 26 + 'A');
    }
    cout << input << endl;
    return 0;
}
// 
