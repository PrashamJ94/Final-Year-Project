#include <stdio.h>

int dfs(int h) {
  if (h == 1) {
    return 1;
  }

  return dfs(h / 2) * 2 + 1;
}

int main() {
  int H;
  scanf("%d", &H);

  int count = dfs(H);
  printf("%d\n", count);

  return 0;
}
// 
