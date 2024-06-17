// aarch64-linux-gnu-g++ -o timming_check ./timming_check.cpp

#include <stdio.h>
#include <time.h>
#include <stdint.h>

// 1초를 나노로 변환
#define NANOSECONDS_IN_SECOND 1000000000
#define NUM_TESTS 1000000

int main() {
    struct timespec start, end;
    uint64_t time_accumulated = 0;

    // 타이머 시작
    clock_gettime(CLOCK_MONOTONIC, &start);

    // 반복 연산 수행
    for (int i = 0; i < NUM_TESTS; i++) {
        __asm__("nop");
    }

    // 타이머 종료
    clock_gettime(CLOCK_MONOTONIC, &end);

    // 총 걸린 시간 계산 (단위: nanoseconds)
    time_accumulated = (end.tv_sec - start.tv_sec) * NANOSECONDS_IN_SECOND + (end.tv_nsec - start.tv_nsec);

    printf("Total time for %d operations: %lu nanoseconds\n", NUM_TESTS, time_accumulated);
    printf("Average time per operation: %lu nanoseconds\n", time_accumulated / NUM_TESTS);

    return 0;
}
