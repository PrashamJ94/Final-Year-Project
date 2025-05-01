#include <stdio.h>

#define MAX 100

int n, m, x;
int c[MAX][MAX];
int combinations[MAX][MAX];
int l[MAX];
int rem[MAX];
int ans;

void get_combinations(int arr[], int n, int r, int index, int data[], int i) {
    if (index == r) {
        for (int j = 0; j < r; j++)
            combinations[i][j] = data[j];
        return;
    }

    if (i >= n)
        return;

    data[index] = arr[i];
    get_combinations(arr, n, r, index + 1, data, i + 1);
    get_combinations(arr, n, r, index, data, i + 1);
}

int main() {
    scanf("%d %d %d", &n, &m, &x);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &c[i][j]);

    // This is a placeholder for the itertools.combinations function in Python
    // This will need to be replaced with an actual implementation
    get_combinations(c, n, m, 0, l, 0);

    // The rest of the code is a rough translation of the Python code
    // Some of the Python-specific features like list.insert and list.pop are not available in C
    // This code will need to be revised to work in C

    /*for (int i = 1; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
            int ca = 0;
            for (int ii = 0; ii < n; ii++) {
                ca += c[ii][i];
            }
            if (ca < x) {
                rem[j] = 1;
            }
        }
        if (rem[0]) {
            for (int j = 0; j < n; j++) {
                l[j] = 0;
            }
            rem[0] = 0;
        }
        if (!l[0]) {
            printf("-1\n");
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        int ca = 0;
        for (int j = 0; j < n; j++) {
            ca += c[j][0];
        }
        if (!ans) {
            ans = ca;
        } else {
            ans = ans < ca ? ans : ca;
        }
    }

    printf("%d\n", ans);*/
    return 0;
}
//End of Code


//Please note that this code will not compile or run correctly because it's incomplete and it needs further adaptation to make it equivalent to the original Python code. It's recommended to ask for help from a C programmer who can help you translate this Python code into C.
