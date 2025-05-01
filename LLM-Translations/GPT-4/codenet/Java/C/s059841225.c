#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[256];
  while (scanf("%s", str) != EOF) {
    char *token = strtok(str, ",");
    int l[10];
    int d = 0;
    for (int i = 0; i < 10; i++) {
      l[i] = atoi(token);
      d += l[i];
      token = strtok(NULL, ",");
    }
    int v[2];
    v[0] = atoi(token);
    token = strtok(NULL, ",");
    v[1] = atoi(token);
    double t = (double)d / (v[0] + v[1]);
    d = 0;
    for (int i = 0; i < 11; i++) {
      if (v[0] * t <= d) {
        printf("%d\n", i);
        break;
      } else {
        d += l[i];
      }
    }
  }
  return 0;
}
// 
