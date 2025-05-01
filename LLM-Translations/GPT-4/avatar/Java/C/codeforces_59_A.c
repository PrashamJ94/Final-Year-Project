#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char word[101];
  int uppercase = 0;
  int lowercase = 0;

  scanf("%s", word);

  for (int i = 0; i < strlen(word); i++) {
    char ch = word[i];
    if (isupper(ch)) {
      uppercase++;
    } else {
      lowercase++;
    }
  }

  if (uppercase > lowercase) {
    for (int i = 0; i < strlen(word); i++) {
      word[i] = toupper(word[i]);
    }
  } else {
    for (int i = 0; i < strlen(word); i++) {
      word[i] = tolower(word[i]);
    }
  }

  printf("%s\n", word);

  return 0;
}
// //End of Code
