
#include <stdio.h>
#include <string.h>

int main() {
  char s[201], t[101];
  scanf("%s %s", s, t);
  strcat(s, s);
  printf("%s", (strstr(s, t) != NULL) ? "Yes" : "No");
  return 0;
}


