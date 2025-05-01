#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char record_of_movements[1000];
    scanf("%s", record_of_movements);
    int x = 0, y = 0;
    int d_movement[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    char moves[] = {'L', 'R', 'U', 'D'};
    int d[1000][1000] = {0};
    bool bug = false;
    
    for (int i = 0; i < strlen(record_of_movements); i++) {
        char move = record_of_movements[i];
        int temp_x = x, temp_y = y;
        for (int j = 0; j < 4; j++) {
            if (move == moves[j]) {
                x += d_movement[j][0];
                y += d_movement[j][1];
                break;
            }
        }
        if (d[x][y] == 0) {
            for (int j = 0; j < 4; j++) {
                int new_x = x + d_movement[j][0];
                int new_y = y + d_movement[j][1];
                if ((new_x != temp_x || new_y != temp_y) && d[new_x][new_y] != 0) {
                    bug = true;
                    break;
                }
            }
        } else {
            bug = true;
        }
        if (bug) {
            break;
        }
        d[x][y] = 1;
    }
    if (bug) {
        printf("BUG\n");
    } else {
        printf("OK\n");
    }
    return 0;
}
// End of Code
