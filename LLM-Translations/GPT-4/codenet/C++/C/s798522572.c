#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
  int N, T;
  scanf("%d %d", &N, &T);
  int A[N];
  int B[N];
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  int m = A[0];
  B[1] = A[1] - m;
  m = (m < A[1]) ? m : A[1];
  for(int i = 2; i < N; i++){
    B[i] = A[i] - m;
    m = (m < A[i]) ? m : A[i];
  }
  int max = INT_MIN;
  int count = 0;
  for(int i = 0; i < N; i++){
    if(B[i] > max){
      max = B[i];
      count = 1;
    } else if(B[i] == max){
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
// 
