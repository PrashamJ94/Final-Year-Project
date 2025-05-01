#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s[s.length() - 1] - '0';
    if (n == 3)
        cout << "bon" << endl;
    else if (n == 0 || n == 1 || n == 6 || n == 8)
        cout << "pon" << endl;
    else
        cout << "hon" << endl;

    return 0;
}
// 
