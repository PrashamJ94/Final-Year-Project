#include <iostream>

int main() {
	int h, r;
	std::cin >> h >> r;
	if (r > -h) { std::cout << "1" << std::endl; }
	else if (r == -h) { std::cout << "0" << std::endl; }
	else { std::cout << "-1" << std::endl; }
	return 0;
}
// 
