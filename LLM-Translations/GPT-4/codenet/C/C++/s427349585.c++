#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  char s;
  int v;
} card;

vector<card> L(100000 / 2 + 2), R(100000 / 2 + 2);

void me(vector<card>& a, int n, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l;
  int n2 = r - m;

  for (i = 0; i < n1; i++) L[i] = a[l + i];
  for (i = 0; i < n2; i++) R[i] = a[m + i];
  L[n1].v = R[n2].v = 2000000000;
  i = 0;
  j = 0;
  for (k = l; k < r; k++) {
    if (L[i].v <= R[j].v) {
      a[k] = L[i++];
    } else {
      a[k] = R[j++];
    }
  }
}

void ms(vector<card>& a, int n, int l, int r) {
  int m;
  if (l + 1 < r) {
    m = (l + r) / 2;
    ms(a, n, l, m);
    ms(a, n, m, r);
    me(a, n, l, m, r);
  }
}

int partiton(vector<card>& a, int n, int p, int r) {
  int i, j;
  card t, x;
  x = a[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (a[j].v <= x.v) {
      i++;
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;
  return i + 1;
}

void qs(vector<card>& a, int n, int p, int r) {
  int q;

  if (p < r) {
    q = partiton(a, n, p, r);
    qs(a, n, p, q - 1);
    qs(a, n, q + 1, r);
  }
}

int main() {
  int n, i, v;
  char s[10];
  int stable = 1;

  cin >> n;

  vector<card> a(n), b(n);

  for (i = 0; i < n; i++) {
    cin >> s >> v;
    a[i].s = b[i].s = s[0];
    a[i].v = b[i].v = v;
  }

  ms(a, n, 0, n);
  qs(b, n, 0, n - 1);

  for (i = 0; i < n; i++) {
    if (a[i].s != b[i].s) {
      stable = 0;
    }
  }
  if (stable == 1) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
  for (i = 0; i < n; i++) {
    cout << b[i].s << " " << b[i].v << endl;
  }

  return 0;
}

// 
