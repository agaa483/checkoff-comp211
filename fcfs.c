#include <stdio.h>

// Simulates First-Come, First-Served (FCFS) scheduling.
// Jobs run in the order given, and each job runs until it's done.
// A job's waiting time = the total burst time of every job ahead of it.
void run_fcfs(const char *label, int ids[], int bursts[], int n) {
    int wait = 0;   // running total of burst times so far
    int total = 0;  // sum of all waiting times

    printf("%s\n", label);
    for (int i = 0; i < n; i++) {
        printf("  P%d waits %d ms (burst %d ms)\n", ids[i], wait, bursts[i]);
        total += wait;
        wait += bursts[i];
    }
    printf("  Average wait = %.1f ms\n\n", (double) total / n);
}

int main(void) {
    // Same 3 jobs, two different arrival orders
    int short_first_ids[]    = {2, 3, 1};
    int short_first_bursts[] = {3, 3, 24};

    int long_first_ids[]     = {1, 2, 3};
    int long_first_bursts[]  = {24, 3, 3};

    run_fcfs("Short jobs first:", short_first_ids, short_first_bursts, 3);
    run_fcfs("Long job first:", long_first_ids, long_first_bursts, 3);

    return 0;
}
