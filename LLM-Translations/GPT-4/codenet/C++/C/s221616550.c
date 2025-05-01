#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s, int length){
  for(int i = 0; i < length / 2; i++){
    if(s[i] == s[length - 1 - i]) continue;
    else return false;
  }
  return true;
}

int main(){
  char s[1000];
  scanf("%s", s);
  int length = strlen(s);
  if(isPalindrome(s, length) && isPalindrome(s, length / 2)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

// 
