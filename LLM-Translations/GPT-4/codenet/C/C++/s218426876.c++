#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, sum = 0;
    int flag = 0;
    string x;
    while (true)
    {
        sum = 0;
        cin >> x;
        if (x == "0")
        {
            break;
        }
        for (i = 0; i < x.length(); i++)
        {
            sum += x[i] - '0';
        }
        cout << sum << endl;
    }

    return 0;
}
// 
