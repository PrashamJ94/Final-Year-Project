#include <iostream>
#include <vector>
#include <string>

int checkSubNumbers(int N, int P, const std::string &S);
int checkTwoOrFive(int N, int P, const std::string &S);
int checkNotTwoNorFive(int N, int P, const std::string &S);

int main() {
    int N, P;
    std::string S;
    std::cin >> N >> P >> S;

    int answer = checkSubNumbers(N, P, S);
    std::cout << answer << std::endl;

    return 0;
}

int checkSubNumbers(int N, int P, const std::string &S) {
    switch (P) {
        case 2:
        case 5:
            return checkTwoOrFive(N, P, S);
        default:
            return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, const std::string &S) {
    int answer = 0;
    int n;
    for (int i = N - 1; i >= 0; --i) {
        n = S[i] - '0';
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, const std::string &S) {
    int multiplier = 1;
    int answer = 0;
    std::vector<int> remainderLookup(P, 0);
    int prevRemainder = -1;
    int digit, remainder, count;
    for (int i = N - 1; i >= 0; --i) {
        digit = S[i] - '0';
        if (prevRemainder == -1) {
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemainder) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemainder = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}

// 
