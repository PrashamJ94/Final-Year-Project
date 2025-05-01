#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int key;
  int value;
} KeyValuePair;

int main() {
  int n, i, a, ans;
  scanf("%d", &n);
  KeyValuePair* map = (KeyValuePair*)malloc(n * sizeof(KeyValuePair));
  int mapSize = 0;

  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    bool found = false;
    for (int j = 0; j < mapSize; j++) {
      if (map[j].key == a) {
        map[j].value += 1;
        found = true;
        break;
      }
    }
    if (!found) {
      map[mapSize].key = a;
      map[mapSize].value = 1;
      mapSize++;
    }
  }
  ans = 0;
  for (i = 0; i < mapSize; i++) {
    if ((map[i].value % 2) == 1) {
      ans++;
    }
  }
  printf("%d\n", ans);
  free(map);
  return 0;
}
// 
