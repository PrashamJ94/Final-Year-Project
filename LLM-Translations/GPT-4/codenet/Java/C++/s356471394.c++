
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int N, M, D;
static int num = 0;
static vector<vector<char>> room;

void inputRoom() {
    string str_room;
    for (int i = 0; i < N; i++) {
        getline(cin, str_room);
        room.push_back(vector<char>(str_room.begin(), str_room.end()));
    }
}

void setWE() {
    bool canPut = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - D + 1; j++) {
            canPut = true;

            for(int k = 0; k < D; k++){
                if (room[i][j + k] == '#') {
                    canPut = false;
                    break;
                }
            }

            if (canPut == true) {
                num++;
            }
        }
    }
}

void setNS() {
    bool canPut = true;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - D + 1; j++) {
            canPut = true;

            for(int k = 0; k < D; k++){
                if (room[j + k][i] == '#') {
                    canPut = false;
                    break;
                }
            }

            if (canPut == true) {
                num++;
            }
        }
    }
}

int main() {
    cin >> N >> M >> D;
    cin.ignore();
    inputRoom();

    if (M >= D) {
        setWE();
    }

    if (N >= D) {
        setNS();
    }

    cout << num << endl;

    return 0;
}

// 
