#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#define MAX_STRING 30
#define MAX_LINE 2000000
#define MAX_HUMAN 200000

std::string sLongInputLine(MAX_LINE + 1, ' ');
std::vector<int> anComingSec(MAX_HUMAN);

int main() {

    std::string sInput(MAX_STRING + 1, ' ');
    std::string token;
    std::istringstream iss;

    int nHumanNumber = 0;
    int nNextHumanIndex = 0;
    int nWaterLength = 0;
    int nWaterLife = 0;
    int nStart = 0;
    int nStop = 0;

    int nIndex = 0;
    int i = 0;
    int j = 0;

    // read line 1
    std::getline(std::cin, sInput);
    iss.str(sInput);
    iss >> nHumanNumber >> nWaterLength;

    std::getline(std::cin, sLongInputLine);
    
    iss.clear();
    iss.str(sLongInputLine);
    for (i = 0; i < nHumanNumber; i++) {
        iss >> anComingSec[i];
    }

    nStart = anComingSec[0];

    while (nNextHumanIndex < nHumanNumber) {
        if (nNextHumanIndex == nHumanNumber) {
            break;
        } else {
            nStop = nStart + nWaterLength;
            if (anComingSec[nNextHumanIndex] < nStop) {
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength;
                        nNextHumanIndex++;
                    }
                }
                if (nNextHumanIndex == nHumanNumber) {
                    nWaterLife = nWaterLife + (nStop - nStart);
                    break;
                }
            }
            nWaterLife = nWaterLife + (nStop - nStart);
            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }
    }
    std::cout << nWaterLife << std::endl;

    return 0;

}
// 
