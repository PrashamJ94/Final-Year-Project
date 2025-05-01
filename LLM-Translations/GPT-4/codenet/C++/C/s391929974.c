#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
  int n;
  int sq[10000],fr[5000];
  int com[5000];
  int tmp;
  int com_size;

  while(1){
    scanf("%d", &n);
    if(!n)break;

    for(int i=1;i<n;i++)sq[i] = (i*i)%n;
    com_size = 0;

    for(int i=1;i<n;i++){
      bool f = true;
      for(int j=0;j<com_size;j++){
	if(com[j]==sq[i]){
	  f = false;
	  break;
	}
      }
      if(f)com[com_size++] = sq[i];
    }
 
    for(int i=0;i<=(n-1)/2;i++)fr[i] = 0;

    for(int i=0;i<com_size;i++){
      for(int j=0;j<com_size;j++){
	if(i!=j){
	  tmp = com[i]-com[j];
	  if(tmp<0)tmp+=n;
	  if(tmp>(n-1)/2)tmp = n - tmp;
	  fr[tmp]++;
	}
      }
    }

    for(int i=1;i<=(n-1)/2;i++)printf("%d\n", fr[i]);
  }
}
// 
