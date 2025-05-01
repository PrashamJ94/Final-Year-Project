#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> flag;

void prime(int num){
	int i,j;

	flag.resize(num + 1, false);

	for(i = 2; i * i <= num; i++){
		if(flag[i] == false){
			for(j = 2; i * j <= num; j++){
				flag[i * j] = true;
			}
		}
	}
}

int main(){
	int n, i, cnt;

	prime(50000);

	while(1){
		std::cin >> n;
		if(n == 0){
			break;
		}
		i = 2;
		cnt = 0;
		while(i * 2 <= n){
			if(!flag[i] && !flag[n - i]){
				cnt++;
			}
			i++;
		}
		std::cout << cnt << std::endl;
	}

	return 0;
}
// 
