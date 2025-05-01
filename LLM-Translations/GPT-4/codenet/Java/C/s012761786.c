#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  long n, a, b;
  scanf("%ld %ld %ld", &n, &a, &b);

  long sa = labs(a - b);

  long ans = 0;

  if (sa % 2 == 0) {
    ans = sa / 2;
  }
  else {
    long AAA = fminl((n - a), (a - 1));
    long BBB = fminl((n - b), (b - 1));

    ans = fminl(AAA, BBB); // One of them reaches the end.

    // Decrease the difference by 1 => The difference becomes even
    sa -= 1;
    ans += 1;

    // The difference is even
    ans += sa / 2;
  }

  printf("%ld\n", ans);

  return 0;
}

// 
