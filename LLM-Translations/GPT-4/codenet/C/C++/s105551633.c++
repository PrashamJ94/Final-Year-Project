#include<iostream>
#include<cmath>
#include<algorithm>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int digit(int64 n){
  int res=0;
  while(n>0){
    res++;
    n/=10;
  }
  return res;
}

void run(void){
  int64 n;
  std::cin >> n;
  int min=digit(n);
  int i;
  for(i=1;(int64)i*i<=n;i++){
    if(n%i!=0) continue;
    int64 a=i;
    int64 b=n/i;
    min=std::min(min, std::max(digit(a),digit(b)));
  }
  std::cout << min << std::endl;
}

int main(void){
  run();
  return 0;
}

// 
