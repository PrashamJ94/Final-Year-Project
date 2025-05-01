#include <stdio.h>

int main() {
  int count;
  scanf("%d", &count);
  
  int total = 0;
  for (int ix = 1; ix <= count; ix++) {
      total += ix;
  }
  
  printf("%d\n", total);
  return 0;
}
// 
