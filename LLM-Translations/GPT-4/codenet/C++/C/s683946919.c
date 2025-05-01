#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

typedef long long ll;
typedef struct {
  int first, second;
} P;
typedef struct {
  int first;
  P second;
} PP;

int time2min(int month,int day,int hour,int min){
  const int total_day_of_month[]
    = {31,28,31,30,31,30,31,31,30,31,30,31};
  int total = 0;
  for(int i=1;i<month;i++){
    total += total_day_of_month[i]*24*60;
  }
  for(int i=1;i<day;i++){
    total += 24*60;
  }
  total += hour * 60 + min;

  return total;
}

int main(){
  int N;
  while(scanf("%d",&N) != EOF){
    if(N==0) break;

    int log[1000][1000];
    int log_size[1000] = {0};
    memset(log, 0, sizeof(log));

    for(int i=0;i<N;i++){
      int month,day,hour,min,id;
      char action[2];
      scanf("%d/%d %d:%d %s %d",
        &month,&day,&hour,&min,action,
        &id);
      
      int t = time2min(month,day,hour,min);
      log[id][log_size[id]++] = t;
    }

    int total[1000];
    memset(total,0,sizeof(total));
    
    for(int i=0;i+1<log_size[0];i+=2){
      int god_start = log[0][i];
      int god_end = log[0][i+1];

      for(int id = 1; id < 1000; id++){
        if(log_size[id] == 0) continue;
        for(int j=0;j<log_size[id];j+=2){
          int ppl_start = log[id][j];
          int ppl_end = log[id][j+1];
          int start = (god_start > ppl_start) ? god_start : ppl_start;
          int end = (god_end < ppl_end) ? god_end : ppl_end;
          total[id] += (end > start) ? end-start : 0;
        }
      }
    }

    int max_v = 0;
    for(int id=0;id<1000;id++){
      max_v = (total[id] > max_v) ? total[id] : max_v;
    }
    printf("%d\n",max_v);
  }
  // 
}
