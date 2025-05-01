#include <iostream>
#include <vector>

using namespace std;

int main() {
   
   int N;
   cin >> N;
   
   vector<int> A(N+1);
   vector<int> B(N);
   int i;
   
   for (i = 0; i < N + 1; i++) {
      cin >> A[i];
   }
   
   for (i = 0; i < N; i++) {
      cin >> B[i];
   }
   
   long ans = 0;
   
   for (i = 0; i < N; i++) {
      
      //site i
      if (A[i] >= B[i]) {
         ans = ans + B[i];
         A[i] = A[i] - B[i];
         B[i] = 0;
      }
      else {
         ans = ans + A[i];
         B[i] = B[i] - A[i];
         A[i] = 0;
      }

      //site i + 1
      if (A[i + 1] >= B[i]) {
         ans = ans + B[i];
         A[i + 1] = A[i + 1] - B[i];
         B[i] = 0;
      }
      else {
         ans = ans + A[i + 1];
         B[i] = B[i] - A[i + 1];
         A[i + 1] = 0;
      }
   }
   
   cout << ans << endl;
   
   return 0;
   
}

// 
