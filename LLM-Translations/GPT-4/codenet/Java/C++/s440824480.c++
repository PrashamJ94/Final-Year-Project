#include <iostream>
using namespace std;

int main() {
  int n, c = 0, flg = 0;
  cin >> n;

  while (n-- > 0) {
    int x, y;
    cin >> x >> y;

    if (x == y) {
      c++;
      if (c >= 3) {
        flg = 1;
      }
    } else {
      c = 0;
    }
  }

  if (flg == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
// 
