#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main() {
  int n, count, i, j;
  scanf("%d", &n);
  
  int num[n];
  for (i = 0; i < n; i++) {
	num[i] = i + 1;
  }
  
  scanf("%d", &count);
  regex_t regex;
  regmatch_t matches[3];
  regcomp(&regex, "(\\d+),(\\d+)", REG_EXTENDED);
  
  int line[2];
  char input[100];
  for (i = 0; i < count; i++) {
	scanf("%s", input);
	if (regexec(&regex, input, 3, matches, 0) == 0) {
	  for (j = 0; j < 2; j++) {
		int start = matches[j + 1].rm_so;
		int end = matches[j + 1].rm_eo;
		char temp[end - start + 1];
		memcpy(temp, &input[start], end - start);
		temp[end - start] = '\0';
		line[j] = atoi(temp) - 1;
	  }
	}
	int change = num[line[0]];
	num[line[0]] = num[line[1]];
	num[line[1]] = change;
  }
  regfree(&regex);
  
  for (i = 0; i < n; i++) {
	printf("%d\n", num[i]);
  }

  return 0;
}

// 
