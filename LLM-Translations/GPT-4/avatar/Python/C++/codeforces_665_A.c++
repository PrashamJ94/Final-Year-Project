#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, at, b, bt, t1, t2, st, fin, now = 0, ans = 0;
    scanf("%d%d", &a, &at);
    scanf("%d%d", &b, &bt);
    scanf("%d:%d", &t1, &t2);
    st = t2 + (t1 - 5) * 60;
    fin = st + at;
    while(now < fin && now < 1140){
        if(now + bt > st){
            ans++;
        }
        now += b;
    }
    printf("%d", ans);
    return 0;
} // End of Code.
