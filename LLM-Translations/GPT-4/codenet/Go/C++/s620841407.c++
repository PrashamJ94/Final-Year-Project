
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const ll INF_INT64 = 1e18;
const int INF_BIT60 = 1 << 60;
const int INF_INT32 = 1e9;
const int INF_BIT30 = 1 << 30;
const int NIL = -1;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

template <typename T>
class ReRootingSolver
{
public:
    int nodeCount;
    vector<vector<int>> adjacents;
    vector<vector<int>> indexForAdjacents;
    vector<T> res;
    vector<vector<T>> dp;
    T identity;
    function<T(T, T)> operate;
    function<T(T, int)> operateNode;

    ReRootingSolver(int nodeCount, vector<vector<int>> &edges, T identity, function<T(T, T)> operate, function<T(T, int)> operateNode)
    {
        this->nodeCount = nodeCount;
        this->identity = identity;
        this->operate = operate;
        this->operateNode = operateNode;

        adjacents.resize(nodeCount);
        indexForAdjacents.resize(nodeCount);
        for (auto &e : edges)
        {
            indexForAdjacents[e[0]].push_back(adjacents[e[1]].size());
            indexForAdjacents[e[1]].push_back(adjacents[e[0]].size());
            adjacents[e[0]].push_back(e[1]);
            adjacents[e[1]].push_back(e[0]);
        }

        dp.resize(adjacents.size());
        res.resize(adjacents.size());

        for (int i = 0; i < adjacents.size(); i++)
        {
            dp[i].resize(adjacents[i].size());
        }

        if (nodeCount > 1)
        {
            initialize();
        }
        else
        {
            res[0] = operateNode(identity, 0);
        }
    }

    T query(int node)
    {
        return res[node];
    }

    void initialize()
    {
        vector<int> parents(nodeCount), order(nodeCount);

        // InitOrderedTree
        int index = 0;
        stack<int> st;
        st.push(0);
        parents[0] = -1;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            order[index] = node;
            index++;
            for (int i = 0; i < adjacents[node].size(); i++)
            {
                int adjacent = adjacents[node][i];
                if (adjacent == parents[node])
                {
                    continue;
                }
                st.push(adjacent);
                parents[adjacent] = node;
            }
        }

        // fromLeaf
        for (int i = order.size() - 1; i >= 1; i--)
        {
            int node = order[i];
            int parent = parents[node];

            T accum = identity;
            int parentIndex = -1;
            for (int j = 0; j < adjacents[node].size(); j++)
            {
                if (adjacents[node][j] == parent)
                {
                    parentIndex = j;
                    continue;
                }
                accum = operate(accum, dp[node][j]);
            }
            dp[parent][indexForAdjacents[node][parentIndex]] = operateNode(accum, node);
        }

        // toLeaf
        for (int i = 0; i < order.size(); i++)
        {
            int node = order[i];
            T accum = identity;
            vector<T> accumsFromTail(adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = identity;
            for (int j = accumsFromTail.size() - 1; j >= 1; j--)
            {
                accumsFromTail[j - 1] = operate(dp[node][j], accumsFromTail[j]);
            }
            for (int j = 0; j < accumsFromTail.size(); j++)
            {
                dp[adjacents[node][j]][indexForAdjacents[node][j]] = operateNode(operate(accum, accumsFromTail[j]), node);
                accum = operate(accum, dp[node][j]);
            }
            res[node] = operateNode(accum, node);
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }

    auto f = [](ll x, ll y) { return (x * y) % m; };
    auto g = [](ll v, int p) { return v + 1; };
    ReRootingSolver<ll> s(n, edges, 1, f, g);
    for (int i = 0; i < n; i++)
    {
        cout << s.query(i) - 1 << endl;
    }

    return 0;
}


