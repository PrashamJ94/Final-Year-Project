
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define each(itr, v) for (auto itr = v.begin(); itr != v.end(); itr++)
#define pb push_back
#define eb emplace_back
#define print(x) cout << x << endl
#define debug(x) cerr << #x << " = " << x << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i != v.size() - 1) os << " ";
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> &v) {
  for (auto itr = v.begin(); itr != v.end(); itr++) {
    os << *itr;
    if (itr != prev(v.end())) os << " ";
  }
  return os;
}

/********** Binary Indexed Tree (Fenwick Tree) **********/

class BIT {
 public:
  vector<int> bit;
  int n;
  BIT(int n) : bit(vector<int>(n + 1, 0)), n(n) {}
  void add(int i, int x) {
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }
  int sum(int i) {
    int res = 0;
    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }
};

/********** Main **********/

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> C(n);
  for (int i = 0; i < n; i++) cin >> C[i];

  vector<tuple<int, int, int>> Q(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    Q[i] = make_tuple(r, l, i);
  }
  sort(all(Q));

  vector<int> P(500000 + 50, -1);
  vector<int> Answers(500000 + 50);

  BIT bit(500000 + 50);
  int k = 0;
  for (auto query : Q) {
    int r, l, idx;
    tie(r, l, idx) = query;
    while (k < r) {
      if (P[C[k]] != -1) {
        bit.add(P[C[k]] + 1, -1);
      }
      P[C[k]] = k;
      bit.add(k + 1, 1);
      k++;
    }
    Answers[idx] = bit.sum(r) - bit.sum(l - 1);
  }

  for (int i = 0; i < q; i++) cout << Answers[i] << endl;

  return 0;
}


