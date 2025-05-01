#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;

class FastReader
{
public:
    FastReader()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    string next()
    {
        while (st.empty())
        {
            getline(cin, tmp);
            stringstream ss(tmp);
            while (ss >> buf)
                st.push(buf);
        }
        string ret = st.front();
        st.pop();
        return ret;
    }

    int nextInt()
    {
        return stoi(next());
    }

    long long nextLong()
    {
        return stoll(next());
    }

    double nextDouble()
    {
        return stod(next());
    }

    string nextLine()
    {
        string str;
        getline(cin, str);
        return str;
    }

private:
    queue<string> st;
    string tmp, buf;
};

int modPower(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

template <typename T1, typename T2>
class pair
{
public:
    T1 first;
    T2 second;
    pair(T1 first, T2 second) : first(first), second(second) {}
};

int main()
{
    FastReader in;
    long a[4];
    for (int i = 0; i < 4; i++)
        a[i] = in.nextLong();
    cout << max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))) << endl;
    return 0;
}

// //End of Code.
