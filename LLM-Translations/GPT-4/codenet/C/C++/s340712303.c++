#include<iostream>
#include<vector>
#define N 2000
using namespace std;

int num1;
vector<int> math(N+1, 0);

int main(){
    int a, num2, ans, sum=0;
    int i, j;

    math[0]=1;
    
    cin >> num1;
    for(i=0; i<num1; i++){
        cin >> a;
        sum += a;
        for(j=sum-a; j>=0; j--){
            if(math[j]==1) math[j+a]=1;
        }
    	
    }

    cin >> num2;
    for(i=0; i<num2; i++){
        cin >> ans;
        math[ans]==1 ? cout << "yes\n" : cout << "no\n";
    }

    return 0;
}

// 
