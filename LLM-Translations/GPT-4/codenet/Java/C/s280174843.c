#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int abc[3];
  char str[256];
  char *inp;
  fgets(str, 256, stdin);
  inp = strtok(str, " ");
  for (int i = 0; i < 3; i++) {
    abc[i] = atoi(inp);
    inp = strtok(NULL, " ");
  }
  if (abc[0] < abc[1] && abc[1] < abc[2]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
// 
