#include <iostream>
using namespace std;

int main() {
   int a, b, c = 0;
   cin >> a >> b;
   for (int i = 0; i < 2; i++) {
      c += max(a, b);
      if (a >= b) {
         a -= 1;
      } else {
         b -= 1;
      }
   }
   cout << c;
   return 0;
}

// End of Code
