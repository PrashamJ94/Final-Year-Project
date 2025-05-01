#include<iostream>
#include<vector>

bool search(std::vector<int> &A, int n, int key){
    int i = 0;
    A.push_back(key);
    while (A[i] != key) i++;
    A.pop_back();
    return i != n;
}

int main(){
    int n, q, key, sum = 0;
    std::vector<int> A;

    std::cin >> n;
    for(int i = 0; i < n; i++){
	int a;
	std::cin >> a;
	A.push_back(a);
    }
    std::cin >> q;
    for(int i = 0; i < q; i++){
	std::cin >> key;
	if(search(A, n, key)) sum++;
    }
    std::cout << sum << std::endl;

    return 0;
}
// 
