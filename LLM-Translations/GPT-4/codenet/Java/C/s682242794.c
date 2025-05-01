#include <stdio.h>

void solve(){
    int high;
    int low;
    int sa;
    
    for(int i=0;i<7;i++){
        scanf("%d", &high);
        scanf("%d", &low);
        sa=high-low;
        printf("%d\n", sa);
    }
}

int main(){
    solve();
    return 0;
}
// 
