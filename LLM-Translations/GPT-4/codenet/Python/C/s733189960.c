#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return (*(char *)a) - (*(char *)b);
}

int main() {
  int n;
  scanf("%d", &n);

  char s[11];
  char sorted_str[11];
  int ans = 0;

  struct {
    char key[11];
    int count;
  } sdic[100];

  int sdic_size = 0;

  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    strcpy(sorted_str, s);
    qsort(sorted_str, strlen(sorted_str), sizeof(char), compare);

    int found = 0;
    for (int j = 0; j < sdic_size; j++) {
      if (strcmp(sdic[j].key, sorted_str) == 0) {
        sdic[j].count++;
        found = 1;
        break;
      }
    }

    if (!found) {
      strcpy(sdic[sdic_size].key, sorted_str);
      sdic[sdic_size].count = 1;
      sdic_size++;
    }
  }

  for (int i = 0; i < sdic_size; i++) {
    ans += sdic[i].count * (sdic[i].count - 1) / 2;
  }

  printf("%d\n", ans);

  return 0;
}

// 
