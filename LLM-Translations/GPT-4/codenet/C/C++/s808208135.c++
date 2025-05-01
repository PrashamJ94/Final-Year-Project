#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int N = 100000;
const int INF = 1000000;

struct Date
{
    int go, back, cost;
};

int n;
vector<int> d(N);
vector<Date> a(500000);
void root(int);

int main()
{
    int i, j, k, u, count = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (j = 0; j < k; j++)
        {
            a[count].back = u;
            cin >> a[count].go >> a[count].cost;
            count++;
        }
    }
    root(count);
    for (i = 0; i < n; i++)
        cout << i << " " << d[i] << endl;
    return 0;
}

void root(int b)
{
    int i, flag = 1;

    for (i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;

    while (flag != 0)
    {
        flag = 0;
        for (i = 0; i < b; i++)
        {
            if (a[i].cost + d[a[i].back] < d[a[i].go])
            {
                d[a[i].go] = a[i].cost + d[a[i].back];
                flag = 1;
            }
        }
    }
}

// 
