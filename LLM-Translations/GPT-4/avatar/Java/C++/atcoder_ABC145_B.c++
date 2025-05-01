#include <iostream>
#include <string>

using namespace std;

void cout(string str) {
    std::cout << str << std::endl;
}

int main() {
    string a = "", b = "", str;
    int n;

    cin >> n;
    cin.ignore();

    getline(cin, str);

    for (int i = 0; i < n / 2; i++) {
        a = a + str[i];
    }

    if (str == a + a)
        cout("Yes");
    else
        cout("No");

    return 0;
}

// //End of Code
