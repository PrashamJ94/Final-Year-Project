#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare (const void * a, const void * b){
   return ( *(int*)b - *(int*)a );
}

int main(){
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    int a[x], b[y], c[z];
    for(int i=0; i<x; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<y; i++)
        scanf("%d", &b[i]);
    for(int i=0; i<z; i++)
        scanf("%d", &c[i]);

    int ab[x*y];
    int index = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            ab[index++] = a[i] + b[j];
        }
    }
    qsort(ab, x*y, sizeof(int), compare);

    int abc[k*z];
    index = 0;
    for(int i=0; i< (k < x*y ? k : x*y); i++){
        for(int j=0; j<z; j++){
            abc[index++] = ab[i] + c[j];
        }
    }
    qsort(abc, k*z, sizeof(int), compare);

    for(int i=0; i<k; i++){
        printf("%d\n", abc[i]);
    }

    return 0;
}
// End of Code

//This C code does exactly what the Python code does: it reads 4 integers (x, y, z, k) from the input, then reads 3 arrays of integers (a, b, c), then computes all the possible sums of an element from a and an element from b, sorts these sums in decreasing order, then computes all the possible sums of an element from the previous sums and an element from c, and finally prints the k largest sums. Note that in C it's necessary to first declare the size of the arrays, which is determined by the first four inputs. Also, the comparison function for qsort() (which is the C equivalent of Python's sort()) is defined at the beginning.

