#include<iostream>
#include<vector>

void print_vector(int n, std::vector<int> &A) {
    int i;
    for(i = 0; i < n - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[i] << std::endl;
}

void insertion_sort(int n, std::vector<int> &A) {
    int i, j, a;
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(A[i] < A[j]) {
                a = A[i];
                A[i] = A[j];
                A[j] = a;
            }
        }
        print_vector(n, A);
    }
}

int main() {
    int i, n;
    std::cin >> n;
    std::vector<int> A(n);
    for (i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    insertion_sort(n, A);

    return 0;
}
// 
