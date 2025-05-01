#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::istream* input;
    std::ostream* output;

    if (argc > 1) {
        inputFile.open(argv[1]);
        input = &inputFile;
        if (argc > 2) {
            outputFile.open(argv[2]);
            output = &outputFile;
        } else {
            output = &std::cout;
        }
    } else {
        input = &std::cin;
        output = &std::cout;
    }

    int n;
    *input >> n;

    std::string ans = "second";
    for (int i = 0; i < n; i++) {
        int a;
        *input >> a;
        if (a % 2 == 1) {
            ans = "first";
            break;
        }
    }
    *output << ans << std::endl;

    if (inputFile.is_open()) inputFile.close();
    if (outputFile.is_open()) outputFile.close();

    return 0;
}
// 
