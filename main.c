#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#define NTEST 1000000000

uint64_t getTime(void) {
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return ((uint64_t)(time.tv_sec)*1000000000 + (uint64_t)(time.tv_nsec));
}

void indef() {
    int i, n = 0;
    for (i = 0; i < NTEST; i++) {
        if (n % 11 == 0) n++;
        else n--;
    }
}

void def() {
    int i, n = 0;
    for (i = 0; i < NTEST; i++) {
        if (n % 1 == 0) n++;
        else n--;
    }
}

uint64_t indef_time() {
    uint64_t start, finish;
    start = getTime();
    indef();
    finish = getTime();
    return finish - start;
}

uint64_t def_time() {
    uint64_t  start, finish;
    start = getTime();
    def();
    finish = getTime();
    return finish - start;
}

int main() {
    uint64_t indef_t = indef_time();
    uint64_t def_t = def_time();
    printf("Indef time: %lu\n", indef_t);
    printf("Def time:   %lu\n", def_t);
    printf("Indef/ Def Time Ratio: %f\n", (float)indef_t / def_t);
    return 0;
}