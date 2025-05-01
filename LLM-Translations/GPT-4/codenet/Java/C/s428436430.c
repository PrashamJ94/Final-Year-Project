#include <stdio.h>

int calArea(int w, int h) {
    int area = w * h;
    return area;
}

int main() {
    int arr[4];
    
    for(int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    
    int area1 = calArea(arr[0], arr[1]);
    int area2 = calArea(arr[2], arr[3]);
    
    if(area1 > area2) {
        printf("%d\n", area1);
    } else if(area1 < area2) {
        printf("%d\n", area2);
    } else if(area1 == area2) {
        printf("%d\n", area1);
    }
    
    return 0;
}
// 
