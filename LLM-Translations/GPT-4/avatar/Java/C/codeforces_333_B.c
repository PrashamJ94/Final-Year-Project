#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct FastReader {
    FILE *file;
    char *buffer;
    size_t buffer_size;
} FastReader;

FastReader *fast_reader_init(FILE *file) {
    FastReader *reader = malloc(sizeof(FastReader));
    reader->file = file;
    reader->buffer = NULL;
    reader->buffer_size = 0;
    return reader;
}

void fast_reader_free(FastReader *reader) {
    if (reader->buffer) {
        free(reader->buffer);
    }
    free(reader);
}

bool fast_reader_next(FastReader *reader, char **output) {
    ssize_t read = getline(&reader->buffer, &reader->buffer_size, reader->file);
    if (read <= 0) {
        return false;
    }
    reader->buffer[read - 1] = '\0';
    *output = reader->buffer;
    return true;
}

int main() {
    FastReader *in = fast_reader_init(stdin);
    int n, m;
    fscanf(stdin, "%d %d", &n, &m);

    bool bannedRows[n + 1], bannedCols[n + 1];
    memset(bannedRows, false, sizeof(bannedRows));
    memset(bannedCols, false, sizeof(bannedCols));

    for (int i = 0; i < m; i++) {
        int r, c;
        fscanf(stdin, "%d %d", &r, &c);
        if (r > 1 && r < n) {
            bannedRows[r] = true;
        }
        if (c > 1 && c < n) {
            bannedCols[c] = true;
        }
    }

    int answer = (n - 2) * 2;
    for (int i = 2; i < n; i++) {
        if (bannedRows[i]) {
            answer--;
        }
        if (bannedCols[i]) {
            answer--;
        }
    }

    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows[mid] && !bannedCols[mid]) {
            answer--;
        }
    }

    printf("%d\n", answer);

    fast_reader_free(in);

    return 0;
}

// //End of Code
