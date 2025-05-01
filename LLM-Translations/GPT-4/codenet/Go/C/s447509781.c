
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int64_t *NextIntArray(char *line);
int NextInt(char *line);

int main() {
  char line[1000000];
  fgets(line, sizeof(line), stdin);
  int n = NextInt(line);

  fgets(line, sizeof(line), stdin);
  int64_t *s = NextIntArray(line);

  bool *u = (bool *)calloc(n, sizeof(bool));
  int64_t m = 0, f;

  for (int c = 1; c < n - 1; c++) {
    f = 0;
    for (int k = 0; c < n - 1 - k * c; k++) {
      u[k * c] = true;
      if (u[n - 1 - k * c]) { break; }
      f += s[n - 1 - k * c] + s[k * c];
      if (m < f) { m = f; }
    }
    for (int k = 0; k * c < n - 1; k++) { u[k * c] = false; }
  }
  printf("%lld\n", m);

  free(s);
  free(u);
  return 0;
}

int64_t *NextIntArray(char *line) {
  char *token;
  int count = 0;
  int64_t *a;
  token = strtok(line, " ");
  while (token != NULL) {
    a = (int64_t *)realloc(a, (count + 1) * sizeof(int64_t));
    a[count++] = strtoll(token, NULL, 10);
    token = strtok(NULL, " ");
  }
  return a;
}

int NextInt(char *line) {
  return atoi(line);
}

// 
