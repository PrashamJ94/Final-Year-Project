
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e18;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N);
    for(int i = 0; i < M; ++i)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        --X; --Y; --Z;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }
    vector<bool> used(N, false);
    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        if(!used[i])
        {
            ans += 1;
            deque<int> queue;
            queue.push_back(i);
            while(!queue.empty())
            {
                int node = queue.front();
                queue.pop_front();
                used[node] = true;
                for(auto nextnode : edge[node])
                {
                    if(!used[nextnode])
                    {
                        queue.push_back(nextnode);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// End of Code
