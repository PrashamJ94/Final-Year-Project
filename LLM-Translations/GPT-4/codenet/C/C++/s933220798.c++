#include <iostream>

int main()
{
	double a;
	double ave = 0;
	int i;

	for (i = 0; i < 5; i++){
		std::cin >> a;
		if (a <= 40){
			ave += 40;
		}
		else {
			ave += a;
		}
	}

	ave /= 5.0;

	std::cout << static_cast<int>(ave) << std::endl;

	return 0;
}
// 
