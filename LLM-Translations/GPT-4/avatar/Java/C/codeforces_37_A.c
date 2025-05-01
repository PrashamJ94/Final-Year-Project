Your Java code makes use of a lot of classes and methods that are part of the standard Java library, such as BufferedReader, StringTokenizer, HashMap, and Map.Entry. These classes and methods do not have direct equivalents in C, so translating the code to C requires implementing equivalent functionality manually.

Here is a rough translation of your code to C:


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n, val, max = 0;
    int map[MAX_SIZE] = {0};
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        map[val]++;
    }

    int size = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        if(map[i] > 0) {
            size++;
            if(map[i] > max) {
                max = map[i];
            }
        }
    }

    printf("%d %d\n", max, size);

    return 0;
}
/* //End of Code */


This code assumes that the input integers are non-negative and less than `MAX_SIZE`. It uses an array `map` to keep the count of each integer. The size of the map is determined by counting the non-zero elements in the array. The maximum value is determined by finding the maximum count in the array. 

Please note that this is a simple translation and may not cover all edge cases. Also, the original Java code uses a BufferedReader for efficient input, which has no direct equivalent in C. The C code here simply uses `scanf` for input, which may be slower if the input size is very large.
