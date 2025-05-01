#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n, m, q;
int max = 0;
int *a, *b, *c, *d;

void dfs(int *array, int array_length) {
  if (array_length > n) {
    int score = 0;
    for (int i = 0; i < q; i++) {
      if (array[b[i]] - array[a[i]] == c[i]) {
        score += d[i];
      }
    }
    max = (max > score) ? max : score;
    return;
  }

  // Append an item to the existing array
  int *newArray = (int *)malloc((array_length + 1) * sizeof(int));
  memcpy(newArray, array, array_length * sizeof(int));
  newArray[array_length] = array[array_length - 1];

  while (newArray[array_length] <= m) {
    dfs(newArray, array_length + 1);
    newArray[array_length] += 1;
  }
  free(newArray);
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  a = (int *)malloc(q * sizeof(int));
  b = (int *)malloc(q * sizeof(int));
  c = (int *)malloc(q * sizeof(int));
  d = (int *)malloc(q * sizeof(int));
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
  }
  int initial_array[] = {1};
  dfs(initial_array, 1);
  printf("%d\n", max);
  free(a); free(b); free(c); free(d);
  return 0;
}
// 
