#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    long constraints[5];
    long N;
    long result;
} Main;

void calc(Main *main_instance) {
    long min = LONG_MAX;
    for (int i = 0; i < 5; ++i) {
        if (main_instance->constraints[i] < min) {
            min = main_instance->constraints[i];
        }
    }
    long time = main_instance->N / min;
    if (main_instance->N % min != 0) {
        ++time;
    }
    time += 4;
    main_instance->result = time;
}

int main() {
    Main main_instance;
    scanf("%ld", &(main_instance.N));
    for (int i = 0; i < 5; ++i) {
        scanf("%ld", &(main_instance.constraints[i]));
    }

    calc(&main_instance);
    printf("%ld\n", main_instance.result);

    return 0;
}

// 
